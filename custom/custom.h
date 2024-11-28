/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h>
#include <errno.h>
#include <linux/fcntl.h>
#include <linux/input.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h> //-std=c99  -std=gnu99
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/prctl.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <drm/drm.h>
#include <drm/drm_mode.h>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include <drm_fourcc.h>

#include <unistd.h>
#include <sys/mman.h>
#include <inttypes.h>
#include <linux/input.h>

#include "cJSON.h"
#include "gui_guider.h"


#define WIDTH   480 
#define HEIGHT  480

#define MUSIC_DIR "/music"

// LVGL System
void custom_init();
uint32_t custom_tick_get(void);

// Compatible API
void luckfox_lv_obj_set_pos(lv_obj_t * obj, lv_coord_t x, lv_coord_t y);
void luckfox_lv_obj_set_size(lv_obj_t * obj, lv_coord_t w, lv_coord_t h);
void luckfox_lv_obj_set_style_text_font(struct _lv_obj_t * obj, const lv_font_t * value, lv_style_selector_t selector);
void luckfox_lv_obj_align(lv_obj_t * obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
void luckfox_lv_obj_set_width(lv_obj_t * obj, lv_coord_t w);
void luckfox_lv_style_set_text_font(lv_style_t * style, const lv_font_t * value);

// Check info 
void luckfox_get_drm_info();
void luckfox_get_wifi_enable_info();
void luckfox_get_input_device_info();
void luckfox_check_music_enable_info();
int luckfox_get_system_info();

/* Sketchpad */
lv_obj_t * lv_sketchpad_create(lv_obj_t * parent);
void Sketchpad_color_cpicker_event_cb(lv_event_t * e);
void Sketchpad_clear_btn_event_cb(lv_event_t * e);

/* Music Player */
int music_scan_list(char* mp3_string);

void Music_player_list_roller_event_handler(lv_event_t *e);
void Music_player_next_btn_event_handler(lv_event_t *e);
void Music_player_pre_btn_event_handler(lv_event_t *e);
void Music_player_start_btn_event_handler(lv_event_t *e);
void Music_player_volume_slider_event_handler(lv_event_t *e);
void Music_player_progress_slider_event_handler(lv_event_t *e);
void Music_player_mode_btn_event_handler(lv_event_t *e);

int music_app_init();
int music_player_thread_init();

/* WIFI */
void WIFI_clear_btn_event_handler(lv_event_t *e);
void WIFI_load_btn_event_handler(lv_event_t *e);
void WIFI_scanning_btn_event_handler(lv_event_t *e);
void WIFI_wifi_list_event_handler(lv_event_t *e);

void wifi_app_init();
void wifi_backend_init();
void wifi_backend_release();

/* Main */
void Main_OFF_btn_event_handler(lv_event_t *e);

void main_app_init();
void main_backend_init();
void main_backend_release();

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
