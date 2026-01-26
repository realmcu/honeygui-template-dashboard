/**
 * dashboardMain UI实现（自动生成，请勿手动修改）
 * 生成时间: 2026-01-19T03:05:57.651Z
 */
#include "dashboardMain_ui.h"
#include "../callbacks/dashboardMain_callbacks.h"
#include <stddef.h>

// 组件句柄定义
gui_obj_t *map = NULL;
gui_obj_t *map_fade = NULL;
gui_obj_t *dail_speed = NULL;
gui_obj_t *dail_power = NULL;
gui_obj_t *text_loc_temp = NULL;
gui_obj_t *text_time = NULL;
gui_obj_t *bt_icon = NULL;
gui_obj_t *switch_icon = NULL;
gui_obj_t *wifi_icon = NULL;
gui_obj_t *off_icon = NULL;
gui_obj_t *turn_l_icon = NULL;
gui_obj_t *turn_r_icon = NULL;


// 创建 dashboardMainView (hg_view)
static void dashboardMainView_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void dashboardMainView_switch_in(gui_view_t *view)
{
    // 设置动画步长
    gui_view_set_animate_step(view, 48);

    // 设置透明度
    gui_view_set_opacity(view, 255);

    GUI_UNUSED(view);


    // 创建 map (hg_image)
    map = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "map", "/resource/Map.bin", 141, 198, 517, 282);
    gui_img_set_mode((gui_img_t *)map, IMG_BYPASS_MODE);
    gui_obj_show(map, true);

    // 创建 map_fade (hg_image)
    map_fade = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "map_fade", "/resource/MapFading.bin", 141, 198, 518, 282);
    gui_img_set_mode((gui_img_t *)map_fade, IMG_SRC_OVER_MODE);
    gui_obj_show(map_fade, true);

    // 创建 dail_speed (hg_image)
    dail_speed = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "dail_speed", "/resource/dail_speed.bin", 38, 64, 295, 294);
    gui_img_set_mode((gui_img_t *)dail_speed, IMG_SRC_OVER_MODE);
    gui_obj_show(dail_speed, true);

    // 创建 dail_power (hg_image)
    dail_power = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "dail_power", "/resource/dail_power.bin", 470, 64, 295, 294);
    gui_img_set_mode((gui_img_t *)dail_power, IMG_SRC_OVER_MODE);
    gui_obj_show(dail_power, true);

    // 创建 text_loc_temp (hg_label)
    text_loc_temp = gui_text_create((gui_obj_t *)view, "text_loc_temp", 334, 32, 132, 22);
    gui_text_set((gui_text_t *)text_loc_temp, "Suzhou 25°C", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 12, 22);
    gui_text_type_set((gui_text_t *)text_loc_temp, "//HarmonyOS_Sans_Bold_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_loc_temp, MULTI_CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_loc_temp, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_loc_temp, 0);

    // 创建 text_time (hg_label)
    text_time = gui_text_create((gui_obj_t *)view, "text_time", 334, 55, 132, 22);
    gui_text_set((gui_text_t *)text_time, "10:10", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 5, 22);
    gui_text_type_set((gui_text_t *)text_time, "//HarmonyOS_Sans_Bold_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_time, MULTI_CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_time, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_time, 0);

    // 创建 bt_icon (hg_image)
    bt_icon = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "bt_icon", "/resource/bt.bin", 294, 52, 14, 20);
    gui_obj_show(bt_icon, true);

    // 创建 switch_icon (hg_image)
    switch_icon = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "switch_icon", "/resource/SwitchIcon_release.bin", 25, 17, 25, 17);
    gui_obj_show(switch_icon, true);

    // 创建 wifi_icon (hg_image)
    wifi_icon = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "wifi_icon", "/resource/wifi.bin", 478, 52, 28, 20);
    gui_obj_show(wifi_icon, true);

    // 创建 off_icon (hg_image)
    off_icon = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "off_icon", "/resource/OffIcon_release.bin", 746, 23, 20, 20);
    gui_obj_show(off_icon, true);

    // 创建 turn_l_icon (hg_image)
    turn_l_icon = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "turn_l_icon", "/resource/Turnleft_off.bin", 20, 64, 35, 19);
    gui_obj_show(turn_l_icon, true);

    // 创建 turn_r_icon (hg_image)
    turn_r_icon = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "turn_r_icon", "/resource/Turnright_off.bin", 745, 64, 35, 19);
    gui_obj_show(turn_r_icon, true);

    // 创建用户配置的定时器
    gui_obj_create_timer((gui_obj_t *)text_time, 10, true, time_update_cb);
    gui_obj_start_timer((gui_obj_t *)text_time);
}
GUI_VIEW_INSTANCE("dashboardMainView", false, dashboardMainView_switch_in, dashboardMainView_switch_out);
