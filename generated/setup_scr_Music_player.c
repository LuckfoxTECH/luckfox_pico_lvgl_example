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

void setup_scr_Music_player(lv_ui *ui)
{
	//Write codes Music_player
	ui->Music_player = lv_obj_create(NULL);
	ui->g_kb_Music_player = lv_keyboard_create(ui->Music_player);
	lv_obj_add_event_cb(ui->g_kb_Music_player, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_Music_player, LV_OBJ_FLAG_HIDDEN);
	luckfox_lv_obj_set_style_text_font(ui->g_kb_Music_player, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_size(ui->Music_player, 480, 480);
	lv_obj_set_scrollbar_mode(ui->Music_player, LV_SCROLLBAR_MODE_OFF);

	//Write style for Music_player, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Music_player_img_3
	ui->Music_player_img_3 = lv_img_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Music_player_img_3, &_wave_top_alpha_480x80);
	lv_img_set_pivot(ui->Music_player_img_3, 50,50);
	lv_img_set_angle(ui->Music_player_img_3, 0);
	luckfox_lv_obj_set_pos(ui->Music_player_img_3, 0, 0);
	luckfox_lv_obj_set_width(ui->Music_player_img_3, WIDTH);
	lv_obj_set_height(ui->Music_player_img_3, 80);

	//Write style for Music_player_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Music_player_img_3, 137, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Music_player_start_btn
	ui->Music_player_start_btn = lv_imgbtn_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_start_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->Music_player_start_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_play_alpha_84x84, NULL);
	lv_imgbtn_set_src(ui->Music_player_start_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_btn_list_play_alpha_84x84, NULL);
	lv_imgbtn_set_src(ui->Music_player_start_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn_pause_alpha_84x84, NULL);
	lv_imgbtn_set_src(ui->Music_player_start_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn_pause_alpha_84x84, NULL);
	ui->Music_player_start_btn_label = lv_label_create(ui->Music_player_start_btn);
	lv_label_set_text(ui->Music_player_start_btn_label, "");
	lv_label_set_long_mode(ui->Music_player_start_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Music_player_start_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Music_player_start_btn, 0, LV_STATE_DEFAULT);
	luckfox_lv_obj_set_pos(ui->Music_player_start_btn, 198, 332);
	lv_obj_set_size(ui->Music_player_start_btn, 84, 84);
	lv_obj_add_flag(ui->Music_player_start_btn, LV_OBJ_FLAG_CLICKABLE);

	//Write style for Music_player_start_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Music_player_start_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_start_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_start_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_start_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_start_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_start_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->Music_player_start_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Music_player_start_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_start_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Music_player_start_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Music_player_start_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for Music_player_start_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->Music_player_start_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->Music_player_start_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_start_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->Music_player_start_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->Music_player_start_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for Music_player_start_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->Music_player_start_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes Music_player_pre_btn
	ui->Music_player_pre_btn = lv_imgbtn_create(ui->Music_player);
	lv_imgbtn_set_src(ui->Music_player_pre_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_prev_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_pre_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_btn_prev_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_pre_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn_prev_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_pre_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn_prev_alpha_64x64, NULL);
	ui->Music_player_pre_btn_label = lv_label_create(ui->Music_player_pre_btn);
	lv_label_set_text(ui->Music_player_pre_btn_label, "");
	lv_label_set_long_mode(ui->Music_player_pre_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Music_player_pre_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Music_player_pre_btn, 0, LV_STATE_DEFAULT);
	luckfox_lv_obj_set_pos(ui->Music_player_pre_btn, 76, 342);
	lv_obj_set_size(ui->Music_player_pre_btn, 64, 64);

	//Write style for Music_player_pre_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Music_player_pre_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_pre_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_pre_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_pre_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_pre_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_pre_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->Music_player_pre_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Music_player_pre_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_pre_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Music_player_pre_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Music_player_pre_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for Music_player_pre_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->Music_player_pre_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->Music_player_pre_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_pre_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->Music_player_pre_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->Music_player_pre_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for Music_player_pre_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->Music_player_pre_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes Music_player_play_mode_btn
	ui->Music_player_play_mode_btn = lv_imgbtn_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_play_mode_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->Music_player_play_mode_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_loop_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Music_player_play_mode_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_btn_loop_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Music_player_play_mode_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn_rnd_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Music_player_play_mode_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn_rnd_alpha_32x32, NULL);
	ui->Music_player_play_mode_btn_label = lv_label_create(ui->Music_player_play_mode_btn);
	lv_label_set_text(ui->Music_player_play_mode_btn_label, "");
	lv_label_set_long_mode(ui->Music_player_play_mode_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Music_player_play_mode_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Music_player_play_mode_btn, 0, LV_STATE_DEFAULT);
	luckfox_lv_obj_set_pos(ui->Music_player_play_mode_btn, 76, 310);
	lv_obj_set_size(ui->Music_player_play_mode_btn, 32, 32);

	//Write style for Music_player_play_mode_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Music_player_play_mode_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_play_mode_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_play_mode_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_play_mode_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_play_mode_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_play_mode_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->Music_player_play_mode_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Music_player_play_mode_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_play_mode_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Music_player_play_mode_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Music_player_play_mode_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for Music_player_play_mode_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->Music_player_play_mode_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->Music_player_play_mode_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_play_mode_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->Music_player_play_mode_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->Music_player_play_mode_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for Music_player_play_mode_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->Music_player_play_mode_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes Music_player_music_list_btn
	ui->Music_player_music_list_btn = lv_imgbtn_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_music_list_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->Music_player_music_list_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_icn_chart_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Music_player_music_list_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_icn_chart_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Music_player_music_list_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_icn_chart_alpha_32x32, NULL);
	lv_imgbtn_set_src(ui->Music_player_music_list_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_icn_chart_alpha_32x32, NULL);
	ui->Music_player_music_list_btn_label = lv_label_create(ui->Music_player_music_list_btn);
	lv_label_set_text(ui->Music_player_music_list_btn_label, "");
	lv_label_set_long_mode(ui->Music_player_music_list_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Music_player_music_list_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Music_player_music_list_btn, 0, LV_STATE_DEFAULT);
	luckfox_lv_obj_set_pos(ui->Music_player_music_list_btn, 139, 310);
	lv_obj_set_size(ui->Music_player_music_list_btn, 32, 32);

	//Write style for Music_player_music_list_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Music_player_music_list_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_music_list_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_music_list_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_music_list_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_music_list_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_music_list_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->Music_player_music_list_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Music_player_music_list_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_music_list_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Music_player_music_list_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Music_player_music_list_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for Music_player_music_list_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->Music_player_music_list_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->Music_player_music_list_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_music_list_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->Music_player_music_list_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->Music_player_music_list_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for Music_player_music_list_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->Music_player_music_list_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes Music_player_next_btn
	ui->Music_player_next_btn = lv_imgbtn_create(ui->Music_player);
	lv_imgbtn_set_src(ui->Music_player_next_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_next_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_next_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_btn_next_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_next_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn_next_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_next_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn_next_alpha_64x64, NULL);
	ui->Music_player_next_btn_label = lv_label_create(ui->Music_player_next_btn);
	lv_label_set_text(ui->Music_player_next_btn_label, "");
	lv_label_set_long_mode(ui->Music_player_next_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Music_player_next_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Music_player_next_btn, 0, LV_STATE_DEFAULT);
	luckfox_lv_obj_set_pos(ui->Music_player_next_btn, 340, 342);
	lv_obj_set_size(ui->Music_player_next_btn, 64, 64);

	//Write style for Music_player_next_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Music_player_next_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_next_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_next_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_next_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_next_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_next_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->Music_player_next_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Music_player_next_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_next_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Music_player_next_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Music_player_next_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for Music_player_next_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->Music_player_next_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->Music_player_next_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_next_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->Music_player_next_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->Music_player_next_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for Music_player_next_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->Music_player_next_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes Music_player_progress_slider
	ui->Music_player_progress_slider = lv_slider_create(ui->Music_player);
	lv_slider_set_range(ui->Music_player_progress_slider, 0, 100);
	lv_slider_set_mode(ui->Music_player_progress_slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Music_player_progress_slider, 50, LV_ANIM_OFF);
	luckfox_lv_obj_set_pos(ui->Music_player_progress_slider, 76, 417);
	luckfox_lv_obj_set_size(ui->Music_player_progress_slider, 328, 11);

	//Write style for Music_player_progress_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_progress_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_progress_slider, lv_color_hex(0x996ff2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_dither_mode(ui->Music_player_progress_slider, LV_DITHER_ORDERED, LV_PART_MAIN|LV_STATE_DEFAULT);
	//lv_obj_set_style_bg_grad_dir(ui->Music_player_progress_slider, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	//lv_obj_set_style_bg_grad_color(ui->Music_player_progress_slider, lv_color_hex(0x996ff2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->Music_player_progress_slider, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->Music_player_progress_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_progress_slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Music_player_progress_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_progress_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_progress_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_progress_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_progress_slider, lv_color_hex(0x5694f8), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_progress_slider, LV_GRAD_DIR_HOR, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->Music_player_progress_slider, lv_color_hex(0x5281cb), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->Music_player_progress_slider, 53, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->Music_player_progress_slider, 184, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_progress_slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Music_player_progress_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_progress_slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_progress_slider, lv_color_hex(0x42749d), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_progress_slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_progress_slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Music_player_volume_slider
	ui->Music_player_volume_slider = lv_slider_create(ui->Music_player);
	lv_slider_set_range(ui->Music_player_volume_slider, 0, 100);
	lv_slider_set_mode(ui->Music_player_volume_slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Music_player_volume_slider, 50, LV_ANIM_OFF);
	luckfox_lv_obj_set_pos(ui->Music_player_volume_slider, 244, 324);
	luckfox_lv_obj_set_size(ui->Music_player_volume_slider, 160, 8);

	//Write style for Music_player_volume_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_volume_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_volume_slider, lv_color_hex(0x99a08e), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_volume_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_volume_slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Music_player_volume_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_volume_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_volume_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_volume_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_volume_slider, lv_color_hex(0x528d94), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_volume_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_volume_slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Music_player_volume_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_volume_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_volume_slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Music_player_music_name
	ui->Music_player_music_name = lv_label_create(ui->Music_player);
	lv_label_set_text(ui->Music_player_music_name, "music.mp3\n");
	lv_label_set_long_mode(ui->Music_player_music_name, LV_LABEL_LONG_WRAP);
	luckfox_lv_obj_set_pos(ui->Music_player_music_name, 140, 68);
	luckfox_lv_obj_set_size(ui->Music_player_music_name, 200, 22);

	//Write style for Music_player_music_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Music_player_music_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_music_name, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_music_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Music_player_music_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Music_player_music_name, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_music_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_music_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Music_player_img_1
	ui->Music_player_img_1 = lv_img_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Music_player_img_1, &_cover_1_alpha_200x200);
	lv_img_set_pivot(ui->Music_player_img_1, 50,50);
	lv_img_set_angle(ui->Music_player_img_1, 0);
	luckfox_lv_obj_align(ui->Music_player_img_1, LV_ALIGN_CENTER, 0, -40);
	lv_obj_set_size(ui->Music_player_img_1, 200, 200);

	//Write style for Music_player_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Music_player_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Music_player_img_2
	ui->Music_player_img_2 = lv_img_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Music_player_img_2, &_volume_alpha_32x32);
	lv_img_set_pivot(ui->Music_player_img_2, 50,50);
	lv_img_set_angle(ui->Music_player_img_2, 0);
	luckfox_lv_obj_set_pos(ui->Music_player_img_2, 202, 310);
	lv_obj_set_size(ui->Music_player_img_2, 32, 32);

	//Write style for Music_player_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Music_player_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Music_player_back_btn
	ui->Music_player_back_btn = lv_imgbtn_create(ui->Music_player);
	lv_obj_add_flag(ui->Music_player_back_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->Music_player_back_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_back_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_back_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_back_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_back_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_back_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->Music_player_back_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_back_alpha_64x64, NULL);
	ui->Music_player_back_btn_label = lv_label_create(ui->Music_player_back_btn);
	lv_label_set_text(ui->Music_player_back_btn_label, "");
	lv_label_set_long_mode(ui->Music_player_back_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Music_player_back_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Music_player_back_btn, 0, LV_STATE_DEFAULT);
	luckfox_lv_obj_set_pos(ui->Music_player_back_btn, 0, 0);
	lv_obj_set_size(ui->Music_player_back_btn, 64, 64);

	//Write style for Music_player_back_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Music_player_back_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_back_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_back_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_back_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_back_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_back_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->Music_player_back_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Music_player_back_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_back_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Music_player_back_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Music_player_back_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for Music_player_back_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->Music_player_back_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->Music_player_back_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_back_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->Music_player_back_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->Music_player_back_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for Music_player_back_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->Music_player_back_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes Music_player_cont_1
	ui->Music_player_cont_1 = lv_obj_create(ui->Music_player);
	luckfox_lv_obj_set_pos(ui->Music_player_cont_1, -1.5, 92);
	luckfox_lv_obj_set_size(ui->Music_player_cont_1, 313, 221);
	lv_obj_set_scrollbar_mode(ui->Music_player_cont_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->Music_player_cont_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->Music_player_cont_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for Music_player_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Music_player_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Music_player_cont_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Music_player_cont_1, 195, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_cont_1, lv_color_hex(0x5a6173), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_cont_1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->Music_player_cont_1, lv_color_hex(0x198fa4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->Music_player_cont_1, 38, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->Music_player_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Music_player_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Music_player_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Music_player_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Music_player_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Music_player_roller_1
	ui->Music_player_roller_1 = lv_roller_create(ui->Music_player_cont_1);
	
	char roller_str[256];
	music_scan_list(roller_str);
	lv_roller_set_options(ui->Music_player_roller_1, roller_str, LV_ROLLER_MODE_INFINITE);
	//lv_roller_set_options(ui->Music_player_roller_1, "music1\nmusic2\nmusic3\nmusic4\nmusic5", LV_ROLLER_MODE_INFINITE);
	luckfox_lv_obj_set_pos(ui->Music_player_roller_1, 19, 27);
	luckfox_lv_obj_set_width(ui->Music_player_roller_1, 272);
	luckfox_lv_obj_align(ui->Music_player_roller_1, LV_ALIGN_CENTER, 0, 0);

	//Write style for Music_player_roller_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->Music_player_roller_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Music_player_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_roller_1, lv_color_hex(0x5a6173), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_roller_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Music_player_roller_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_roller_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_roller_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Music_player_roller_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Music_player_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Music_player_roller_1, lv_color_hex(0x7d8490), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Music_player_roller_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Music_player_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Music_player_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Music_player_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Music_player_roller_1, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Music_player_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Music_player_roller_1, lv_color_hex(0x5a6173), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Music_player_roller_1, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Music_player_roller_1, lv_color_hex(0xffa300), LV_PART_SELECTED|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Music_player_roller_1, &lv_font_montserratMedium_18, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Music_player_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Music_player_roller_1, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->Music_player_roller_1, 6);
	//The custom code of Music_player.
	
	lv_obj_add_event_cb(ui->Music_player_play_mode_btn, Music_player_mode_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_next_btn, Music_player_next_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_pre_btn, Music_player_pre_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_start_btn, Music_player_start_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_volume_slider, Music_player_volume_slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_progress_slider, Music_player_progress_slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_roller_1, Music_player_list_roller_event_handler,LV_EVENT_VALUE_CHANGED , ui);

	//Update current screen layout.
	lv_obj_update_layout(ui->Music_player);

	//Init events for screen.
	events_init_Music_player(ui);
    music_app_init();
	
}
