/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


extern int WIFI_ENABLE;
extern int MUSIC_ENABLE;

void setup_scr_Main(lv_ui *ui)
{
	//Write codes Main
	ui->Main = lv_obj_create(NULL);
	ui->g_kb_Main = lv_keyboard_create(ui->Main);
	lv_obj_add_event_cb(ui->g_kb_Main, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_Main, LV_OBJ_FLAG_HIDDEN);
	luckfox_lv_obj_set_style_text_font(ui->g_kb_Main, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_size(ui->Main, 480, 480);
	lv_obj_set_scrollbar_mode(ui->Main, LV_SCROLLBAR_MODE_OFF);

	//Write style for Main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Main, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_img_1
	ui->Main_img_1 = lv_img_create(ui->Main);
	lv_obj_add_flag(ui->Main_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Main_img_1, &_logo_alpha_100x100);
	lv_img_set_pivot(ui->Main_img_1, 50,50);
	lv_img_set_angle(ui->Main_img_1, 0);
	luckfox_lv_obj_set_pos(ui->Main_img_1, 60, 118);
	lv_obj_set_size(ui->Main_img_1, 100, 100);

	//Write style for Main_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Main_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_digital_clock_1
	static bool Main_digital_clock_1_timer_enabled = false;
	ui->Main_digital_clock_1 = lv_dclock_create(ui->Main, "00:00 AM");
	if (!Main_digital_clock_1_timer_enabled) {
		lv_timer_create(Main_digital_clock_1_timer, 1000, NULL);
		Main_digital_clock_1_timer_enabled = true;
	}
	luckfox_lv_obj_set_pos(ui->Main_digital_clock_1, 220, 115);
	luckfox_lv_obj_set_size(ui->Main_digital_clock_1, 210, 50);

	//Write style for Main_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Main_digital_clock_1, lv_color_hex(0x030303), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_digital_clock_1, &lv_font_montserratMedium_42, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Main_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_datetext_1
	ui->Main_datetext_1 = lv_label_create(ui->Main);
	lv_label_set_text(ui->Main_datetext_1, "2023/07/31");
	lv_obj_set_style_text_align(ui->Main_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_flag(ui->Main_datetext_1, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(ui->Main_datetext_1, Main_datetext_1_event_handler, LV_EVENT_ALL, NULL);
	luckfox_lv_obj_set_pos(ui->Main_datetext_1, 300, 180);
	luckfox_lv_obj_set_size(ui->Main_datetext_1, 115, 30);

	//Write style for Main_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Main_datetext_1, lv_color_hex(0x5a5959), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Main_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Main_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Main_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Main_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Main_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Main_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Main_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	
	//Write codes Main_Wifi_btn
	ui->Main_Wifi_btn = lv_btn_create(ui->Main);
	ui->Main_Wifi_btn_label = lv_label_create(ui->Main_Wifi_btn);
	lv_label_set_text(ui->Main_Wifi_btn_label, "WIFI");
	lv_label_set_long_mode(ui->Main_Wifi_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Main_Wifi_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Main_Wifi_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Main_Wifi_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Main_Wifi_btn, 5, 370);
	luckfox_lv_obj_set_size(ui->Main_Wifi_btn, 90, 80);

	//Write style for Main_Wifi_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main_Wifi_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Main_Wifi_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Main_Wifi_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Main_Wifi_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Main_Wifi_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Main_Wifi_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Main_Wifi_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Main_Wifi_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_Wifi_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Main_Wifi_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_Wifi_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_Wifi_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_Wifi_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_PAD_btn
	ui->Main_PAD_btn = lv_btn_create(ui->Main);
	ui->Main_PAD_btn_label = lv_label_create(ui->Main_PAD_btn);
	lv_label_set_text(ui->Main_PAD_btn_label, "PAD");
	lv_label_set_long_mode(ui->Main_PAD_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Main_PAD_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Main_PAD_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Main_PAD_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Main_PAD_btn, 100, 370);
	luckfox_lv_obj_set_size(ui->Main_PAD_btn, 90, 80);

	//Write style for Main_PAD_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main_PAD_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Main_PAD_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Main_PAD_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Main_PAD_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Main_PAD_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Main_PAD_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Main_PAD_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Main_PAD_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_PAD_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Main_PAD_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_PAD_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_PAD_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_PAD_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_Music_btn
	ui->Main_Music_btn = lv_btn_create(ui->Main);
	ui->Main_Music_btn_label = lv_label_create(ui->Main_Music_btn);
	lv_label_set_text(ui->Main_Music_btn_label, "MUSIC");
	lv_label_set_long_mode(ui->Main_Music_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Main_Music_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Main_Music_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Main_Music_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Main_Music_btn, 195, 370);
	luckfox_lv_obj_set_size(ui->Main_Music_btn, 90, 80);

	//Write style for Main_Music_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main_Music_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Main_Music_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Main_Music_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Main_Music_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Main_Music_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Main_Music_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Main_Music_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Main_Music_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_Music_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Main_Music_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_Music_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_Music_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_Music_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_GIF_btn
	ui->Main_GIF_btn = lv_btn_create(ui->Main);
	ui->Main_GIF_btn_label = lv_label_create(ui->Main_GIF_btn);
	lv_label_set_text(ui->Main_GIF_btn_label, "GIF");
	lv_label_set_long_mode(ui->Main_GIF_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Main_GIF_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Main_GIF_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Main_GIF_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Main_GIF_btn, 290, 370);
	luckfox_lv_obj_set_size(ui->Main_GIF_btn, 90, 80);

	//Write style for Main_GIF_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main_GIF_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Main_GIF_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Main_GIF_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Main_GIF_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Main_GIF_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Main_GIF_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Main_GIF_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Main_GIF_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_GIF_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Main_GIF_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_GIF_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_GIF_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_GIF_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_OFF
	ui->Main_OFF = lv_btn_create(ui->Main);
	ui->Main_OFF_label = lv_label_create(ui->Main_OFF);
	lv_label_set_text(ui->Main_OFF_label, "OFF");
	lv_label_set_long_mode(ui->Main_OFF_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Main_OFF_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Main_OFF, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Main_OFF_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Main_OFF, 385, 370);
	luckfox_lv_obj_set_size(ui->Main_OFF, 90, 80);

	//Write style for Main_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Main_OFF, lv_color_hex(0xb5a58d), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Main_OFF, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Main_OFF, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Main_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Main_OFF, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Main_OFF, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Main_OFF, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Main_OFF, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Main_OFF, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Main_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Main_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Main_win_music
	ui->Main_win_music = lv_win_create(ui->Main, 46);
	lv_obj_t * Main_win_music_title = lv_win_add_title(ui->Main_win_music, "");
	ui->Main_win_music_item0 = lv_win_add_btn(ui->Main_win_music, LV_SYMBOL_CLOSE, 40);
	lv_obj_t *Main_win_music_label = lv_label_create(lv_win_get_content(ui->Main_win_music));
	lv_obj_set_scrollbar_mode(lv_win_get_content(ui->Main_win_music), LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(Main_win_music_label, "Can't find music!");
	luckfox_lv_obj_align(ui->Main_win_music, LV_ALIGN_CENTER, 0, 0);
	luckfox_lv_obj_set_size(ui->Main_win_music, 400, 200);
	lv_obj_set_scrollbar_mode(ui->Main_win_music, LV_SCROLLBAR_MODE_OFF);

	//Write style for Main_win_music, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Main_win_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Main_win_music, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_opa(ui->Main_win_music, 90, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_color(ui->Main_win_music, lv_color_hex(0x081A0F), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Main_win_music, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->Main_win_music, lv_color_hex(0xc1c6cb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->Main_win_music, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->Main_win_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->Main_win_music, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->Main_win_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Main_win_music_extra_content_main_default
	static lv_style_t style_Main_win_music_extra_content_main_default;
	ui_init_style(&style_Main_win_music_extra_content_main_default);
	
	lv_style_set_bg_opa(&style_Main_win_music_extra_content_main_default, 255);
	lv_style_set_bg_color(&style_Main_win_music_extra_content_main_default, lv_color_hex(0xeeeeee));
	lv_style_set_bg_grad_dir(&style_Main_win_music_extra_content_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_text_color(&style_Main_win_music_extra_content_main_default, lv_color_hex(0x000000));
	lv_style_set_text_font(&style_Main_win_music_extra_content_main_default, &lv_font_montserratMedium_24);
	lv_style_set_text_opa(&style_Main_win_music_extra_content_main_default, 255);
	lv_style_set_text_letter_space(&style_Main_win_music_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_Main_win_music_extra_content_main_default, 2);
	lv_obj_add_style(lv_win_get_content(ui->Main_win_music), &style_Main_win_music_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Main_win_music_extra_header_main_default
	static lv_style_t style_Main_win_music_extra_header_main_default;
	ui_init_style(&style_Main_win_music_extra_header_main_default);
	
	lv_style_set_bg_opa(&style_Main_win_music_extra_header_main_default, 255);
	lv_style_set_bg_color(&style_Main_win_music_extra_header_main_default, lv_color_hex(0xff9600));
	lv_style_set_bg_grad_dir(&style_Main_win_music_extra_header_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_text_color(&style_Main_win_music_extra_header_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_Main_win_music_extra_header_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_Main_win_music_extra_header_main_default, 255);
	lv_style_set_text_letter_space(&style_Main_win_music_extra_header_main_default, 0);
	lv_style_set_text_line_space(&style_Main_win_music_extra_header_main_default, 2);
	lv_obj_add_style(lv_win_get_header(ui->Main_win_music), &style_Main_win_music_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Main_win_music_extra_btns_main_default
	static lv_style_t style_Main_win_music_extra_btns_main_default;
	ui_init_style(&style_Main_win_music_extra_btns_main_default);
	
	lv_style_set_radius(&style_Main_win_music_extra_btns_main_default, 0);
	lv_style_set_border_width(&style_Main_win_music_extra_btns_main_default, 0);
	lv_style_set_bg_opa(&style_Main_win_music_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_Main_win_music_extra_btns_main_default, lv_color_hex(0xB5A58D));
	lv_style_set_bg_grad_dir(&style_Main_win_music_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_shadow_width(&style_Main_win_music_extra_btns_main_default, 0);
	lv_obj_add_style(ui->Main_win_music_item0, &style_Main_win_music_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//The custom code of Main.	
	lv_obj_add_event_cb(ui->Main_OFF, Main_OFF_btn_event_handler, LV_EVENT_ALL, ui);

	//Update current screen layout.
	lv_obj_update_layout(ui->Main);

	//Init events for screen.
	events_init_Main(ui);
    
	if (WIFI_ENABLE == 0)
	{
		luckfox_lv_obj_set_pos(ui->Main_PAD_btn, 50, 370);
		luckfox_lv_obj_set_pos(ui->Main_Music_btn, 145, 370);
		luckfox_lv_obj_set_pos(ui->Main_GIF_btn, 240, 370);
		luckfox_lv_obj_set_pos(ui->Main_OFF, 335, 370);
	
		lv_obj_add_flag(ui->Main_Wifi_btn, LV_OBJ_FLAG_HIDDEN);
	}

	if((MUSIC_ENABLE == 2) && (WIFI_ENABLE == 0))
	{
		luckfox_lv_obj_set_pos(ui->Main_PAD_btn, 50, 370);
		luckfox_lv_obj_set_pos(ui->Main_GIF_btn, 190, 370);
		luckfox_lv_obj_set_pos(ui->Main_OFF, 335, 370);
	
		lv_obj_add_flag(ui->Main_Music_btn, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui->Main_Wifi_btn, LV_OBJ_FLAG_HIDDEN);
	}

	main_backend_init();
	main_app_init();
	
}
