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



void setup_scr_Gif(lv_ui *ui)
{
	//Write codes Gif
	ui->Gif = lv_obj_create(NULL);
	ui->g_kb_Gif = lv_keyboard_create(ui->Gif);
	lv_obj_add_event_cb(ui->g_kb_Gif, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_Gif, LV_OBJ_FLAG_HIDDEN);
	luckfox_lv_obj_set_style_text_font(ui->g_kb_Gif, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_size(ui->Gif, 480, 480);
	lv_obj_set_scrollbar_mode(ui->Gif, LV_SCROLLBAR_MODE_OFF);

	//Write style for Gif, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Gif, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Gif, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Gif, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Gif_fox_gif
	ui->Gif_fox_gif = lv_animimg_create(ui->Gif);
	lv_animimg_set_src(ui->Gif_fox_gif, (const void **) Gif_fox_gif_imgs, 20, false);
	lv_animimg_set_duration(ui->Gif_fox_gif, 30*20);
	lv_animimg_set_repeat_count(ui->Gif_fox_gif, LV_ANIM_REPEAT_INFINITE);
	lv_animimg_start(ui->Gif_fox_gif);
	luckfox_lv_obj_set_pos(ui->Gif_fox_gif, 140, 140);
	luckfox_lv_obj_set_size(ui->Gif_fox_gif, 200, 200);

	//The custom code of Gif.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Gif);

	//Init events for screen.
	events_init_Gif(ui);
}
