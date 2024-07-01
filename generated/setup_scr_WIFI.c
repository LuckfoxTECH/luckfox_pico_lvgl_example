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



void setup_scr_WIFI(lv_ui *ui)
{	
	//Write codes WIFI
	ui->WIFI = lv_obj_create(NULL);
	ui->g_kb_WIFI = lv_keyboard_create(ui->WIFI);
	lv_obj_add_event_cb(ui->g_kb_WIFI, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_WIFI, LV_OBJ_FLAG_HIDDEN);
	luckfox_lv_obj_set_style_text_font(ui->g_kb_WIFI, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_size(ui->WIFI, 480, 480);
	lv_obj_set_scrollbar_mode(ui->WIFI, LV_SCROLLBAR_MODE_OFF);

	//Write style for WIFI, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_loading_spinner
	ui->WIFI_loading_spinner = lv_spinner_create(ui->WIFI, 1000, 50);
	luckfox_lv_obj_set_pos(ui->WIFI_loading_spinner, 29, 24);
	luckfox_lv_obj_set_size(ui->WIFI_loading_spinner, 77, 74);

	//Write style for WIFI_loading_spinner, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->WIFI_loading_spinner, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->WIFI_loading_spinner, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_loading_spinner, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_loading_spinner, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_loading_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->WIFI_loading_spinner, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->WIFI_loading_spinner, 81, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->WIFI_loading_spinner, lv_color_hex(0x393c41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_loading_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for WIFI_loading_spinner, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->WIFI_loading_spinner, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->WIFI_loading_spinner, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->WIFI_loading_spinner, lv_color_hex(0xff9600), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes WIFI_ssid_ta
	ui->WIFI_ssid_ta = lv_textarea_create(ui->WIFI);
	lv_textarea_set_text(ui->WIFI_ssid_ta, "Your_wifi_name");
	lv_textarea_set_placeholder_text(ui->WIFI_ssid_ta, "");
	lv_textarea_set_password_bullet(ui->WIFI_ssid_ta, "*");
	lv_textarea_set_password_mode(ui->WIFI_ssid_ta, false);
	lv_textarea_set_one_line(ui->WIFI_ssid_ta, true);
	lv_textarea_set_accepted_chars(ui->WIFI_ssid_ta, "");
	lv_textarea_set_max_length(ui->WIFI_ssid_ta, 32);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->WIFI_ssid_ta, ta_event_cb, LV_EVENT_ALL, ui->g_kb_WIFI);
	#endif
	luckfox_lv_obj_set_pos(ui->WIFI_ssid_ta, 150, 115);
	luckfox_lv_obj_set_size(ui->WIFI_ssid_ta, 310, 40);

	//Write style for WIFI_ssid_ta, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->WIFI_ssid_ta, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_ssid_ta, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_ssid_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->WIFI_ssid_ta, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_ssid_ta, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_ssid_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_ssid_ta, lv_color_hex(0x5a6173), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_ssid_ta, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_ssid_ta, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_ssid_ta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_ssid_ta, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_ssid_ta, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_ssid_ta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->WIFI_ssid_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_ssid_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_ssid_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_ssid_ta, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for WIFI_ssid_ta, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI_ssid_ta, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_ssid_ta, lv_color_hex(0x5a6173), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_ssid_ta, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_ssid_ta, 10, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes WIFI_psw_ta
	ui->WIFI_psw_ta = lv_textarea_create(ui->WIFI);
	lv_textarea_set_text(ui->WIFI_psw_ta, "");
	lv_textarea_set_placeholder_text(ui->WIFI_psw_ta, "");
	lv_textarea_set_password_bullet(ui->WIFI_psw_ta, "*");
	lv_textarea_set_password_mode(ui->WIFI_psw_ta, true);
	lv_textarea_set_one_line(ui->WIFI_psw_ta, true);
	lv_textarea_set_accepted_chars(ui->WIFI_psw_ta, "");
	lv_textarea_set_max_length(ui->WIFI_psw_ta, 32);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->WIFI_psw_ta, ta_event_cb, LV_EVENT_ALL, ui->g_kb_WIFI);
	#endif
	luckfox_lv_obj_set_pos(ui->WIFI_psw_ta, 150, 195);
	luckfox_lv_obj_set_size(ui->WIFI_psw_ta, 310, 40);

	//Write style for WIFI_psw_ta, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->WIFI_psw_ta, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_psw_ta, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_psw_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->WIFI_psw_ta, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_psw_ta, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_psw_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_psw_ta, lv_color_hex(0x5a6173), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_psw_ta, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_psw_ta, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_psw_ta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_psw_ta, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_psw_ta, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_psw_ta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->WIFI_psw_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_psw_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_psw_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_psw_ta, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for WIFI_psw_ta, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI_psw_ta, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_psw_ta, lv_color_hex(0x5a6173), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_psw_ta, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_psw_ta, 10, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes WIFI_load_btn
	ui->WIFI_load_btn = lv_btn_create(ui->WIFI);
	ui->WIFI_load_btn_label = lv_label_create(ui->WIFI_load_btn);
	lv_label_set_text(ui->WIFI_load_btn_label, "Load\n");
	lv_label_set_long_mode(ui->WIFI_load_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->WIFI_load_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->WIFI_load_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->WIFI_load_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->WIFI_load_btn, 130, 350);
	luckfox_lv_obj_set_size(ui->WIFI_load_btn, 100, 100);

	//Write style for WIFI_load_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI_load_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_load_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_load_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_load_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_load_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_load_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_load_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_load_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_load_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_load_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_load_btn, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_load_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_load_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_clear_btn
	ui->WIFI_clear_btn = lv_btn_create(ui->WIFI);
	ui->WIFI_clear_btn_label = lv_label_create(ui->WIFI_clear_btn);
	lv_label_set_text(ui->WIFI_clear_btn_label, "Clear\n");
	lv_label_set_long_mode(ui->WIFI_clear_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->WIFI_clear_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->WIFI_clear_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->WIFI_clear_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->WIFI_clear_btn, 250, 350);
	luckfox_lv_obj_set_size(ui->WIFI_clear_btn, 100, 100);

	//Write style for WIFI_clear_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI_clear_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_clear_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_clear_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_clear_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_clear_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_clear_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_clear_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_clear_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_clear_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_clear_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_clear_btn, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_clear_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_clear_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_ssid_label
	ui->WIFI_ssid_label = lv_label_create(ui->WIFI);
	lv_label_set_text(ui->WIFI_ssid_label, "SSID\n\n\n\n");
	lv_label_set_long_mode(ui->WIFI_ssid_label, LV_LABEL_LONG_CLIP);
	luckfox_lv_obj_set_pos(ui->WIFI_ssid_label, 15, 120);
	luckfox_lv_obj_set_size(ui->WIFI_ssid_label, 125, 25);

	//Write style for WIFI_ssid_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_ssid_label, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_ssid_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_ssid_label, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_ssid_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->WIFI_ssid_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_ssid_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_ssid_label, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_ssid_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_ssid_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_ssid_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_psw_label
	ui->WIFI_psw_label = lv_label_create(ui->WIFI);
	lv_label_set_text(ui->WIFI_psw_label, "PASSWD\n\n\n\n\n");
	lv_label_set_long_mode(ui->WIFI_psw_label, LV_LABEL_LONG_CLIP);
	luckfox_lv_obj_set_pos(ui->WIFI_psw_label, 15, 200);
	luckfox_lv_obj_set_size(ui->WIFI_psw_label, 125, 25);

	//Write style for WIFI_psw_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_psw_label, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_psw_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_psw_label, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_psw_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->WIFI_psw_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_psw_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_psw_label, 54, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_psw_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_psw_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_psw_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_back_btn
	ui->WIFI_back_btn = lv_btn_create(ui->WIFI);
	ui->WIFI_back_btn_label = lv_label_create(ui->WIFI_back_btn);
	lv_label_set_text(ui->WIFI_back_btn_label, "Back\n");
	lv_label_set_long_mode(ui->WIFI_back_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->WIFI_back_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->WIFI_back_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->WIFI_back_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->WIFI_back_btn, 360, 350);
	luckfox_lv_obj_set_size(ui->WIFI_back_btn, 100, 100);

	//Write style for WIFI_back_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI_back_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_back_btn, lv_color_hex(0x979798), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_back_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_back_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_back_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_back_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_back_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_back_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_back_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_back_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_back_btn, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_back_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_back_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_loaded_wifi_label
	ui->WIFI_loaded_wifi_label = lv_label_create(ui->WIFI);
	lv_label_set_text(ui->WIFI_loaded_wifi_label, "wifi");
	lv_label_set_long_mode(ui->WIFI_loaded_wifi_label, LV_LABEL_LONG_WRAP);
	luckfox_lv_obj_set_pos(ui->WIFI_loaded_wifi_label, 300, 80);
	luckfox_lv_obj_set_size(ui->WIFI_loaded_wifi_label, 200, 20);

	//Write style for WIFI_loaded_wifi_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_loaded_wifi_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_loaded_wifi_label, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_loaded_wifi_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->WIFI_loaded_wifi_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_loaded_wifi_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_loaded_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_wifi_log_img
	ui->WIFI_wifi_log_img = lv_img_create(ui->WIFI);
	lv_obj_add_flag(ui->WIFI_wifi_log_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->WIFI_wifi_log_img, &_wifi_alpha_64x64);
	lv_img_set_pivot(ui->WIFI_wifi_log_img, 50,50);
	lv_img_set_angle(ui->WIFI_wifi_log_img, 0);
	luckfox_lv_obj_set_pos(ui->WIFI_wifi_log_img, 375, 15);
	lv_obj_set_size(ui->WIFI_wifi_log_img, 64, 64);

	//Write style for WIFI_wifi_log_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->WIFI_wifi_log_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_wifi_list
	ui->WIFI_wifi_list = lv_dropdown_create(ui->WIFI);
	lv_dropdown_set_options(ui->WIFI_wifi_list, "");
	luckfox_lv_obj_set_pos(ui->WIFI_wifi_list, 150, 50);
	luckfox_lv_obj_set_size(ui->WIFI_wifi_list, 190, 30);

	//Write style for WIFI_wifi_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->WIFI_wifi_list, lv_color_hex(0x0e0d0d), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_wifi_list, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_wifi_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_wifi_list, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_wifi_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_wifi_list, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_wifi_list, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->WIFI_wifi_list, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->WIFI_wifi_list, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->WIFI_wifi_list, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_wifi_list, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->WIFI_wifi_list, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_wifi_list, lv_color_hex(0x5a6173), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_wifi_list, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_wifi_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_WIFI_wifi_list_extra_list_selected_checked
	static lv_style_t style_WIFI_wifi_list_extra_list_selected_checked;
	ui_init_style(&style_WIFI_wifi_list_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_WIFI_wifi_list_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_WIFI_wifi_list_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_WIFI_wifi_list_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_WIFI_wifi_list_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_WIFI_wifi_list_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_WIFI_wifi_list_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_WIFI_wifi_list_extra_list_selected_checked, lv_color_hex(0xff9600));
	lv_style_set_bg_grad_dir(&style_WIFI_wifi_list_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->WIFI_wifi_list), &style_WIFI_wifi_list_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_WIFI_wifi_list_extra_list_main_default
	static lv_style_t style_WIFI_wifi_list_extra_list_main_default;
	ui_init_style(&style_WIFI_wifi_list_extra_list_main_default);
	
	lv_style_set_max_height(&style_WIFI_wifi_list_extra_list_main_default, 90);
	lv_style_set_text_color(&style_WIFI_wifi_list_extra_list_main_default, lv_color_hex(0xffffff));
	luckfox_lv_style_set_text_font(&style_WIFI_wifi_list_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_WIFI_wifi_list_extra_list_main_default, 255);
	lv_style_set_border_width(&style_WIFI_wifi_list_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_WIFI_wifi_list_extra_list_main_default, 255);
	lv_style_set_border_color(&style_WIFI_wifi_list_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_WIFI_wifi_list_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_WIFI_wifi_list_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_WIFI_wifi_list_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_WIFI_wifi_list_extra_list_main_default, lv_color_hex(0x5a6173));
	lv_style_set_bg_grad_dir(&style_WIFI_wifi_list_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->WIFI_wifi_list), &style_WIFI_wifi_list_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_WIFI_wifi_list_extra_list_scrollbar_default
	static lv_style_t style_WIFI_wifi_list_extra_list_scrollbar_default;
	ui_init_style(&style_WIFI_wifi_list_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_WIFI_wifi_list_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_WIFI_wifi_list_extra_list_scrollbar_default, 100);
	lv_style_set_bg_color(&style_WIFI_wifi_list_extra_list_scrollbar_default, lv_color_hex(0xff9600));
	lv_style_set_bg_grad_dir(&style_WIFI_wifi_list_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->WIFI_wifi_list), &style_WIFI_wifi_list_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes WIFI_Scanning_btn
	ui->WIFI_Scanning_btn = lv_btn_create(ui->WIFI);
	ui->WIFI_Scanning_btn_label = lv_label_create(ui->WIFI_Scanning_btn);
	lv_label_set_text(ui->WIFI_Scanning_btn_label, "Scan\n");
	lv_label_set_long_mode(ui->WIFI_Scanning_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->WIFI_Scanning_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->WIFI_Scanning_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->WIFI_Scanning_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->WIFI_Scanning_btn, 15, 350);
	luckfox_lv_obj_set_size(ui->WIFI_Scanning_btn, 100, 100);

	//Write style for WIFI_Scanning_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->WIFI_Scanning_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->WIFI_Scanning_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->WIFI_Scanning_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->WIFI_Scanning_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->WIFI_Scanning_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->WIFI_Scanning_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->WIFI_Scanning_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->WIFI_Scanning_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->WIFI_Scanning_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->WIFI_Scanning_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->WIFI_Scanning_btn, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->WIFI_Scanning_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->WIFI_Scanning_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of WIFI.	
	lv_obj_add_event_cb(ui->WIFI_load_btn,  WIFI_load_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->WIFI_clear_btn, WIFI_clear_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->WIFI_Scanning_btn, WIFI_scanning_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->WIFI_wifi_list, WIFI_wifi_list_event_handler, LV_EVENT_ALL, ui);

	//Update current screen layout.
	lv_obj_update_layout(ui->WIFI);

	//Init events for screen.
	events_init_WIFI(ui);
    wifi_backend_init();
	wifi_app_init();

}
