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
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL VARIABLES
 **********************/

extern lv_ui guider_ui;
extern int QUIT_FLAG;
extern float SCALE;
extern int WIFI_ENABLE;
extern int MUSIC_ENABLE;

int Main_digital_clock_1_min_value ;
int Main_digital_clock_1_hour_value;
int Main_digital_clock_1_sec_value ;
char Main_digital_clock_1_meridiem[] = "AM";


/**********************
 *  STATIC VARIABLES
 **********************/
lv_timer_t *main_time_update_timer;
/**********************
 *  STATIC FUNCTIONS
 **********************/

static void _time_update()
{
    time_t current_time;
    struct tm *tm_info;

    time(&current_time);
    tm_info = localtime(&current_time);

    Main_digital_clock_1_hour_value = tm_info->tm_hour;
    Main_digital_clock_1_min_value = tm_info->tm_min;
    Main_digital_clock_1_sec_value = tm_info->tm_sec;

    if(tm_info->tm_hour > 12)
    {
        tm_info->tm_hour -= 12;    
        Main_digital_clock_1_hour_value = tm_info->tm_hour;
        Main_digital_clock_1_min_value = tm_info->tm_min;
        Main_digital_clock_1_sec_value = tm_info->tm_sec;
        strcpy(Main_digital_clock_1_meridiem, "PM");
    }
    else
    { 
        Main_digital_clock_1_hour_value = tm_info->tm_hour;
        Main_digital_clock_1_min_value = tm_info->tm_min;
        Main_digital_clock_1_sec_value = tm_info->tm_sec;
        strcpy(Main_digital_clock_1_meridiem, "AM");
    }

    char day_str[8];
    char month_str[8];
    char year_str[8];

    tm_info->tm_year += 1900;
    tm_info->tm_mon += 1;

    if(tm_info->tm_mday < 10)
        sprintf(day_str,"0%d",tm_info->tm_mday);
    else
        sprintf(day_str,"%d",tm_info->tm_mday);
       
    if(tm_info->tm_mon < 10)
        sprintf(month_str,"0%d",tm_info->tm_mon);
    else
        sprintf(month_str,"%d",tm_info->tm_mon);
    
    sprintf(year_str,"%d",tm_info->tm_year);

	lv_label_set_text_fmt(guider_ui.Main_datetext_1, "%s/%s/%s",year_str,month_str,day_str);


    // printf("Year: %d\n", tm_info->tm_year);
    // printf("Month: %d\n", tm_info->tm_mon);
    // printf("Day: %d\n", tm_info->tm_mday);
    // printf("Hour: %d\n", tm_info->tm_hour);
    // printf("Minute: %d\n", tm_info->tm_min);
    // printf("Sec: %d\n", tm_info->tm_sec);
}

static void main_time_update_timer_cb(lv_timer_t * tmr)
{
    _time_update();
}

static int _check_input_device(char *device_path) {
    int fd = open(device_path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open device");
        return -1;
    }

    char name[256] = "Unknown";
    if (ioctl(fd, EVIOCGNAME(sizeof(name)), name) < 0) {
        perror("Failed to get device name");
    } else {
        //printf("Device %s is %s\n", device_path, name);
    }

    if (strstr(name, "TouchScreen") != NULL) {
        close(fd);
        return 0;
    }

    close(fd);
    return -1;
}

// 检查目录是否存在
int check_directory_exists(const char *path) {
    struct stat info;
    if (stat(path, &info) != 0) {
        return 0;
    } else if (info.st_mode & S_IFDIR) {
        return 1;
    } else {
        return 0;
    }
}

static int contains_mp3_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return 0;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            const char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL && strcmp(ext, ".mp3") == 0) {
                closedir(dp);
                return 1; 
            }
        }
    }

    closedir(dp);
    return 0;
}

/**********************
 *  GLOBAL FUNCTIONS
 **********************/
void custom_init()
{
    QUIT_FLAG = 0;
    SCALE = 1.0;
    /* Main */

    /* WIFI */
    WIFI_ENABLE = 0;

    /* Skeychpad */

    /* Music Player */
    MUSIC_ENABLE = 0;
    system("mpv 2>&1 >/dev/null");
    music_player_thread_init();

    /* GIF */

}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}

/* GUI */
void Main_OFF_btn_event_handler(lv_event_t *e)
{
    
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_RELEASED)
    {
        // release style
        // release obj

        sleep(1);
        QUIT_FLAG = 1;
    } 
}

void main_app_init()
{
    lv_obj_add_flag(guider_ui.Main_win_music, LV_OBJ_FLAG_HIDDEN);;
    _time_update();
}

void main_backend_init()
{ 
    main_time_update_timer = lv_timer_create(main_time_update_timer_cb, 5000, 0); 
    lv_timer_set_repeat_count(main_time_update_timer, -1); 
}

void main_backend_release()
{
    lv_timer_del(main_time_update_timer);
}

/* Get hardware information */
void luckfox_get_drm_info()
{
    int ret, flags;
    drmModeRes *resources;
    drmModeConnector *connector;
    int i,j;

    int drm_fd = open("/dev/dri/card0", O_RDWR | O_CLOEXEC);
    if(drm_fd < 0 )
    {
		perror("cannot open /dev/dri/card0 \n");
        exit(EXIT_FAILURE);
    } 

    resources = drmModeGetResources(drm_fd);
    if (resources == NULL) {
        perror("drmModeGetResources failed");
        close(drm_fd);
        exit(EXIT_FAILURE);

    }

    for (i = 0; i < resources->count_connectors; i++) {
        connector = drmModeGetConnector(drm_fd, resources->connectors[i]);
        if (connector == NULL) {
            continue;
        }

        if (connector->connection == DRM_MODE_CONNECTED && connector->count_modes > 0) {
            //printf("Connected display found: %d\n", connector->connector_id);
            for (j = 0; j < connector->count_modes; j++) {
                printf("Mode %d: %dx%d @ %dHz\n", j, connector->modes[j].hdisplay, connector->modes[j].vdisplay, connector->modes[j].vrefresh);
                if( j == 0 ){
                    // Just Support  Square screen
                    if(connector->modes[j].hdisplay == connector->modes[j].vdisplay ){
                        // 720 x 720: 1.5 ;480 x 480: 1.0
                        SCALE = (float)connector->modes[j].hdisplay / (float)HEIGHT;
                    }
                    else{
                        perror("This LCD model is not supported yet.\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
        drmModeFreeConnector(connector);
    }

    drmModeFreeResources(resources);
    close(drm_fd);

}

int luckfox_get_system_info()
{
    FILE *fp = popen("cat /etc/os-release | grep \"Ubuntu\"", "r");
    if (fp == NULL) {
        perror("popen failed");
    }

    char buffer[128];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        pclose(fp);
        WIFI_ENABLE = 0;
        MUSIC_ENABLE = 2;

        return 1;
    }

    pclose(fp);

    return 0;
};

void luckfox_get_wifi_enable_info()
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/device-tree/model", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "Luckfox Pico Ultra W") == 0) {
            WIFI_ENABLE = 1;
        } 
        else if (strcmp(buffer, "Luckfox Pico Ultra") == 0) {
            WIFI_ENABLE = 0;
        }
        else{
            perror("This Luckfox Pico model is not supported yet.\n");
            exit(EXIT_FAILURE);
        }            
    } else {
        perror("Error reading file");
        fclose(file);
    }

    fclose(file);
}

void luckfox_get_input_device_info(char ** ts_dev)
{
    const char *path = "/dev/input";
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_CHR) { 
            if (strncmp(entry->d_name, "event", 5) == 0) { 
                char device_path[256];
                snprintf(device_path, sizeof(device_path), "%s/%s", path, entry->d_name);
                if(!_check_input_device(device_path))
                {
                    *ts_dev = device_path;
                }
            }
        }
    }
    closedir(dp);
}

void luckfox_check_music_enable_info()
{
    if (check_directory_exists(MUSIC_DIR)) {
        if (contains_mp3_files(MUSIC_DIR)) {
            MUSIC_ENABLE = 1;
        } else {
            MUSIC_ENABLE = 0;
        }
    } else {
        MUSIC_ENABLE = 0;
    }
}

/* Compatible more LCD */
void luckfox_lv_obj_set_pos(lv_obj_t * obj, lv_coord_t x, lv_coord_t y)
{
    float scale_params = SCALE;
    lv_coord_t scale_x = (lv_coord_t)((float)x * scale_params );
    lv_coord_t scale_y = (lv_coord_t)((float)y * scale_params );
    
    lv_obj_set_pos(obj, scale_x, scale_y);
}

void luckfox_lv_obj_set_size(lv_obj_t * obj, lv_coord_t w, lv_coord_t h)
{
    float scale_params = SCALE;
    lv_coord_t scale_w = (lv_coord_t)((float)w * scale_params );
    lv_coord_t scale_h = (lv_coord_t)((float)h * scale_params );
    
    lv_obj_set_size(obj, scale_w, scale_h);
    
}

void luckfox_lv_obj_align(lv_obj_t * obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    float scale_params = SCALE;
    lv_coord_t scale_x = (lv_coord_t)((float)x_ofs * scale_params );
    lv_coord_t scale_y = (lv_coord_t)((float)y_ofs * scale_params );

    lv_obj_align(obj, align, scale_x, scale_y);
}

void luckfox_lv_obj_set_width(lv_obj_t * obj, lv_coord_t w)
{
    float scale_params = SCALE;
    lv_coord_t scale_w = (lv_coord_t)((float)w * scale_params );

    lv_obj_set_width(obj, scale_w);
}

void luckfox_lv_obj_set_style_text_font(struct _lv_obj_t * obj, const lv_font_t * value, lv_style_selector_t selector)
{
    float scale_parmas = SCALE;
    int font_size = value->line_height;
    int scale_size= (int)((float)font_size * SCALE);

    switch (scale_size) {
        // 480 * 480 
        case 12:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_12, selector);
            break;
        case 16:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_16, selector);
            break;
        case 20:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_20, selector);
            break;
        case 42:  
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_42, selector);
            break;
        // 720 *720 
        case 18:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_18, selector);
            break;
        case 24:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_24, selector);
            break;
        case 30:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_30, selector);
            break;
        case 63:
            lv_obj_set_style_text_font(obj, &lv_font_montserratMedium_63, selector);
            break;
    }
    
}


void luckfox_lv_style_set_text_font(lv_style_t * style, const lv_font_t * value)
{
    float scale_parmas = SCALE;
    int font_size = value->line_height;
    int scale_size= (int)((float)font_size * SCALE);

    switch (scale_size) {
        // 480 * 480 
        case 12:
            lv_style_set_text_font(style, &lv_font_montserratMedium_12);
            break;
        case 16:
            lv_style_set_text_font(style, &lv_font_montserratMedium_16);
            break;
        case 20:
            lv_style_set_text_font(style, &lv_font_montserratMedium_20);
            break;
        case 42:
            lv_style_set_text_font(style, &lv_font_montserratMedium_42);
            break;
        // 720 
        case 18:
            lv_style_set_text_font(style, &lv_font_montserratMedium_18);
            break;
        case 24:
            lv_style_set_text_font(style, &lv_font_montserratMedium_24);
            break;
        case 30:
            lv_style_set_text_font(style, &lv_font_montserratMedium_30);
            break;
        case 63:
            lv_style_set_text_font(style, &lv_font_montserratMedium_63);
            break;
    }
}