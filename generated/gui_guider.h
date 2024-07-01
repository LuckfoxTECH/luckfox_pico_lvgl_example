/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Main;
	bool Main_del;
	lv_obj_t *g_kb_Main;
	lv_obj_t *Main_img_1;
	lv_obj_t *Main_digital_clock_1;
	lv_obj_t *Main_datetext_1;
	lv_obj_t *Main_Wifi_btn;
	lv_obj_t *Main_Wifi_btn_label;
	lv_obj_t *Main_PAD_btn;
	lv_obj_t *Main_PAD_btn_label;
	lv_obj_t *Main_Music_btn;
	lv_obj_t *Main_Music_btn_label;
	lv_obj_t *Main_GIF_btn;
	lv_obj_t *Main_GIF_btn_label;
	lv_obj_t *Main_OFF;
	lv_obj_t *Main_OFF_label;
	lv_obj_t *Main_win_music;
	lv_obj_t *Main_win_music_item0;
	lv_obj_t *WIFI;
	bool WIFI_del;
	lv_obj_t *g_kb_WIFI;
	lv_obj_t *WIFI_loading_spinner;
	lv_obj_t *WIFI_ssid_ta;
	lv_obj_t *WIFI_psw_ta;
	lv_obj_t *WIFI_load_btn;
	lv_obj_t *WIFI_load_btn_label;
	lv_obj_t *WIFI_clear_btn;
	lv_obj_t *WIFI_clear_btn_label;
	lv_obj_t *WIFI_Scanning_btn;
	lv_obj_t *WIFI_Scanning_btn_label;
	lv_obj_t *WIFI_ssid_label;
	lv_obj_t *WIFI_psw_label;
	lv_obj_t *WIFI_back_btn;
	lv_obj_t *WIFI_back_btn_label;
	lv_obj_t *WIFI_loaded_wifi_label;
	lv_obj_t *WIFI_wifi_log_img;
	lv_obj_t *WIFI_wifi_list;
	lv_obj_t *Gif;
	bool Gif_del;
	lv_obj_t *g_kb_Gif;
	lv_obj_t *Gif_fox_gif;
	lv_obj_t *Sketchpad;
	bool Sketchpad_del;
	lv_obj_t *g_kb_Sketchpad;
	lv_obj_t *Sketchpad_color_cpicker;
	lv_obj_t *Sketchpad_clear_btn;
	lv_obj_t *Sketchpad_clear_btn_label;
	lv_obj_t *Sketchpad_back_btn;
	lv_obj_t *Sketchpad_back_btn_label;
	lv_obj_t *Music_player;
	bool Music_player_del;
	lv_obj_t *g_kb_Music_player;
	lv_obj_t *Music_player_img_3;
	lv_obj_t *Music_player_start_btn;
	lv_obj_t *Music_player_start_btn_label;
	lv_obj_t *Music_player_pre_btn;
	lv_obj_t *Music_player_pre_btn_label;
	lv_obj_t *Music_player_play_mode_btn;
	lv_obj_t *Music_player_play_mode_btn_label;
	lv_obj_t *Music_player_music_list_btn;
	lv_obj_t *Music_player_music_list_btn_label;
	lv_obj_t *Music_player_next_btn;
	lv_obj_t *Music_player_next_btn_label;
	lv_obj_t *Music_player_progress_slider;
	lv_obj_t *Music_player_volume_slider;
	lv_obj_t *Music_player_music_name;
	lv_obj_t *Music_player_img_1;
	lv_obj_t *Music_player_img_2;
	lv_obj_t *Music_player_back_btn;
	lv_obj_t *Music_player_back_btn_label;
	lv_obj_t *Music_player_cont_1;
	lv_obj_t *Music_player_roller_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_Main(lv_ui *ui);
void setup_scr_WIFI(lv_ui *ui);
void setup_scr_Gif(lv_ui *ui);
void setup_scr_Sketchpad(lv_ui *ui);
void setup_scr_Music_player(lv_ui *ui);
LV_IMG_DECLARE(_logo_alpha_100x100);
LV_IMG_DECLARE(_wifi_alpha_64x64);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(Gif_fox_giffox_0);
LV_IMG_DECLARE(Gif_fox_giffox_1);
LV_IMG_DECLARE(Gif_fox_giffox_2);
LV_IMG_DECLARE(Gif_fox_giffox_3);
LV_IMG_DECLARE(Gif_fox_giffox_4);
LV_IMG_DECLARE(Gif_fox_giffox_5);
LV_IMG_DECLARE(Gif_fox_giffox_6);
LV_IMG_DECLARE(Gif_fox_giffox_7);
LV_IMG_DECLARE(Gif_fox_giffox_8);
LV_IMG_DECLARE(Gif_fox_giffox_9);
LV_IMG_DECLARE(Gif_fox_giffox_10);
LV_IMG_DECLARE(Gif_fox_giffox_11);
LV_IMG_DECLARE(Gif_fox_giffox_12);
LV_IMG_DECLARE(Gif_fox_giffox_13);
LV_IMG_DECLARE(Gif_fox_giffox_14);
LV_IMG_DECLARE(Gif_fox_giffox_15);
LV_IMG_DECLARE(Gif_fox_giffox_16);
LV_IMG_DECLARE(Gif_fox_giffox_17);
LV_IMG_DECLARE(Gif_fox_giffox_18);
LV_IMG_DECLARE(Gif_fox_giffox_19);
LV_IMG_DECLARE(_wave_top_alpha_480x80);
LV_IMG_DECLARE(_btn_play_alpha_84x84);
LV_IMG_DECLARE(_btn_list_play_alpha_84x84);
LV_IMG_DECLARE(_btn_pause_alpha_84x84);
LV_IMG_DECLARE(_btn_pause_alpha_84x84);
LV_IMG_DECLARE(_btn_prev_alpha_64x64);
LV_IMG_DECLARE(_btn_prev_alpha_64x64);
LV_IMG_DECLARE(_btn_prev_alpha_64x64);
LV_IMG_DECLARE(_btn_prev_alpha_64x64);
LV_IMG_DECLARE(_btn_loop_alpha_32x32);
LV_IMG_DECLARE(_btn_loop_alpha_32x32);
LV_IMG_DECLARE(_btn_rnd_alpha_32x32);
LV_IMG_DECLARE(_btn_rnd_alpha_32x32);
LV_IMG_DECLARE(_icn_chart_alpha_32x32);
LV_IMG_DECLARE(_icn_chart_alpha_32x32);
LV_IMG_DECLARE(_icn_chart_alpha_32x32);
LV_IMG_DECLARE(_icn_chart_alpha_32x32);
LV_IMG_DECLARE(_btn_next_alpha_64x64);
LV_IMG_DECLARE(_btn_next_alpha_64x64);
LV_IMG_DECLARE(_btn_next_alpha_64x64);
LV_IMG_DECLARE(_btn_next_alpha_64x64);
LV_IMG_DECLARE(_cover_1_alpha_200x200);
LV_IMG_DECLARE(_volume_alpha_32x32);
LV_IMG_DECLARE(_back_alpha_64x64);
LV_IMG_DECLARE(_back_alpha_64x64);
LV_IMG_DECLARE(_back_alpha_64x64);
LV_IMG_DECLARE(_back_alpha_64x64);


// 480*480 
LV_FONT_DECLARE(lv_font_montserratMedium_42)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)

// 720*720
LV_FONT_DECLARE(lv_font_montserratMedium_63)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_24)
LV_FONT_DECLARE(lv_font_montserratMedium_18)

#ifdef __cplusplus
}
#endif
#endif
