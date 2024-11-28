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

#define MAX_FILENAME_LEN 256
#define MAX_CMD_LEN 256
#define MUSIC_DIR_PATH "/music"
/**********************
 *      TYPEDEFS
 **********************/
struct Music_Node {
    char filename[MAX_FILENAME_LEN];
    int id;
    struct Music_Node* prev;
    struct Music_Node* next;
};

/**********************
 *  STATIC VARIABLES
 **********************/
struct Music_Node *playing_music_node;  
struct Music_Node* head;

int32_t fd_mpv;
struct sigaction act;
pid_t pid;
struct sockaddr_un addr;
pthread_t monitor_thread;

int slider_pressed = 0;
/**********************
 *  GLOBAL VARIABLES
 **********************/
extern lv_ui guider_ui;
/**********************
 *  STATIC FUNCTIONS
 **********************/
static void sigaction_exit_handler(int sig) { exit(0); }

static void init_music_node_list(struct Music_Node** head) {
    *head = NULL;
}

static void insert_music_node(struct Music_Node** head, char* filename, int id) {
    struct Music_Node* newNode = (struct Music_Node*)malloc(sizeof(struct Music_Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->filename, filename);
    newNode->id = id;

    if (*head == NULL) {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        struct Music_Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

static void free_music_node_list(struct Music_Node* head) {
    if (head != NULL) {
        struct Music_Node* current = head->next;
        while (current != head) {
            struct Music_Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(head);
    }
}

static void _music_pause(int sta)
{
    char cmd[256];
    sprintf(cmd, "{ \"command\": [\"set_property\", \"pause\",%s] }\n", sta ? "true" : "false");
    //printf("%s\n", cmd);
    write(fd_mpv, cmd, strlen(cmd));
}

static void _music_set_pos(int music_id)
{
    int read_flag = 0;
    char cmd[256];
    sprintf(cmd, "{ \"command\": [\"set_property\", \"playlist-pos\", %d] }\n",music_id);
    //printf("%s\n", cmd);
    write(fd_mpv, cmd, strlen(cmd)); 
    // set name
    lv_label_set_text(guider_ui.Music_player_music_name, playing_music_node->filename);
}

static void _music_set_volume(int volume)
{
    char cmd[256];
    sprintf(cmd, "{ \"command\": [\"set_property\", \"volume\", %d] }\n",volume);
    //printf("%s\n", cmd);
    write(fd_mpv, cmd, strlen(cmd));        
}

static void _music_set_progress(int progress)
{
    char cmd[256];
    sprintf(cmd, "{ \"command\": [\"seek\", %d, \"absolute\"] }\n",progress);
    //printf("%s\n", cmd);
    write(fd_mpv, cmd, strlen(cmd));        
}

static void _music_set_mode(int mode)
{
    char cmd[256];
    sprintf(cmd, "{ \"command\": [\"set_property\", \"loop\",%s] }\n", mode ? "true" : "false");
    //printf("%s\n", cmd);
    write(fd_mpv, cmd, strlen(cmd)); 
}

void *get_music_playback_time(void *arg)
{
    pthread_detach(pthread_self());
    // get playback-time
    char cmd[] = "{\"command\": [\"observe_property\", 1,\"playback-time\"]}\n ";
 
    // get sum-time 
    char cmd1[] = "{\"command\": [\"observe_property\", 2,\"duration\"]}\n ";
    
    cJSON *root;
    cJSON *event;
    cJSON *cjson_obj;
    char buf[512];

    write(fd_mpv, cmd, strlen(cmd));
    write(fd_mpv, cmd1, strlen(cmd1));
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        if (read(fd_mpv, buf, sizeof(buf)) > 0)
        {
            // printf("%s len:%d", buf, strlen(buf));
            // Get one line data
			char *temp = strtok(buf, "\n"); 
            while (temp)
            {
                root = cJSON_Parse(temp);
                if (root != NULL)
                {
                    if (cJSON_HasObjectItem(root, "event"))
                    {
                        event = cJSON_GetObjectItem(root, "event");
                        if (event != NULL)
                        {
                            if (strcmp(event->valuestring, "property-change") == 0)
                            {
                                cjson_obj = cJSON_GetObjectItem(root, "data");
                                cJSON *id = cJSON_GetObjectItem(root, "id"); //可以用id,也可以用name
                                if ((id != NULL) && (cjson_obj != NULL))
                                {
                                    if (id->valueint == 1)
                                    {
                                        if(!slider_pressed)
                                            lv_slider_set_value(guider_ui.Music_player_progress_slider, (int)cjson_obj->valuedouble,LV_ANIM_OFF);
                                    }
                                    else if (id->valueint == 2) 
                                    {
                                        lv_slider_set_range(guider_ui.Music_player_progress_slider, 0, (int)cjson_obj->valuedouble);
                                    }
                                }
                            }
                        }
                    }
                }

                temp = strtok(NULL, "\n");
            }
        }
        usleep(10000);
    }
    pthread_exit(NULL);
}

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

int music_scan_list(char* mp3_string)
{
    DIR *dir;
    struct dirent *entry;
    int id_num = 0;
    int i;

    init_music_node_list(&head);
    dir = opendir(MUSIC_DIR_PATH); 

    // Read files from music dir
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // common file
            // check .mp3
            char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL && strcmp(ext, ".mp3") == 0) {
                // insert Music Node
                insert_music_node(&head, entry->d_name,id_num);
                id_num++;
                //add to mpv list            
                char cmd[256];
                sprintf(cmd, "{ \"command\": [\"loadfile\", \"/music/%s\",\"append\"] }\n",entry->d_name);
                //printf("%s\n", cmd);
                write(fd_mpv, cmd, strlen(cmd));
            }
        }
    }
    closedir(dir);
    
    // Create roller str
    mp3_string[0] = '\0';
    if (head != NULL) {
        struct Music_Node* current = head;
        playing_music_node = head;
        for(i = 0;i < id_num;i++) {
            if(i != 0)
                strcat(mp3_string,"\n");
            strcat(mp3_string, current->filename);
            //printf("%s\n", current->filename);
            current = current->next;
        }
    }

    return 0;
}

void Music_player_list_roller_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {   
        char buf[32];
        lv_roller_get_selected_str(obj,  buf, sizeof(buf));

        while(strcmp(playing_music_node->filename, buf))
        {
            playing_music_node = playing_music_node->next;    
        }

        _music_set_pos(playing_music_node->id);
    }
}

void Music_player_next_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (code == LV_EVENT_RELEASED)
    {
        playing_music_node = playing_music_node->next;
        lv_roller_set_selected(guider_ui.Music_player_roller_1,playing_music_node->id,LV_ANIM_OFF);
        // set play music    
        _music_set_pos(playing_music_node->id);
    }
}

void Music_player_pre_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (code == LV_EVENT_RELEASED)
    {   
        playing_music_node = playing_music_node->prev;
        lv_roller_set_selected(guider_ui.Music_player_roller_1,playing_music_node->id,LV_ANIM_OFF);
        // set play music
        _music_set_pos(playing_music_node->id);
    }
}

void Music_player_start_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_RELEASED)
    {
        lv_state_t btn_state = lv_obj_get_state(obj);
        if(btn_state &= LV_STATE_CHECKED)
        {
            // Music start
            _music_pause(0);
        }
        else
        {
            // Music stop
            _music_pause(1);
        } 
    }
}

void Music_player_volume_slider_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (code == LV_EVENT_RELEASED)
    {
        int volume = lv_slider_get_value(obj);
        _music_set_volume(volume);
    }
}

void Music_player_progress_slider_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (code == LV_EVENT_RELEASED)
    { 
        int progress = lv_slider_get_value(obj);
        _music_set_progress(progress);
        slider_pressed = 0;
    }
    else if(code == LV_EVENT_PRESSING)
    {
        slider_pressed = 1;
    }

}

void Music_player_mode_btn_event_handler(lv_event_t *e)
{ 
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (code == LV_EVENT_RELEASED)
    { 
        lv_state_t btn_state = lv_obj_get_state(obj);
        if(btn_state &= LV_STATE_CHECKED)
        {
            _music_set_mode(0);
        }
        else
        {
            _music_set_mode(1);
        } 
    }

}

int music_player_thread_init()
{
	pid = vfork();
	if (pid == 0) // child thread
	{  
        char cmd[256];
        prctl(PR_SET_PDEATHSIG, SIGKILL);
        execlp("mpv", "mpv", "--quiet", "--no-terminal", "--no-video", "--idle=yes", "--term-status-msg=", "--input-ipc-server=/tmp/mpvsocket", NULL);        
        return 0;
	}
	else if (pid > 0) // parent thread
	{

        sleep(1);
        close(0);

        act.sa_handler = sigaction_exit_handler;
        sigfillset(&act.sa_mask);
        act.sa_flags = SA_RESTART; /* don't fiddle with EINTR */
        sigaction(SIGUSR1, &act, NULL);
        addr.sun_family = AF_UNIX;
        strcpy(addr.sun_path, "/tmp/mpvsocket");
        
        fd_mpv = socket(AF_UNIX, SOCK_STREAM, 0);
        if (fd_mpv == -1)
        {   
            perror("Create socket failed\n");
            return -1;
        }
        sleep(0.1);
    	// socket connect
		if (connect(fd_mpv, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        {
            perror("Cannot connect to socket \n");
            return -1;
        }
		// Monitor thread
        if (pthread_create(&monitor_thread, NULL, get_music_playback_time, NULL) != 0)
        {
            perror("pthread create error!\n");
            return -1;
        }
        //printf("get music pos pthread create ok!\n");
    }
    else
    {
        perror("fork error:\n");
        return -1;
    }
}

int music_app_init()
{
    _music_set_pos(0);
    _music_pause(1);
    _music_set_volume(50);
    _music_set_mode(1);
}

int music_app_quit()
{
    _music_pause(1);
}