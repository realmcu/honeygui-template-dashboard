/**
 * dashboardMain UI实现（自动生成，请勿手动修改）
 * 生成时间: 2026-02-04T10:10:35.970Z
 */
#include "dashboardMain_ui.h"
#include "../callbacks/dashboardMain_callbacks.h"
#include <stddef.h>

// 组件句柄定义
gui_obj_t *gloom = NULL;
gui_obj_t *start_engine = NULL;
gui_obj_t *shadow = NULL;
gui_obj_t *win_map = NULL;
gui_obj_t *map = NULL;
gui_obj_t *map_fade = NULL;
gui_obj_t *root_menu = NULL;
gui_obj_t *win_dashboard = NULL;
gui_obj_t *win_dail = NULL;
gui_obj_t *win_line = NULL;
gui_obj_t *line_left = NULL;
gui_obj_t *line_right = NULL;
gui_obj_t *win_speed = NULL;
gui_obj_t *dail_speed = NULL;
gui_obj_t *speed_arc = NULL;
gui_obj_t *dail_pointer_s = NULL;
gui_obj_t *win_power = NULL;
gui_obj_t *dail_power = NULL;
gui_obj_t *power_arc = NULL;
gui_obj_t *dail_pointer_p = NULL;
gui_obj_t *rightbottom_gloom = NULL;
gui_obj_t *leftbottom_gloom = NULL;
gui_obj_t *win_common = NULL;
gui_obj_t *turn_l_icon = NULL;
gui_obj_t *turn_r_icon = NULL;
gui_obj_t *off_icon = NULL;
gui_obj_t *switch_icon = NULL;
gui_obj_t *bt_icon = NULL;
gui_obj_t *wifi_icon = NULL;
gui_text_t *text_loc_temp = NULL;
gui_text_t *text_time = NULL;
gui_obj_t *led_0 = NULL;
gui_obj_t *led_1 = NULL;
gui_obj_t *led_2 = NULL;
gui_obj_t *led_3 = NULL;
gui_obj_t *led_4 = NULL;
gui_obj_t *led_5 = NULL;
gui_obj_t *win_speed_text = NULL;
gui_text_t *text_speed = NULL;
gui_text_t *text_speed_unit = NULL;
gui_obj_t *line = NULL;
gui_text_t *text_odo = NULL;
gui_obj_t *win_power_text = NULL;
gui_text_t *text_power = NULL;
gui_text_t *text_power_unit = NULL;
gui_obj_t *line_copy_1768894235876_3 = NULL;
gui_text_t *text_battery = NULL;


// 创建 dashboardMainView (hg_view)
static void dashboardMainView_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void dashboardMainView_switch_in(gui_view_t *view)
{
    // 设置动画步长
    gui_view_set_animate_step(view, 500);

    // 设置透明度
    gui_view_set_opacity(view, 255);

    GUI_UNUSED(view);


    // 创建 gloom (hg_image)
    gloom = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "gloom", "/resource/StartEngineGloom.bin", 80, 58, 640, 364);
    gui_img_set_opacity((gui_img_t *)gloom, 0);
    gui_obj_show(gloom, true);

    // 创建 start_engine (hg_image)
    start_engine = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "start_engine", "/resource/StartEngine.bin", 305, 145, 190, 190);
    gui_obj_show(start_engine, true);
    gui_obj_add_event_cb(start_engine, (gui_event_cb_t)start_engine_animation_set_0_cb, GUI_EVENT_TOUCH_PRESSED, NULL);
    gui_obj_add_event_cb(start_engine, (gui_event_cb_t)start_engine_animation_set_1_cb, GUI_EVENT_TOUCH_RELEASED, NULL);

    // 创建 shadow (hg_image)
    shadow = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "shadow", "/resource/Start_Engine_Release.bin", 348, 187, 105, 105);
    gui_obj_show(shadow, true);
}
GUI_VIEW_INSTANCE("dashboardMainView", false, dashboardMainView_switch_in, dashboardMainView_switch_out);

// 创建 dashboard_view (hg_view)
static void dashboard_view_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void dashboard_view_switch_in(gui_view_t *view)
{
    // 设置动画步长
    gui_view_set_animate_step(view, 500);

    // 设置透明度
    gui_view_set_opacity(view, 255);

    GUI_UNUSED(view);


    // 创建 win_map (hg_window)
    win_map = (gui_obj_t *)gui_win_create((gui_obj_t *)view, "win_map", 141, 198, 517, 282);
    gui_obj_show(win_map, false);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)win_map, 6000, false, win_map_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_map);


    // 创建 map (hg_image)
    map = (gui_obj_t *)gui_img_create_from_fs(win_map, "map", "/resource/Map.bin", 0, 0, 517, 282);
    gui_img_set_mode((gui_img_t *)map, IMG_BYPASS_MODE);
    gui_obj_show(map, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)map, 6000, true, map_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)map);

    // 创建 map_fade (hg_image)
    map_fade = (gui_obj_t *)gui_img_create_from_fs(win_map, "map_fade", "/resource/MapFading.bin", 0, 0, 518, 282);
    gui_img_set_mode((gui_img_t *)map_fade, IMG_SRC_OVER_MODE);
    gui_obj_show(map_fade, true);

    // 创建 root_menu (hg_image)
    root_menu = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "root_menu", "/resource/menu/menu_001.bin", 225, 480, 350, 190);
    gui_img_set_mode((gui_img_t *)root_menu, IMG_SRC_OVER_MODE);
    gui_obj_show(root_menu, true);
    gui_msg_subscribe(root_menu, "up", root_menu_msg_up_cb);
    gui_msg_subscribe(root_menu, "down", root_menu_msg_down_cb);
    gui_msg_subscribe(root_menu, "right", root_menu_msg_right_cb);
    gui_msg_subscribe(root_menu, "left", root_menu_msg_left_cb);

    // 创建 win_dashboard (hg_window)
    win_dashboard = (gui_obj_t *)gui_win_create((gui_obj_t *)view, "win_dashboard", 0, 0, 800, 480);
    gui_obj_show(win_dashboard, true);


    // 创建 win_dail (hg_window)
    win_dail = (gui_obj_t *)gui_win_create(win_dashboard, "win_dail", 0, 0, 800, 480);
    gui_obj_show(win_dail, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)win_dail, 7, true, win_dail_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_dail);


    // 创建 win_line (hg_window)
    win_line = (gui_obj_t *)gui_win_create(win_dail, "win_line", 331, 53, 138, 100);
    gui_obj_show(win_line, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)win_line, 30, true, win_line_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_line);


    // 创建 line_left (hg_image)
    line_left = (gui_obj_t *)gui_img_create_from_fs(win_line, "line_left", "/resource/LeftLineV1.bin", -306, 0, 375, 417);
    ((gui_img_t *)line_left)->need_clip = true;
    gui_obj_show(line_left, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)line_left, 30, true, line_left_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)line_left);

    // 创建 line_right (hg_image)
    line_right = (gui_obj_t *)gui_img_create_from_fs(win_line, "line_right", "/resource/RightLineV1.bin", 69, 0, 375, 417);
    ((gui_img_t *)line_right)->need_clip = true;
    gui_obj_show(line_right, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)line_right, 30, true, line_right_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)line_right);

    // 创建 win_speed (hg_window)
    win_speed = (gui_obj_t *)gui_win_create(win_dail, "win_speed", 38, 64, 295, 294);
    gui_obj_show(win_speed, true);


    // 创建 dail_speed (hg_image)
    dail_speed = (gui_obj_t *)gui_img_create_from_fs(win_speed, "dail_speed", "/resource/dail_speed.bin", 0, 0, 295, 294);
    gui_img_set_mode((gui_img_t *)dail_speed, IMG_SRC_OVER_MODE);
    gui_obj_show(dail_speed, true);

    // 创建 speed_arc (hg_image)
    speed_arc = (gui_obj_t *)gui_img_create_from_fs(win_speed, "speed_arc", "/resource/speed_arc/speed_arc_00.bin", 56, 55, 182, 182);
    gui_img_set_mode((gui_img_t *)speed_arc, IMG_SRC_OVER_MODE);
    gui_obj_show(speed_arc, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)speed_arc, 30, true, speed_arc_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)speed_arc);

    // 创建 dail_pointer_s (hg_image)
    dail_pointer_s = (gui_obj_t *)gui_img_create_from_fs(win_speed, "dail_pointer_s", "/resource/dail_pointer.bin", 144, 212, 4, 25);
    gui_img_set_mode((gui_img_t *)dail_pointer_s, IMG_BYPASS_MODE);
    gui_img_set_quality((gui_img_t *)dail_pointer_s, true);
    gui_img_set_focus((gui_img_t *)dail_pointer_s, 2.0f, -65.0f);
    // 用户自定义平移
    gui_img_translate((gui_img_t *)dail_pointer_s, 2.0f, -65.0f);
    gui_obj_show(dail_pointer_s, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)dail_pointer_s, 30, true, dail_pointer_s_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)dail_pointer_s);

    // 创建 win_power (hg_window)
    win_power = (gui_obj_t *)gui_win_create(win_dail, "win_power", 470, 64, 295, 294);
    gui_obj_show(win_power, true);


    // 创建 dail_power (hg_image)
    dail_power = (gui_obj_t *)gui_img_create_from_fs(win_power, "dail_power", "/resource/dail_power.bin", 0, 0, 295, 294);
    gui_img_set_mode((gui_img_t *)dail_power, IMG_SRC_OVER_MODE);
    gui_obj_show(dail_power, true);

    // 创建 power_arc (hg_image)
    power_arc = (gui_obj_t *)gui_img_create_from_fs(win_power, "power_arc", "/resource/power_arc/power_arc_00.bin", 56, 55, 182, 182);
    gui_img_set_mode((gui_img_t *)power_arc, IMG_SRC_OVER_MODE);
    gui_obj_show(power_arc, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)power_arc, 30, true, power_arc_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)power_arc);

    // 创建 dail_pointer_p (hg_image)
    dail_pointer_p = (gui_obj_t *)gui_img_create_from_fs(win_power, "dail_pointer_p", "/resource/dail_pointer.bin", 144, 212, 4, 25);
    gui_img_set_mode((gui_img_t *)dail_pointer_p, IMG_BYPASS_MODE);
    gui_img_set_quality((gui_img_t *)dail_pointer_p, true);
    gui_img_set_focus((gui_img_t *)dail_pointer_p, 2.0f, -65.0f);
    // 用户自定义平移
    gui_img_translate((gui_img_t *)dail_pointer_p, 2.0f, -65.0f);
    gui_obj_show(dail_pointer_p, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)dail_pointer_p, 30, true, dail_pointer_p_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)dail_pointer_p);

    // 创建 rightbottom_gloom (hg_image)
    rightbottom_gloom = (gui_obj_t *)gui_img_create_from_fs(win_dail, "rightbottom_gloom", "/resource/RightBottomGloomV1.bin", 662, 353, 98, 127);
    gui_obj_show(rightbottom_gloom, true);

    // 创建 leftbottom_gloom (hg_image)
    leftbottom_gloom = (gui_obj_t *)gui_img_create_from_fs(win_dail, "leftbottom_gloom", "/resource/LeftBottomGloomV1.bin", 40, 353, 98, 127);
    gui_obj_show(leftbottom_gloom, true);

    // 创建 win_common (hg_window)
    win_common = (gui_obj_t *)gui_win_create((gui_obj_t *)view, "win_common", 0, 0, 800, 480);
    gui_obj_show(win_common, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)win_common, 20, true, win_common_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_common);


    // 创建 turn_l_icon (hg_image)
    turn_l_icon = (gui_obj_t *)gui_img_create_from_fs(win_common, "turn_l_icon", "/resource/Turnleft_off.bin", 20, 64, 35, 19);
    gui_obj_show(turn_l_icon, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)turn_l_icon, 30, true, turn_l_icon_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)turn_l_icon);

    // 创建 turn_r_icon (hg_image)
    turn_r_icon = (gui_obj_t *)gui_img_create_from_fs(win_common, "turn_r_icon", "/resource/Turnright_off.bin", 745, 64, 35, 19);
    gui_obj_show(turn_r_icon, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)turn_r_icon, 30, true, turn_r_icon_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)turn_r_icon);

    // 创建 off_icon (hg_image)
    off_icon = (gui_obj_t *)gui_img_create_from_fs(win_common, "off_icon", "/resource/OffIcon_release.bin", 746, 23, 20, 20);
    gui_obj_show(off_icon, true);
    gui_obj_add_event_cb(off_icon, (gui_event_cb_t)off_icon_switch_view_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // 创建 switch_icon (hg_image)
    switch_icon = (gui_obj_t *)gui_img_create_from_fs(win_common, "switch_icon", "/resource/SwitchIcon_release.bin", 25, 17, 25, 17);
    gui_obj_show(switch_icon, true);

    // 创建 bt_icon (hg_image)
    bt_icon = (gui_obj_t *)gui_img_create_from_fs(win_common, "bt_icon", "/resource/bt.bin", 294, 52, 14, 20);
    gui_obj_show(bt_icon, true);

    // 创建 wifi_icon (hg_image)
    wifi_icon = (gui_obj_t *)gui_img_create_from_fs(win_common, "wifi_icon", "/resource/wifi.bin", 478, 52, 28, 20);
    gui_obj_show(wifi_icon, true);

    // 创建 text_loc_temp (hg_label)
    text_loc_temp = gui_text_create(win_common, "text_loc_temp", 334, 32, 132, 22);
    gui_text_set((gui_text_t *)text_loc_temp, "Suzhou 25°C", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 12, 22);
    gui_text_type_set((gui_text_t *)text_loc_temp, "//HarmonyOS_Sans_Bold_size22_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_loc_temp, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_loc_temp, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_loc_temp, 0);

    // 创建 text_time (hg_label)
    text_time = gui_text_create(win_common, "text_time", 334, 55, 132, 22);
    gui_text_set((gui_text_t *)text_time, "10:10", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 22);
    gui_text_type_set((gui_text_t *)text_time, "//HarmonyOS_Sans_Bold_size22_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_time, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_time, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_time, 0);
    // 绑定定时器: time update
    gui_obj_create_timer((gui_obj_t *)text_time, 1000, true, text_time_timer_0_cb);

    // 创建 led_0 (hg_image)
    led_0 = (gui_obj_t *)gui_img_create_from_fs(win_common, "led_0", "/resource/LED0_off.bin", 85, 360, 27, 27);
    gui_obj_show(led_0, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)led_0, 30, true, led_0_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_0);

    // 创建 led_1 (hg_image)
    led_1 = (gui_obj_t *)gui_img_create_from_fs(win_common, "led_1", "/resource/LED1_off.bin", 65, 400, 27, 27);
    gui_obj_show(led_1, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)led_1, 30, true, led_1_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_1);

    // 创建 led_2 (hg_image)
    led_2 = (gui_obj_t *)gui_img_create_from_fs(win_common, "led_2", "/resource/LED2_off.bin", 45, 440, 27, 27);
    gui_obj_show(led_2, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)led_2, 30, true, led_2_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_2);

    // 创建 led_3 (hg_image)
    led_3 = (gui_obj_t *)gui_img_create_from_fs(win_common, "led_3", "/resource/LED3_off.bin", 690, 360, 27, 27);
    gui_obj_show(led_3, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)led_3, 30, true, led_3_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_3);

    // 创建 led_4 (hg_image)
    led_4 = (gui_obj_t *)gui_img_create_from_fs(win_common, "led_4", "/resource/LED4_off.bin", 710, 400, 27, 27);
    gui_obj_show(led_4, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)led_4, 30, true, led_4_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_4);

    // 创建 led_5 (hg_image)
    led_5 = (gui_obj_t *)gui_img_create_from_fs(win_common, "led_5", "/resource/LED5_off.bin", 730, 440, 26, 27);
    gui_obj_show(led_5, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)led_5, 30, true, led_5_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_5);

    // 创建 win_speed_text (hg_window)
    win_speed_text = (gui_obj_t *)gui_win_create(win_common, "win_speed_text", 38, 64, 294, 294);
    gui_obj_show(win_speed_text, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)win_speed_text, 10, true, win_speed_text_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_speed_text);


    // 创建 text_speed (hg_label)
    text_speed = gui_text_create(win_speed_text, "text_speed", 0, 106, 294, 40);
    gui_text_set((gui_text_t *)text_speed, "0", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 1, 40);
    gui_text_type_set((gui_text_t *)text_speed, "//HarmonyOS_Sans_Bold_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_speed, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_speed, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_speed, 0);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)text_speed, 30, true, text_speed_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)text_speed);

    // 创建 text_speed_unit (hg_label)
    text_speed_unit = gui_text_create(win_speed_text, "text_speed_unit", 0, 141, 294, 26);
    gui_text_set((gui_text_t *)text_speed_unit, "km/h", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 4, 26);
    gui_text_type_set((gui_text_t *)text_speed_unit, "//HarmonyOS_Sans_SC_Regular_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_speed_unit, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_speed_unit, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_speed_unit, 0);

    // 创建 line (hg_image)
    line = (gui_obj_t *)gui_img_create_from_fs(win_speed_text, "line", "/resource/dividing_line.bin", 96, 168, 101, 2);
    gui_obj_show(line, true);

    // 创建 text_odo (hg_label)
    text_odo = gui_text_create(win_speed_text, "text_odo", 0, 177, 294, 16);
    gui_text_set((gui_text_t *)text_odo, "ODO 300km", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 9, 16);
    gui_text_type_set((gui_text_t *)text_odo, "//HarmonyOS_Sans_Bold_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_odo, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_odo, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_odo, 0);

    // 创建 win_power_text (hg_window)
    win_power_text = (gui_obj_t *)gui_win_create(win_common, "win_power_text", 470, 64, 294, 294);
    gui_obj_show(win_power_text, true);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)win_power_text, 10, true, win_power_text_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_power_text);


    // 创建 text_power (hg_label)
    text_power = gui_text_create(win_power_text, "text_power", 0, 106, 294, 40);
    gui_text_set((gui_text_t *)text_power, "0", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 1, 40);
    gui_text_type_set((gui_text_t *)text_power, "//HarmonyOS_Sans_Bold_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_power, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_power, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_power, 0);
    // 绑定定时器: entrance
    gui_obj_create_timer((gui_obj_t *)text_power, 28, true, text_power_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)text_power);

    // 创建 text_power_unit (hg_label)
    text_power_unit = gui_text_create(win_power_text, "text_power_unit", 0, 141, 294, 26);
    gui_text_set((gui_text_t *)text_power_unit, "kW", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 2, 26);
    gui_text_type_set((gui_text_t *)text_power_unit, "//HarmonyOS_Sans_SC_Regular_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_power_unit, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_power_unit, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_power_unit, 0);

    // 创建 line_copy_1768894235876_3 (hg_image)
    line_copy_1768894235876_3 = (gui_obj_t *)gui_img_create_from_fs(win_power_text, "line_copy_1768894235876_3", "/resource/dividing_line.bin", 96, 168, 101, 2);
    gui_obj_show(line_copy_1768894235876_3, true);

    // 创建 text_battery (hg_label)
    text_battery = gui_text_create(win_power_text, "text_battery", 0, 177, 294, 15);
    gui_text_set((gui_text_t *)text_battery, "BATT 65%", GUI_FONT_SRC_TTF, gui_rgb(255, 255, 255), 8, 16);
    gui_text_type_set((gui_text_t *)text_battery, "//HarmonyOS_Sans_Bold_vector.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_battery, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)text_battery, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)text_battery, 0);
}
GUI_VIEW_INSTANCE("dashboard_view", false, dashboard_view_switch_in, dashboard_view_switch_out);
