
// File generated by bin2lvgl
// developed by fbiego.
// https://github.com/fbiego
// modified by Daniel Kampert.
// https://github.com/kampi
// Watchface: 66_2_dial

#include <lvgl.h>

#include <zephyr/logging/log.h>

#include "ui/zsw_ui.h"
#include "applications/watchface/watchface_app.h"
#include "ui/watchfaces/zsw_ui_notification_area.h"

LOG_MODULE_REGISTER(watchface_66_2_dial, LOG_LEVEL_WRN);

static lv_obj_t *face_66_2_dial;
static lv_obj_t *face_66_2_dial = NULL;
static watchface_app_evt_listener ui_66_2_dial_evt_cb;
static zsw_ui_notification_area_t *zsw_ui_notifications_area;

static int last_date = -1;
static int last_day = -1;
static int last_month = -1;
static int last_year = -1;
static int last_weekday = -1;
static int last_hour = -1;
static int last_minute = -1;

static int last_steps = -1;
static int last_distance = -1;
static int last_kcal = -1;

static lv_obj_t *face_66_2_dial_0_184;
static lv_obj_t *face_66_2_dial_1_68896;
static lv_obj_t *face_66_2_dial_2_61582;
static lv_obj_t *face_66_2_dial_3_105480;
static lv_obj_t *face_66_2_dial_4_92084;
static lv_obj_t *face_66_2_dial_5_60018;
static lv_obj_t *face_66_2_dial_6_58294;
static lv_obj_t *face_66_2_dial_8_123132;

ZSW_LV_IMG_DECLARE(face_66_2_dial_0_184_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_7);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_8);
ZSW_LV_IMG_DECLARE(face_66_2_dial_1_68896_9);
ZSW_LV_IMG_DECLARE(face_66_2_dial_2_61582_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_2_61582_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_2_61582_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_7);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_8);
ZSW_LV_IMG_DECLARE(face_66_2_dial_3_105480_9);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_7);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_8);
ZSW_LV_IMG_DECLARE(face_66_2_dial_4_92084_9);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_7);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_8);
ZSW_LV_IMG_DECLARE(face_66_2_dial_5_60018_9);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_7);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_8);
ZSW_LV_IMG_DECLARE(face_66_2_dial_6_58294_9);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_7_118948_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_0);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_1);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_2);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_3);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_4);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_5);
ZSW_LV_IMG_DECLARE(face_66_2_dial_8_123132_6);
ZSW_LV_IMG_DECLARE(face_66_2_dial_preview_0);

#if CONFIG_LV_COLOR_DEPTH_16 != 1
#error "CONFIG_LV_COLOR_DEPTH_16 should be 16 bit for watchfaces"
#endif
#if CONFIG_LV_COLOR_16_SWAP != 1
#error "CONFIG_LV_COLOR_16_SWAP should be 1 for watchfaces"
#endif

const void *face_66_2_dial_1_68896_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_0),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_1),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_2),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_3),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_4),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_5),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_6),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_7),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_8),
    ZSW_LV_IMG_USE(face_66_2_dial_1_68896_9),
};
const void *face_66_2_dial_2_61582_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_2_61582_0),
    ZSW_LV_IMG_USE(face_66_2_dial_2_61582_1),
    ZSW_LV_IMG_USE(face_66_2_dial_2_61582_2),
};
const void *face_66_2_dial_3_105480_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_0),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_1),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_2),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_3),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_4),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_5),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_6),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_7),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_8),
    ZSW_LV_IMG_USE(face_66_2_dial_3_105480_9),
};
const void *face_66_2_dial_4_92084_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_0),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_1),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_2),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_3),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_4),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_5),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_6),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_7),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_8),
    ZSW_LV_IMG_USE(face_66_2_dial_4_92084_9),
};
const void *face_66_2_dial_5_60018_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_0),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_1),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_2),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_3),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_4),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_5),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_6),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_7),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_8),
    ZSW_LV_IMG_USE(face_66_2_dial_5_60018_9),
};
const void *face_66_2_dial_6_58294_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_0),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_1),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_2),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_3),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_4),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_5),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_6),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_7),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_8),
    ZSW_LV_IMG_USE(face_66_2_dial_6_58294_9),
};
const void *face_66_2_dial_7_118948_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_0),
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_1),
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_2),
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_3),
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_4),
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_5),
    ZSW_LV_IMG_USE(face_66_2_dial_7_118948_6),
};
const void *face_66_2_dial_8_123132_group[] = {
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_0),
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_1),
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_2),
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_3),
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_4),
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_5),
    ZSW_LV_IMG_USE(face_66_2_dial_8_123132_6),
};

static int32_t getPlaceValue(int32_t num, int32_t place)
{
    int32_t divisor = 1;
    for (uint32_t i = 1; i < place; i++) {
        divisor *= 10;
    }
    return (num / divisor) % 10;
}

static int32_t setPlaceValue(int32_t num, int32_t place, int32_t newValue)
{
    int32_t divisor = 1;
    for (uint32_t i = 1; i < place; i++) {
        divisor *= 10;
    }
    return num - ((num / divisor) % 10 * divisor) + (newValue * divisor);
}

static void watchface_66_2_dial_remove(void)
{
    if (!face_66_2_dial) {
        return;
    }

    lv_obj_del(face_66_2_dial);
    face_66_2_dial = NULL;
}

static void watchface_66_2_dial_invalidate_cached(void)
{
    last_date = -1;
    last_day = -1;
    last_month = -1;
    last_year = -1;
    last_weekday = -1;
    last_hour = -1;
    last_minute = -1;
    last_steps = -1;
    last_distance = -1;
    last_kcal = -1;
}

static const void *watchface_66_2_dial_get_preview_img(void)
{
    return ZSW_LV_IMG_USE(face_66_2_dial_preview_0);
}

static void watchface_66_2_dial_set_datetime(int day_of_week, int date, int day, int month, int year, int weekday,
                                             int hour,
                                             int minute, int second, uint32_t usec, bool am, bool mode)
{
    if (!face_66_2_dial) {
        return;
    }

    if (getPlaceValue(last_hour, 1) != getPlaceValue(hour, 1)) {
        last_hour = setPlaceValue(last_hour, 1, getPlaceValue(hour, 1));
        lv_img_set_src(face_66_2_dial_1_68896, face_66_2_dial_1_68896_group[(hour / 1) % 10]);
    }

    if (getPlaceValue(last_hour, 2) != getPlaceValue(hour, 2)) {
        last_hour = setPlaceValue(last_hour, 2, getPlaceValue(hour, 2));
        lv_img_set_src(face_66_2_dial_2_61582, face_66_2_dial_2_61582_group[(hour / 10) % 3]);
    }

    if (getPlaceValue(last_minute, 1) != getPlaceValue(minute, 1)) {
        last_minute = setPlaceValue(last_minute, 1, getPlaceValue(minute, 1));
        lv_img_set_src(face_66_2_dial_3_105480, face_66_2_dial_3_105480_group[(minute / 1) % 10]);
    }

    if (getPlaceValue(last_minute, 2) != getPlaceValue(minute, 2)) {
        last_minute = setPlaceValue(last_minute, 2, getPlaceValue(minute, 2));
        lv_img_set_src(face_66_2_dial_4_92084, face_66_2_dial_4_92084_group[(minute / 10) % 10]);
    }

    if (getPlaceValue(last_day, 1) != getPlaceValue(day, 1)) {
        last_day = setPlaceValue(last_day, 1, getPlaceValue(day, 1));
        lv_img_set_src(face_66_2_dial_5_60018, face_66_2_dial_5_60018_group[(day / 1) % 10]);
    }

    if (getPlaceValue(last_day, 2) != getPlaceValue(day, 2)) {
        last_day = setPlaceValue(last_day, 2, getPlaceValue(day, 2));
        lv_img_set_src(face_66_2_dial_6_58294, face_66_2_dial_6_58294_group[(day / 10) % 10]);
    }

    if (getPlaceValue(last_weekday, 1) != getPlaceValue(weekday, 1)) {
        last_weekday = setPlaceValue(last_weekday, 1, getPlaceValue(weekday, 1));
        lv_img_set_src(face_66_2_dial_8_123132, face_66_2_dial_8_123132_group[((weekday + 6) / 1) % 7]);
    }

}

static void watchface_66_2_dial_set_step(int32_t steps, int32_t distance, int32_t kcal)
{
    if (!face_66_2_dial) {
        return;
    }

}

static void watchface_66_2_dial_set_hrm(int32_t bpm, int32_t oxygen)
{
    if (!face_66_2_dial) {
        return;
    }

}

static void watchface_66_2_dial_set_weather(int8_t temp, int icon)
{
    if (!face_66_2_dial) {
        return;
    }

}

static void watchface_66_2_dial_set_ble_connected(bool connected)
{
    if (!face_66_2_dial) {
        return;
    }

    zsw_ui_notification_area_ble_connected(zsw_ui_notifications_area, connected);
}

static void watchface_66_2_dial_set_battery_percent(int32_t percent, int32_t battery)
{
    if (!face_66_2_dial) {
        return;
    }

}

static void watchface_66_2_dial_set_num_notifcations(int32_t number)
{
    if (!face_66_2_dial) {
        return;
    }

    zsw_ui_notification_area_num_notifications(zsw_ui_notifications_area, number);
}

static void watchface_66_2_dial_set_watch_env_sensors(int temperature, int humidity, int pressure, float iaq, float co2)
{
    if (!face_66_2_dial) {
        return;
    }

}

void watchface_66_2_dial_show(watchface_app_evt_listener evt_cb, zsw_settings_watchface_t *settings)
{
    ui_66_2_dial_evt_cb = evt_cb;

    lv_obj_clear_flag(lv_scr_act(), LV_OBJ_FLAG_SCROLLABLE);
    face_66_2_dial = lv_obj_create(lv_scr_act());
    watchface_66_2_dial_invalidate_cached();

    lv_obj_clear_flag(face_66_2_dial, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_scrollbar_mode(face_66_2_dial, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_opa(face_66_2_dial, LV_OPA_TRANSP, LV_PART_MAIN);

    lv_obj_set_style_border_width(face_66_2_dial, 0, LV_PART_MAIN);
    lv_obj_set_size(face_66_2_dial, 240, 240);
    lv_obj_clear_flag(face_66_2_dial, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(face_66_2_dial, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(face_66_2_dial, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(face_66_2_dial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(face_66_2_dial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(face_66_2_dial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(face_66_2_dial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(face_66_2_dial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    face_66_2_dial_0_184 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_0_184, ZSW_LV_IMG_USE(face_66_2_dial_0_184_0));
    lv_obj_set_width(face_66_2_dial_0_184, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_0_184, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_0_184, 0);
    lv_obj_set_y(face_66_2_dial_0_184, 0);
    lv_obj_add_flag(face_66_2_dial_0_184, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_0_184, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_1_68896 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_1_68896, ZSW_LV_IMG_USE(face_66_2_dial_1_68896_0));
    lv_obj_set_width(face_66_2_dial_1_68896, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_1_68896, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_1_68896, 134);
    lv_obj_set_y(face_66_2_dial_1_68896, 21);
    lv_obj_add_flag(face_66_2_dial_1_68896, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_1_68896, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_2_61582 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_2_61582, ZSW_LV_IMG_USE(face_66_2_dial_2_61582_0));
    lv_obj_set_width(face_66_2_dial_2_61582, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_2_61582, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_2_61582, 83);
    lv_obj_set_y(face_66_2_dial_2_61582, 21);
    lv_obj_add_flag(face_66_2_dial_2_61582, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_2_61582, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_3_105480 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_3_105480, ZSW_LV_IMG_USE(face_66_2_dial_3_105480_0));
    lv_obj_set_width(face_66_2_dial_3_105480, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_3_105480, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_3_105480, 165);
    lv_obj_set_y(face_66_2_dial_3_105480, 95);
    lv_obj_add_flag(face_66_2_dial_3_105480, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_3_105480, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_4_92084 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_4_92084, ZSW_LV_IMG_USE(face_66_2_dial_4_92084_0));
    lv_obj_set_width(face_66_2_dial_4_92084, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_4_92084, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_4_92084, 125);
    lv_obj_set_y(face_66_2_dial_4_92084, 95);
    lv_obj_add_flag(face_66_2_dial_4_92084, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_4_92084, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_5_60018 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_5_60018, ZSW_LV_IMG_USE(face_66_2_dial_5_60018_0));
    lv_obj_set_width(face_66_2_dial_5_60018, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_5_60018, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_5_60018, 106);
    lv_obj_set_y(face_66_2_dial_5_60018, 119);
    lv_obj_add_flag(face_66_2_dial_5_60018, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_5_60018, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_6_58294 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_6_58294, ZSW_LV_IMG_USE(face_66_2_dial_6_58294_0));
    lv_obj_set_width(face_66_2_dial_6_58294, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_6_58294, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_6_58294, 94);
    lv_obj_set_y(face_66_2_dial_6_58294, 119);
    lv_obj_add_flag(face_66_2_dial_6_58294, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_6_58294, LV_OBJ_FLAG_SCROLLABLE);

    face_66_2_dial_8_123132 = lv_img_create(face_66_2_dial);
    lv_img_set_src(face_66_2_dial_8_123132, ZSW_LV_IMG_USE(face_66_2_dial_8_123132_0));
    lv_obj_set_width(face_66_2_dial_8_123132, LV_SIZE_CONTENT);
    lv_obj_set_height(face_66_2_dial_8_123132, LV_SIZE_CONTENT);
    lv_obj_set_x(face_66_2_dial_8_123132, 83);
    lv_obj_set_y(face_66_2_dial_8_123132, 96);
    lv_obj_add_flag(face_66_2_dial_8_123132, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(face_66_2_dial_8_123132, LV_OBJ_FLAG_SCROLLABLE);

    zsw_ui_notifications_area = zsw_ui_notification_area_add(face_66_2_dial);
    lv_obj_set_pos(zsw_ui_notifications_area->ui_notifications_container, 20, 43);
}

static watchface_ui_api_t ui_api = {
    .show = watchface_66_2_dial_show,
    .remove = watchface_66_2_dial_remove,
    .set_battery_percent = watchface_66_2_dial_set_battery_percent,
    .set_hrm = watchface_66_2_dial_set_hrm,
    .set_step = watchface_66_2_dial_set_step,
    .set_ble_connected = watchface_66_2_dial_set_ble_connected,
    .set_num_notifcations = watchface_66_2_dial_set_num_notifcations,
    .set_weather = watchface_66_2_dial_set_weather,
    .set_datetime = watchface_66_2_dial_set_datetime,
    .set_watch_env_sensors = watchface_66_2_dial_set_watch_env_sensors,
    .ui_invalidate_cached = watchface_66_2_dial_invalidate_cached,
    .get_preview_img = watchface_66_2_dial_get_preview_img,
};

static int watchface_66_2_dial_init(void)
{
    watchface_app_register_ui(&ui_api);

    return 0;
}

SYS_INIT(watchface_66_2_dial_init, APPLICATION, WATCHFACE_UI_INIT_PRIO);
