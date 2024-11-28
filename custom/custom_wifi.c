/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/
#define MAX_CONF_LEN 128
#define MAX_LINE_LEN 1024
#define MAX_NETWORKS 10
#define WPA_FILE_PATH "/etc/wpa_supplicant.conf"
/**********************
 *      TYPEDEFS
 **********************/
struct wifi_network {
    char ssid[MAX_CONF_LEN];
};
/**********************
 *  GLOBAL VARIABLES
 **********************/
extern lv_ui guider_ui;
/**********************
 *  STATIC VARIABLES
 **********************/
pthread_t wifi_status_update_thread;
lv_timer_t *wifi_update_timer;
/**********************
 *  STATIC FUNCTIONS
 **********************/
static void _wifi_conf_load(const char* ssid, const char* password)
{
    FILE *wpa_supplicant_pipe;
    char buffer[MAX_CONF_LEN];

    // hide img
    lv_obj_add_flag(guider_ui.WIFI_wifi_log_img,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.WIFI_loaded_wifi_label,LV_OBJ_FLAG_HIDDEN); 

    // open wpa_supplicant pipe
    wpa_supplicant_pipe = popen("wpa_cli", "w");
    if (wpa_supplicant_pipe == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    // set network ssid adn psk
    memset(buffer,0,MAX_CONF_LEN);
    snprintf(buffer, MAX_CONF_LEN, "set_network 0 ssid \"%s\"\n", ssid);
    fputs(buffer, wpa_supplicant_pipe);
    lv_label_set_text(guider_ui.WIFI_loaded_wifi_label,ssid);
    
    memset(buffer,0,MAX_CONF_LEN);
    snprintf(buffer, MAX_CONF_LEN, "set_network 0 psk \"%s\"\n", password);
    fputs(buffer, wpa_supplicant_pipe);

    // save wifi conf
    fputs("save_config\n", wpa_supplicant_pipe);
    pclose(wpa_supplicant_pipe);

    // save wifi conf to /etc/wpa_supplicant.conf
    FILE *file = fopen(WPA_FILE_PATH, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return ;
    }

    FILE *temp_file = fopen("temp_wpa_supplicant.conf", "w");
    if (temp_file == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(file);
        return ;
    }

    char line[MAX_LINE_LEN];
    int inside_network_block = 0;

    while (fgets(line, MAX_LINE_LEN, file)) {
        // Enter network={} block
        if (strstr(line, "network={")) {
            inside_network_block = 1;
            fputs(line, temp_file);
            continue;
        }
        // Exit network={} block
        if (strstr(line, "}")) {
            inside_network_block = 0;
        }
        // Inside network={} block
        if (inside_network_block) {
            if (strstr(line, "ssid=")) {
                memset(buffer,0,MAX_CONF_LEN);
                sprintf(buffer, "        ssid=\"%s\"\n",ssid);
                fputs(buffer, temp_file);
            }
            else if (strstr(line, "psk=")) {
                memset(buffer,0,MAX_CONF_LEN);
                sprintf(buffer, "        psk=\"%s\"\n",password);
                fputs(buffer, temp_file);
            }
            else {
                fputs(line, temp_file);
            }
        }
        else {
            fputs(line, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(WPA_FILE_PATH);    
    rename("temp_wpa_supplicant.conf", WPA_FILE_PATH);
    //printf("SSID and PSK replaced successfully.\n");

    // reconnect wifi
    system("wpa_cli reconfigure &");
    system("udhcpc -i wlan0 &");
    return ;
}

static void _wifi_conf_get(char* ssid, char* passwd)
{
    FILE *file = fopen(WPA_FILE_PATH, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return ;
    }

    char line[MAX_LINE_LEN];
    int inside_network_block = 0;

    while (fgets(line, MAX_LINE_LEN, file)) {
        // Enter network={} block
        if (strstr(line, "network={")) {
            inside_network_block = 1;
            continue;
        }
        // Exit network={} block
        if (strstr(line, "}")) {
            inside_network_block = 0;
        }
        // Inside network={} block
        if (inside_network_block) {
            if (strstr(line, "ssid=")) {
                sscanf(line, " ssid=\"%[^\"]\"", ssid);
            }
            if (strstr(line, "psk=")) {
                sscanf(line, " psk=\"%[^\"]\"", passwd);
            }
        }
    }
    fclose(file);

    return ;
}

static void _wifi_status_update()
{
    FILE *fp;
    char command[MAX_LINE_LEN];
    char result[MAX_LINE_LEN];
    strcpy(command, "wpa_cli status");
 
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        pclose(fp);
        return ;
    }


    while (fgets(result, sizeof(result)-1, fp) != NULL)
    {
        if (strstr(result, "wpa_state=COMPLETED"))
        {   
            // connected 
            if((guider_ui.WIFI_loading_spinner != NULL)
                &&(guider_ui.WIFI_wifi_log_img != NULL)
                &&(guider_ui.WIFI_loaded_wifi_label != NULL)  )
            {
                lv_obj_add_flag(guider_ui.WIFI_loading_spinner,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.WIFI_wifi_log_img,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.WIFI_loaded_wifi_label,LV_OBJ_FLAG_HIDDEN);

            }
            break;     
        }
        else if(strstr(result, "wpa_state=SCANNING"))
        { 
            // scanning
            if((guider_ui.WIFI_loading_spinner != NULL)
                &&(guider_ui.WIFI_wifi_log_img != NULL)
                &&(guider_ui.WIFI_loaded_wifi_label != NULL)  )
            {
                lv_obj_clear_flag(guider_ui.WIFI_loading_spinner,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.WIFI_wifi_log_img,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.WIFI_loaded_wifi_label,LV_OBJ_FLAG_HIDDEN);
            }
            break;     
        }
    }

    pclose(fp);

}

static int _wifi_scanning_ssid()
{
    struct wifi_network networks[MAX_LINE_LEN];
    int network_count = 0;

    char command[] = "wpa_cli -i wlan0 scan_results";
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        return -1;
    }

    char line[MAX_LINE_LEN];
    // Skip the first two lines as they contain header information
    fgets(line, MAX_LINE_LEN, fp);

    // Parse each line to extract the SSID
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        char *token = strtok(line, "\t ");
        int count = 0;
        while (token != NULL) {
            if (count == 4) {
                strncpy(networks[network_count].ssid, token, MAX_CONF_LEN);
                networks[network_count].ssid[MAX_CONF_LEN - 1] = '\0'; // Ensure null-termination
                if (strlen(networks[network_count].ssid) > 0) {
                    network_count++;
                }
                break;
            }
            token = strtok(NULL, "\t ");
            count++;
        }
        if (network_count >= MAX_NETWORKS)
            break;
    }

    // Create a string with SSIDs separated by '\n'
    char ssid_string[MAX_NETWORKS * (MAX_CONF_LEN + 1)]; // 1 additional character for '\n'
    ssid_string[0] = '\0'; // Ensure ssid_string is empty initially

    for (int i = 0; i < network_count; i++) {
        if(strcmp(networks[i].ssid,"\n") && strlen(networks[i].ssid) < 16 )
        {
            strcat(ssid_string, networks[i].ssid);
        }
    }

    
    // Print the SSID string
    printf("SSID String:\n%s", ssid_string); 
    if(ssid_string == NULL || *ssid_string == '\0')
    {
        if(guider_ui.WIFI_wifi_list != NULL)
        {
            lv_dropdown_set_options(guider_ui.WIFI_wifi_list, "scanning");
        }
    }
    else
	{
        if(guider_ui.WIFI_wifi_list != NULL)
        {
            strcat(ssid_string, "\n...");
            lv_dropdown_set_options(guider_ui.WIFI_wifi_list, ssid_string);
        }
    }

    pclose(fp);
    return 0;

}

static void wifi_update_timer_cb(lv_timer_t * tmr)
{
    _wifi_status_update();
}

/**********************
 *  GLOBAL FUNCTIONS
 **********************/
void WIFI_load_btn_event_handler(lv_event_t *e)
{ 
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_RELEASED)
    {
        const char *ssid = lv_textarea_get_text(guider_ui.WIFI_ssid_ta);
        const char *passwd = lv_textarea_get_text(guider_ui.WIFI_psw_ta);
        _wifi_conf_load(ssid, passwd);     
    }
}

void WIFI_clear_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_RELEASED)
    {
        lv_textarea_set_text(guider_ui.WIFI_ssid_ta,"");
        lv_textarea_set_text(guider_ui.WIFI_psw_ta,"");
    } 
}

void WIFI_scanning_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_RELEASED)
    {
        _wifi_scanning_ssid();
    } 
}

void WIFI_wifi_list_event_handler(lv_event_t *e)
{ 
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        char ssid[MAX_CONF_LEN];
        memset(ssid, 0, MAX_CONF_LEN);
        lv_dropdown_get_selected_str(guider_ui.WIFI_wifi_list, ssid, MAX_CONF_LEN);
        lv_textarea_set_text(guider_ui.WIFI_ssid_ta, ssid);
    } 
}

void wifi_app_init()
{
    char ssid[MAX_CONF_LEN];
    char passwd[MAX_CONF_LEN];

    memset(ssid, 0, MAX_CONF_LEN);
    memset(passwd, 0, MAX_CONF_LEN);
    _wifi_conf_get(ssid,passwd);


    lv_label_set_text(guider_ui.WIFI_loaded_wifi_label,ssid);
    lv_textarea_set_text(guider_ui.WIFI_ssid_ta, ssid);
    lv_textarea_set_text(guider_ui.WIFI_psw_ta, passwd);

    lv_obj_add_flag(guider_ui.WIFI_wifi_log_img,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.WIFI_loaded_wifi_label,LV_OBJ_FLAG_HIDDEN); 
}

void wifi_backend_init()
{
    wifi_update_timer = lv_timer_create(wifi_update_timer_cb, 5000, 0); 
    lv_timer_set_repeat_count(wifi_update_timer, -1); 
}

void wifi_backend_release()
{
    lv_timer_del(wifi_update_timer);
}