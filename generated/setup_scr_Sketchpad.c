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

extern float SCALE;

void setup_scr_Sketchpad(lv_ui *ui)
{
	//Write codes Sketchpad
	ui->Sketchpad = lv_obj_create(NULL);
	ui->g_kb_Sketchpad = lv_keyboard_create(ui->Sketchpad);
	lv_obj_add_event_cb(ui->g_kb_Sketchpad, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_Sketchpad, LV_OBJ_FLAG_HIDDEN);
	luckfox_lv_obj_set_style_text_font(ui->g_kb_Sketchpad, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_size(ui->Sketchpad, 480, 480);
	lv_obj_set_scrollbar_mode(ui->Sketchpad, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->Sketchpad, LV_OBJ_FLAG_SCROLLABLE);


	//The custom code of Sketchpad.
	lv_obj_t * sketchpad_obj = lv_sketchpad_create(ui->Sketchpad);
	int cbuf_width = WIDTH * SCALE;
	int cbuf_height = HEIGHT * 0.75 * SCALE;
	int cbuf_skeptchpad_pos_y_offset = -80 * SCALE;
	lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(cbuf_width, cbuf_height)];
	lv_canvas_set_buffer(sketchpad_obj, cbuf, cbuf_width, cbuf_height, LV_IMG_CF_TRUE_COLOR);
	lv_obj_align(sketchpad_obj, LV_ALIGN_CENTER, 0, cbuf_skeptchpad_pos_y_offset);
    lv_canvas_fill_bg(sketchpad_obj, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);


	//Write style for Sketchpad, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Sketchpad, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Sketchpad, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Sketchpad, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Sketchpad_color_cpicker
	ui->Sketchpad_color_cpicker = lv_colorwheel_create(ui->Sketchpad, true);
	luckfox_lv_obj_set_pos(ui->Sketchpad_color_cpicker, 42, 350);
	luckfox_lv_obj_set_size(ui->Sketchpad_color_cpicker, 79, 79);

	//Write style for Sketchpad_color_cpicker, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->Sketchpad_color_cpicker, 9, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Sketchpad_clear_btn
	ui->Sketchpad_clear_btn = lv_btn_create(ui->Sketchpad);
	ui->Sketchpad_clear_btn_label = lv_label_create(ui->Sketchpad_clear_btn);
	lv_label_set_text(ui->Sketchpad_clear_btn_label, "Clear\n");
	lv_label_set_long_mode(ui->Sketchpad_clear_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Sketchpad_clear_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Sketchpad_clear_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Sketchpad_clear_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Sketchpad_clear_btn, 180, 350);
	luckfox_lv_obj_set_size(ui->Sketchpad_clear_btn, 100, 100);

	//Write style for Sketchpad_clear_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Sketchpad_clear_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Sketchpad_clear_btn, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Sketchpad_clear_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Sketchpad_clear_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Sketchpad_clear_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Sketchpad_clear_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Sketchpad_clear_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Sketchpad_clear_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Sketchpad_clear_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Sketchpad_clear_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Sketchpad_clear_btn, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Sketchpad_clear_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Sketchpad_clear_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Sketchpad_back_btn
	ui->Sketchpad_back_btn = lv_btn_create(ui->Sketchpad);
	ui->Sketchpad_back_btn_label = lv_label_create(ui->Sketchpad_back_btn);
	lv_label_set_text(ui->Sketchpad_back_btn_label, "Back\n");
	lv_label_set_long_mode(ui->Sketchpad_back_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Sketchpad_back_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Sketchpad_back_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Sketchpad_back_btn_label, LV_PCT(100));
	luckfox_lv_obj_set_pos(ui->Sketchpad_back_btn, 334, 350);
	luckfox_lv_obj_set_size(ui->Sketchpad_back_btn, 100, 100);

	//Write style for Sketchpad_back_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Sketchpad_back_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Sketchpad_back_btn, lv_color_hex(0x979798), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Sketchpad_back_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Sketchpad_back_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Sketchpad_back_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Sketchpad_back_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Sketchpad_back_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Sketchpad_back_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Sketchpad_back_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Sketchpad_back_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	luckfox_lv_obj_set_style_text_font(ui->Sketchpad_back_btn, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Sketchpad_back_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Sketchpad_back_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_add_event_cb(ui->Sketchpad_color_cpicker, Sketchpad_color_cpicker_event_cb, LV_EVENT_RELEASED, ui);
	lv_obj_add_event_cb(ui->Sketchpad_clear_btn, Sketchpad_clear_btn_event_cb, LV_EVENT_ALL, ui);

	//Update current screen layout.
	lv_obj_update_layout(ui->Sketchpad);

	//Init events for screen.
	events_init_Sketchpad(ui);
}
