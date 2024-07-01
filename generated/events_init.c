/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern int MUSIC_ENABLE;

static void Main_Wifi_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.WIFI, guider_ui.WIFI_del, &guider_ui.Main_del, setup_scr_WIFI, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
static void Main_PAD_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Sketchpad, guider_ui.Sketchpad_del, &guider_ui.Main_del, setup_scr_Sketchpad, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
static void Main_Music_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		if(MUSIC_ENABLE == 1)
			ui_load_scr_animation(&guider_ui, &guider_ui.Music_player, guider_ui.Music_player_del, &guider_ui.Main_del, setup_scr_Music_player, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		else 
			lv_obj_clear_flag(guider_ui.Main_win_music, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void Main_GIF_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Gif, guider_ui.Gif_del, &guider_ui.Main_del, setup_scr_Gif, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
static void Main_win_music_item0_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.Main_win_music, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_Main(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Main_Wifi_btn, Main_Wifi_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Main_PAD_btn, Main_PAD_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Main_Music_btn, Main_Music_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Main_GIF_btn, Main_GIF_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Main_win_music_item0, Main_win_music_item0_event_handler, LV_EVENT_ALL, ui);
}
static void WIFI_back_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.WIFI_del, setup_scr_Main, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
void events_init_WIFI(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->WIFI_back_btn, WIFI_back_btn_event_handler, LV_EVENT_ALL, ui);
}
static void Gif_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.Gif_del, setup_scr_Main, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
void events_init_Gif(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Gif, Gif_event_handler, LV_EVENT_ALL, ui);
}
static void Sketchpad_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCROLL:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.Sketchpad_del, setup_scr_Main, LV_SCR_LOAD_ANIM_NONE, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
static void Sketchpad_back_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.Sketchpad_del, setup_scr_Main, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
void events_init_Sketchpad(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Sketchpad, Sketchpad_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Sketchpad_back_btn, Sketchpad_back_btn_event_handler, LV_EVENT_ALL, ui);
}
static void Music_player_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.Music_player_cont_1, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void Music_player_music_list_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.Music_player_cont_1, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void Music_player_back_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.Music_player_del, setup_scr_Main, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, false);
		break;
	}
	default:
		break;
	}
}
void events_init_Music_player(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Music_player, Music_player_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_music_list_btn, Music_player_music_list_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Music_player_back_btn, Music_player_back_btn_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
