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
#define LAST_VALUE -32768 

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_img_t img;
    lv_img_dsc_t dsc;
    lv_draw_line_dsc_t line_rect_dsc;
} lv_sketchpad_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_sketchpad_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_sketchpad_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_sketchpad_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_sketchpad_class = {
    .constructor_cb = lv_sketchpad_constructor,
    .destructor_cb = lv_sketchpad_destructor,
    .event_cb = lv_sketchpad_event,
    .instance_size = sizeof(lv_sketchpad_t),
    .base_class = &lv_canvas_class
};

lv_obj_t * canva_obj;

/**********************
 *  STATIC FUNCTIONS
 **********************/
static void lv_sketchpad_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    lv_sketchpad_t * sketchpad = (lv_sketchpad_t *)obj; 
    canva_obj = obj;
    
    sketchpad->dsc.header.always_zero = 0;
    sketchpad->dsc.header.cf          = LV_IMG_CF_TRUE_COLOR;
    sketchpad->dsc.header.h           = 0;
    sketchpad->dsc.header.w           = 0;
    sketchpad->dsc.data_size          = 0;
    sketchpad->dsc.data               = NULL;

    lv_draw_line_dsc_init(&sketchpad->line_rect_dsc);
    sketchpad->line_rect_dsc.width = 2;
    sketchpad->line_rect_dsc.round_start = true;
    sketchpad->line_rect_dsc.round_end = true;
    sketchpad->line_rect_dsc.color = lv_color_black();
    sketchpad->line_rect_dsc.opa = LV_OPA_COVER;

    lv_img_set_src(obj, &sketchpad->dsc);

    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
}

static void lv_sketchpad_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    lv_canvas_t * canvas = (lv_canvas_t *)obj;
    lv_img_cache_invalidate_src(&canvas->dsc);
}

void lv_sketchpad_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_res_t res;
    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(&lv_sketchpad_class, e);
    if(res != LV_RES_OK) return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_sketchpad_t * sketchpad = (lv_sketchpad_t *)obj;

    static lv_coord_t last_x, last_y = LAST_VALUE;

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t * indev = lv_indev_get_act();
        if(indev == NULL)  return;

        lv_point_t point;
        lv_indev_get_point(indev, &point);

        lv_color_t c0;
        c0.full = 10;

        lv_point_t points[2];

        /*Release or first use*/
        if ((last_x == LAST_VALUE) || (last_y == LAST_VALUE))
        {
            last_x = point.x;
            last_y = point.y;
        }
        else
        {
            points[0].x = last_x;
            points[0].y = last_y;
            points[1].x = point.x;
            points[1].y = point.y;
            last_x = point.x;
            last_y = point.y;

            lv_canvas_draw_line(obj, points, 2, &sketchpad->line_rect_dsc);
        }
    }

    /*Loosen the brush*/
    else if(code == LV_EVENT_RELEASED)
    {
        last_x = LAST_VALUE;
        last_y = LAST_VALUE;
    }
}

/**********************
 *  GLOBAL FUNCTIONS
 **********************/
lv_obj_t * lv_sketchpad_create(lv_obj_t * parent)
{
    lv_obj_t * obj = lv_obj_class_create_obj(&lv_sketchpad_class, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

void Sketchpad_color_cpicker_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_sketchpad_t * pad_obj = (lv_sketchpad_t *)canva_obj;

    if (code == LV_EVENT_RELEASED)
    {
		pad_obj->line_rect_dsc.color = lv_colorwheel_get_rgb(obj);
    }
}

void Sketchpad_clear_btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    if (code == LV_EVENT_RELEASED)
    {
        // clear canvas
        lv_canvas_fill_bg(canva_obj, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
    }
}