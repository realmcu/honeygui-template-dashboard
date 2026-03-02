#include "dashboardMain_callbacks.h"
#include "../ui/dashboardMain_ui.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// 定时动画计数器
uint16_t gloom_timer_cnt = 0;
uint16_t shadow_timer_cnt = 0;
uint16_t win_map_timer_cnt = 0;
uint16_t icon_dir_timer_cnt = 0;
uint16_t map_timer_cnt = 0;
uint16_t root_menu_timer_cnt = 0;
uint16_t win_line_timer_cnt = 0;
uint16_t line_left_timer_cnt = 0;
uint16_t line_right_timer_cnt = 0;
uint16_t win_dail_timer_cnt = 0;
uint16_t speed_arc_timer_cnt = 0;
uint16_t dail_pointer_s_timer_cnt = 0;
uint16_t power_arc_timer_cnt = 0;
uint16_t dail_pointer_p_timer_cnt = 0;
uint16_t win_common_timer_cnt = 0;
uint16_t turn_l_icon_timer_cnt = 0;
uint16_t turn_r_icon_timer_cnt = 0;
uint16_t text_time_timer_cnt = 0;
uint16_t led_0_timer_cnt = 0;
uint16_t led_1_timer_cnt = 0;
uint16_t led_2_timer_cnt = 0;
uint16_t led_3_timer_cnt = 0;
uint16_t led_4_timer_cnt = 0;
uint16_t led_5_timer_cnt = 0;
uint16_t win_speed_text_timer_cnt = 0;
uint16_t text_speed_timer_cnt = 0;
uint16_t win_power_text_timer_cnt = 0;
uint16_t text_power_timer_cnt = 0;
uint16_t win_func_timer_cnt = 0;
uint16_t win_app_list_timer_cnt = 0;
uint16_t app_list_timer_cnt = 0;
uint16_t tab_hightlight_timer_cnt = 0;
uint16_t win_app_weather_timer_cnt = 0;
uint16_t list_weather_timer_cnt = 0;
uint16_t win_app_developing_timer_cnt = 0;

// 事件回调函数实现

void root_menu_switch_view_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
}

void off_icon_switch_view_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
}

void start_engine_pressed_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    shadow_timer_cnt = 0; // 清零计数器
    gui_obj_create_timer(GUI_BASE(shadow), 20, true, shadow_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(shadow));
}

void start_engine_released_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    shadow_timer_cnt = 0; // 清零计数器
    gui_obj_create_timer(GUI_BASE(shadow), 20, true, shadow_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(shadow));
    gloom_timer_cnt = 0; // 清零计数器
    gui_obj_create_timer(GUI_BASE(gloom), 20, true, gloom_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(gloom));
}

void dashboardMainView_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // 检查按键名
    if (strcmp(e->indev_name, "Home") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_TO_LEFT_USE_TRANSLATION, SWITCH_IN_FROM_RIGHT_USE_TRANSLATION);
    }
}

void start_engine_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // 检查按键名
    if (strcmp(e->indev_name, "Power") == 0)
    {
        gloom_timer_cnt = 0; // 清零计数器
        gui_obj_create_timer(GUI_BASE(gloom), 20, true, gloom_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(gloom));
    }
}

void root_menu_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // 检查按键名
    if (strcmp(e->indev_name, "Menu") == 0)
    {
        root_menu_msg_show_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        root_menu_msg_hide_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Home") == 0)
    {
        root_menu_msg_enter_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Power") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
    }
}

void win_app_list_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // 检查按键名
    if (strcmp(e->indev_name, "Home") == 0)
    {
        win_app_list_msg_enter_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        win_app_list_msg_exit_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        win_app_list_msg_next_cb(obj, e);
    }
}

void win_app_weather_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // 检查按键名
    if (strcmp(e->indev_name, "Menu") == 0)
    {
        win_app_weather_msg_next_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        win_app_weather_msg_exit_cb(obj, e);
    }
}

void win_app_developing_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // 检查按键名
    if (strcmp(e->indev_name, "Back") == 0)
    {
        win_app_developing_msg_exit_cb(obj, e);
    }
}

// 预设定时器回调函数

/**
 * exit
 * 组件: gloom
 * 模式: 预设动作（多段动画）
 * 段数: 3
 */
void gloom_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 36;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    const uint16_t seg1_start = 30;
    const uint16_t seg1_end = 35;
    const uint16_t seg2_start = 35;
    const uint16_t seg2_end = 36;
    
    gloom_timer_cnt++;
    
    // 段 1: 600ms, 1 个动作
    if (gloom_timer_cnt > seg0_start && gloom_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = gloom_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整透明度: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // 段 2: 等待 100ms
    else if (gloom_timer_cnt > seg1_start && gloom_timer_cnt <= seg1_end) {
        // 无动作，仅等待
    }
    // 段 3: 20ms, 1 个动作
    else if (gloom_timer_cnt > seg2_start && gloom_timer_cnt <= seg2_end) {
            // 跳转界面: dashboard_view
            gui_view_switch_direct(gui_view_get_current(), "dashboard_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
            
    }
    
    if (gloom_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        gloom_timer_cnt = 0; // 重置计数器
    }
}


/**
 * press
 * 组件: shadow
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void shadow_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    shadow_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (shadow_timer_cnt > seg0_start && shadow_timer_cnt <= seg0_end) {
            // 更换图片: /resource/Start_Engine_Press.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Start_Engine_Press.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (shadow_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        shadow_timer_cnt = 0; // 重置计数器
    }
}


/**
 * release
 * 组件: shadow
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void shadow_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    shadow_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (shadow_timer_cnt > seg0_start && shadow_timer_cnt <= seg0_end) {
            // 更换图片: /resource/Start_Engine_Release.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Start_Engine_Release.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (shadow_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        shadow_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: win_map
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_map_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_map_timer_cnt++;
    
    // 段 1: 6000ms, 1 个动作
    if (win_map_timer_cnt > seg0_start && win_map_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (win_map_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_map_timer_cnt = 0; // 重置计数器
    }
}


/**
 * show map
 * 组件: win_map
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_map_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_map_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_map_timer_cnt > seg0_start && win_map_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (win_map_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_map_timer_cnt = 0; // 重置计数器
    }
}


/**
 * hide map
 * 组件: win_map
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_map_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_map_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_map_timer_cnt > seg0_start && win_map_timer_cnt <= seg0_end) {
            // 设置可见性: 隐藏
            gui_obj_show(target, false);
            
    }
    
    if (win_map_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_map_timer_cnt = 0; // 重置计数器
    }
}


/**
 * dir update
 * 组件: icon_dir
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void icon_dir_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 13;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 13;
    
    icon_dir_timer_cnt++;
    
    // 段 1: 13000ms, 1 个动作
    if (icon_dir_timer_cnt > seg0_start && icon_dir_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = icon_dir_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 13 张图片
            const void *img_data_array[13] = {
                "/resource/arrow_direct.bin",
                "/resource/arrow_direct.bin",
                "/resource/arrow_direct.bin",
                "/resource/arrow_direct.bin",
                "/resource/Arrow_right.bin",
                "/resource/Arrow_right.bin",
                "/resource/arrow_direct.bin",
                "/resource/arrow_direct.bin",
                "/resource/Arrow_right.bin",
                "/resource/Arrow_left.bin",
                "/resource/Arrow_right.bin",
                "/resource/Arrow_left.bin",
                "/resource/arrow_direct.bin"
            };
            uint16_t index = (13 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (icon_dir_timer_cnt >= total_cnt_max) {
        icon_dir_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * map array
 * 组件: map
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void map_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 13;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 13;
    
    map_timer_cnt++;
    
    // 段 1: 13000ms, 1 个动作
    if (map_timer_cnt > seg0_start && map_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = map_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 13 张图片
            const void *img_data_array[13] = {
                "/resource/map/map_00.bin",
                "/resource/map/map_01.bin",
                "/resource/map/map_02.bin",
                "/resource/map/map_03.bin",
                "/resource/map/map_04.bin",
                "/resource/map/map_05.bin",
                "/resource/map/map_06.bin",
                "/resource/map/map_07.bin",
                "/resource/map/map_08.bin",
                "/resource/map/map_09.bin",
                "/resource/map/map_10.bin",
                "/resource/map/map_11.bin",
                "/resource/map/map_12.bin"
            };
            uint16_t index = (13 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (map_timer_cnt >= total_cnt_max) {
        map_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * entrance
 * 组件: map
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void map_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    map_timer_cnt++;
    
    // 段 1: 6000ms, 1 个动作
    if (map_timer_cnt > seg0_start && map_timer_cnt <= seg0_end) {
            // 切换定时动画: map array
            map_timer_cnt = 0; // 清零计数器
            gui_obj_create_timer(target, 1000, true, map_timer_0_cb);
            gui_obj_start_timer(target);
            return; // 切换定时动画后立即返回
            
    }
    
    if (map_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        map_timer_cnt = 0; // 重置计数器
    }
}


/**
 * menu array
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 120;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 120;
    
    root_menu_timer_cnt++;
    
    // 段 1: 2400ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 60 张图片
            const void *img_data_array[60] = {
                "/resource/menu/menu_001.bin",
                "/resource/menu/menu_002.bin",
                "/resource/menu/menu_003.bin",
                "/resource/menu/menu_004.bin",
                "/resource/menu/menu_005.bin",
                "/resource/menu/menu_006.bin",
                "/resource/menu/menu_007.bin",
                "/resource/menu/menu_008.bin",
                "/resource/menu/menu_009.bin",
                "/resource/menu/menu_010.bin",
                "/resource/menu/menu_011.bin",
                "/resource/menu/menu_012.bin",
                "/resource/menu/menu_013.bin",
                "/resource/menu/menu_014.bin",
                "/resource/menu/menu_015.bin",
                "/resource/menu/menu_016.bin",
                "/resource/menu/menu_017.bin",
                "/resource/menu/menu_018.bin",
                "/resource/menu/menu_019.bin",
                "/resource/menu/menu_020.bin",
                "/resource/menu/menu_021.bin",
                "/resource/menu/menu_022.bin",
                "/resource/menu/menu_023.bin",
                "/resource/menu/menu_024.bin",
                "/resource/menu/menu_025.bin",
                "/resource/menu/menu_026.bin",
                "/resource/menu/menu_027.bin",
                "/resource/menu/menu_028.bin",
                "/resource/menu/menu_029.bin",
                "/resource/menu/menu_030.bin",
                "/resource/menu/menu_031.bin",
                "/resource/menu/menu_032.bin",
                "/resource/menu/menu_033.bin",
                "/resource/menu/menu_034.bin",
                "/resource/menu/menu_035.bin",
                "/resource/menu/menu_036.bin",
                "/resource/menu/menu_037.bin",
                "/resource/menu/menu_038.bin",
                "/resource/menu/menu_039.bin",
                "/resource/menu/menu_040.bin",
                "/resource/menu/menu_041.bin",
                "/resource/menu/menu_042.bin",
                "/resource/menu/menu_043.bin",
                "/resource/menu/menu_044.bin",
                "/resource/menu/menu_045.bin",
                "/resource/menu/menu_046.bin",
                "/resource/menu/menu_047.bin",
                "/resource/menu/menu_048.bin",
                "/resource/menu/menu_049.bin",
                "/resource/menu/menu_050.bin",
                "/resource/menu/menu_051.bin",
                "/resource/menu/menu_052.bin",
                "/resource/menu/menu_053.bin",
                "/resource/menu/menu_054.bin",
                "/resource/menu/menu_055.bin",
                "/resource/menu/menu_056.bin",
                "/resource/menu/menu_057.bin",
                "/resource/menu/menu_058.bin",
                "/resource/menu/menu_059.bin",
                "/resource/menu/menu_060.bin"
            };
            uint16_t index = (60 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        root_menu_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * move up
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 30;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    
    root_menu_timer_cnt++;
    
    // 段 1: 300ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (225, 480) -> (225, 293)
            const int16_t x_origin = 225;
            const int16_t y_origin = 480;
            const int16_t x_target = 225;
            const int16_t y_target = 293;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * move down
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 30;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    
    root_menu_timer_cnt++;
    
    // 段 1: 300ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (225, 293) -> (225, 480)
            const int16_t x_origin = 225;
            const int16_t y_origin = 293;
            const int16_t x_target = 225;
            const int16_t y_target = 480;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 1 to 2
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_3_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // 段 1: 300ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 15 张图片
            const void *img_data_array[15] = {
                "/resource/menu/menu_001.bin",
                "/resource/menu/menu_002.bin",
                "/resource/menu/menu_003.bin",
                "/resource/menu/menu_004.bin",
                "/resource/menu/menu_005.bin",
                "/resource/menu/menu_006.bin",
                "/resource/menu/menu_007.bin",
                "/resource/menu/menu_008.bin",
                "/resource/menu/menu_009.bin",
                "/resource/menu/menu_010.bin",
                "/resource/menu/menu_011.bin",
                "/resource/menu/menu_012.bin",
                "/resource/menu/menu_013.bin",
                "/resource/menu/menu_014.bin",
                "/resource/menu/menu_015.bin"
            };
            uint16_t index = (15 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 2 to 3
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_4_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // 段 1: 300ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 15 张图片
            const void *img_data_array[15] = {
                "/resource/menu/menu_016.bin",
                "/resource/menu/menu_017.bin",
                "/resource/menu/menu_018.bin",
                "/resource/menu/menu_019.bin",
                "/resource/menu/menu_020.bin",
                "/resource/menu/menu_021.bin",
                "/resource/menu/menu_022.bin",
                "/resource/menu/menu_023.bin",
                "/resource/menu/menu_024.bin",
                "/resource/menu/menu_025.bin",
                "/resource/menu/menu_026.bin",
                "/resource/menu/menu_027.bin",
                "/resource/menu/menu_028.bin",
                "/resource/menu/menu_029.bin",
                "/resource/menu/menu_030.bin"
            };
            uint16_t index = (15 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 3 to 4
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_5_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // 段 1: 300ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 15 张图片
            const void *img_data_array[15] = {
                "/resource/menu/menu_031.bin",
                "/resource/menu/menu_032.bin",
                "/resource/menu/menu_033.bin",
                "/resource/menu/menu_034.bin",
                "/resource/menu/menu_035.bin",
                "/resource/menu/menu_036.bin",
                "/resource/menu/menu_037.bin",
                "/resource/menu/menu_038.bin",
                "/resource/menu/menu_039.bin",
                "/resource/menu/menu_040.bin",
                "/resource/menu/menu_041.bin",
                "/resource/menu/menu_042.bin",
                "/resource/menu/menu_043.bin",
                "/resource/menu/menu_044.bin",
                "/resource/menu/menu_045.bin"
            };
            uint16_t index = (15 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 4 to 1
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_6_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // 段 1: 299ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 15 张图片
            const void *img_data_array[15] = {
                "/resource/menu/menu_046.bin",
                "/resource/menu/menu_047.bin",
                "/resource/menu/menu_048.bin",
                "/resource/menu/menu_049.bin",
                "/resource/menu/menu_050.bin",
                "/resource/menu/menu_051.bin",
                "/resource/menu/menu_052.bin",
                "/resource/menu/menu_053.bin",
                "/resource/menu/menu_054.bin",
                "/resource/menu/menu_055.bin",
                "/resource/menu/menu_056.bin",
                "/resource/menu/menu_057.bin",
                "/resource/menu/menu_058.bin",
                "/resource/menu/menu_059.bin",
                "/resource/menu/menu_060.bin"
            };
            uint16_t index = (15 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 1 to 4
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_7_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // 段 1: 280ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 14 张图片
            const void *img_data_array[14] = {
                "/resource/menu/menu_060.bin",
                "/resource/menu/menu_059.bin",
                "/resource/menu/menu_058.bin",
                "/resource/menu/menu_057.bin",
                "/resource/menu/menu_056.bin",
                "/resource/menu/menu_055.bin",
                "/resource/menu/menu_054.bin",
                "/resource/menu/menu_053.bin",
                "/resource/menu/menu_052.bin",
                "/resource/menu/menu_051.bin",
                "/resource/menu/menu_050.bin",
                "/resource/menu/menu_049.bin",
                "/resource/menu/menu_048.bin",
                "/resource/menu/menu_047.bin"
            };
            uint16_t index = (14 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 4 to 3
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_8_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // 段 1: 280ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 14 张图片
            const void *img_data_array[14] = {
                "/resource/menu/menu_045.bin",
                "/resource/menu/menu_044.bin",
                "/resource/menu/menu_043.bin",
                "/resource/menu/menu_042.bin",
                "/resource/menu/menu_041.bin",
                "/resource/menu/menu_040.bin",
                "/resource/menu/menu_039.bin",
                "/resource/menu/menu_038.bin",
                "/resource/menu/menu_037.bin",
                "/resource/menu/menu_036.bin",
                "/resource/menu/menu_035.bin",
                "/resource/menu/menu_034.bin",
                "/resource/menu/menu_033.bin",
                "/resource/menu/menu_032.bin"
            };
            uint16_t index = (14 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 3 to 2
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_9_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // 段 1: 280ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 14 张图片
            const void *img_data_array[14] = {
                "/resource/menu/menu_030.bin",
                "/resource/menu/menu_029.bin",
                "/resource/menu/menu_028.bin",
                "/resource/menu/menu_027.bin",
                "/resource/menu/menu_026.bin",
                "/resource/menu/menu_025.bin",
                "/resource/menu/menu_024.bin",
                "/resource/menu/menu_023.bin",
                "/resource/menu/menu_022.bin",
                "/resource/menu/menu_021.bin",
                "/resource/menu/menu_020.bin",
                "/resource/menu/menu_019.bin",
                "/resource/menu/menu_018.bin",
                "/resource/menu/menu_017.bin"
            };
            uint16_t index = (14 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * 2 to 1
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_10_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // 段 1: 280ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 14 张图片
            const void *img_data_array[14] = {
                "/resource/menu/menu_015.bin",
                "/resource/menu/menu_014.bin",
                "/resource/menu/menu_013.bin",
                "/resource/menu/menu_012.bin",
                "/resource/menu/menu_011.bin",
                "/resource/menu/menu_010.bin",
                "/resource/menu/menu_009.bin",
                "/resource/menu/menu_008.bin",
                "/resource/menu/menu_007.bin",
                "/resource/menu/menu_006.bin",
                "/resource/menu/menu_005.bin",
                "/resource/menu/menu_004.bin",
                "/resource/menu/menu_003.bin",
                "/resource/menu/menu_002.bin"
            };
            uint16_t index = (14 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * set focus
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_11_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    root_menu_timer_cnt++;
    
    // 段 1: 10ms, 1 个动作
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
            // 设置焦点
            gui_obj_focus_set(target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: win_line
 * 模式: 预设动作（多段动画）
 * 段数: 2
 */
void win_line_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 62;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    const uint16_t seg1_start = 30;
    const uint16_t seg1_end = 62;
    
    win_line_timer_cnt++;
    
    // 段 1: 900ms, 2 个动作
    if (win_line_timer_cnt > seg0_start && win_line_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_line_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整大小: (138, 100) -> (750, 100)
            const int16_t w_origin = 138;
            const int16_t h_origin = 100;
            const int16_t w_target = 750;
            const int16_t h_target = 100;
            int16_t w_cur = w_origin + (w_target - w_origin) * seg_cnt / seg_cnt_max;
            int16_t h_cur = h_origin + (h_target - h_origin) * seg_cnt / seg_cnt_max;
            target->w = w_cur;
            target->h = h_cur;
            
            // 调整位置: (331, 53) -> (25, 53)
            const int16_t x_origin = 331;
            const int16_t y_origin = 53;
            const int16_t x_target = 25;
            const int16_t y_target = 53;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    // 段 2: 960ms, 1 个动作
    else if (win_line_timer_cnt > seg1_start && win_line_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = win_line_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 调整大小: (750, 100) -> (750, 417)
            const int16_t w_origin = 750;
            const int16_t h_origin = 100;
            const int16_t w_target = 750;
            const int16_t h_target = 417;
            int16_t w_cur = w_origin + (w_target - w_origin) * seg_cnt / seg_cnt_max;
            int16_t h_cur = h_origin + (h_target - h_origin) * seg_cnt / seg_cnt_max;
            target->w = w_cur;
            target->h = h_cur;
            
    }
    
    if (win_line_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_line_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: line_left
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void line_left_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 30;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    
    line_left_timer_cnt++;
    
    // 段 1: 900ms, 1 个动作
    if (line_left_timer_cnt > seg0_start && line_left_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = line_left_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (-306, 0) -> (0, 0)
            const int16_t x_origin = -306;
            const int16_t y_origin = 0;
            const int16_t x_target = 0;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (line_left_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        line_left_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: line_right
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void line_right_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 30;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    
    line_right_timer_cnt++;
    
    // 段 1: 900ms, 1 个动作
    if (line_right_timer_cnt > seg0_start && line_right_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = line_right_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (69, 0) -> (375, 0)
            const int16_t x_origin = 69;
            const int16_t y_origin = 0;
            const int16_t x_target = 375;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (line_right_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        line_right_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: win_dail
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_dail_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 143;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 143;
    
    win_dail_timer_cnt++;
    
    // 段 1: 1000ms, 1 个动作
    if (win_dail_timer_cnt > seg0_start && win_dail_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_dail_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整透明度: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            target->opacity_value = opacity_cur;
            
    }
    
    if (win_dail_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_dail_timer_cnt = 0; // 重置计数器
    }
}


/**
 * show
 * 组件: win_dail
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_dail_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_dail_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_dail_timer_cnt > seg0_start && win_dail_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (win_dail_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_dail_timer_cnt = 0; // 重置计数器
    }
}


/**
 * hide
 * 组件: win_dail
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_dail_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_dail_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_dail_timer_cnt > seg0_start && win_dail_timer_cnt <= seg0_end) {
            // 设置可见性: 隐藏
            gui_obj_show(target, false);
            
    }
    
    if (win_dail_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_dail_timer_cnt = 0; // 重置计数器
    }
}


/**
 * arc_animate
 * 组件: speed_arc
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void speed_arc_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    speed_arc_timer_cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (speed_arc_timer_cnt > seg0_start && speed_arc_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = speed_arc_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 16 张图片
            const void *img_data_array[16] = {
                "/resource/speed_arc/speed_arc_01.bin",
                "/resource/speed_arc/speed_arc_02.bin",
                "/resource/speed_arc/speed_arc_03.bin",
                "/resource/speed_arc/speed_arc_04.bin",
                "/resource/speed_arc/speed_arc_05.bin",
                "/resource/speed_arc/speed_arc_06.bin",
                "/resource/speed_arc/speed_arc_07.bin",
                "/resource/speed_arc/speed_arc_08.bin",
                "/resource/speed_arc/speed_arc_09.bin",
                "/resource/speed_arc/speed_arc_10.bin",
                "/resource/speed_arc/speed_arc_11.bin",
                "/resource/speed_arc/speed_arc_12.bin",
                "/resource/speed_arc/speed_arc_13.bin",
                "/resource/speed_arc/speed_arc_14.bin",
                "/resource/speed_arc/speed_arc_15.bin",
                "/resource/speed_arc/speed_arc_00.bin"
            };
            uint16_t index = (16 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (speed_arc_timer_cnt >= total_cnt_max) {
        speed_arc_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * entrance
 * 组件: speed_arc
 * 模式: 预设动作（多段动画）
 * 段数: 5
 */
void speed_arc_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 164;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 97;
    const uint16_t seg1_start = 97;
    const uint16_t seg1_end = 113;
    const uint16_t seg2_start = 113;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 163;
    const uint16_t seg4_start = 163;
    const uint16_t seg4_end = 164;
    
    speed_arc_timer_cnt++;
    
    // 段 1: 等待 2900ms
    if (speed_arc_timer_cnt > seg0_start && speed_arc_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (speed_arc_timer_cnt > seg1_start && speed_arc_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = speed_arc_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 图片序列动画: 16 张图片
            const void *img_data_array[16] = {
                "/resource/speed_arc/speed_arc_01.bin",
                "/resource/speed_arc/speed_arc_02.bin",
                "/resource/speed_arc/speed_arc_03.bin",
                "/resource/speed_arc/speed_arc_04.bin",
                "/resource/speed_arc/speed_arc_05.bin",
                "/resource/speed_arc/speed_arc_06.bin",
                "/resource/speed_arc/speed_arc_07.bin",
                "/resource/speed_arc/speed_arc_08.bin",
                "/resource/speed_arc/speed_arc_09.bin",
                "/resource/speed_arc/speed_arc_10.bin",
                "/resource/speed_arc/speed_arc_11.bin",
                "/resource/speed_arc/speed_arc_12.bin",
                "/resource/speed_arc/speed_arc_13.bin",
                "/resource/speed_arc/speed_arc_14.bin",
                "/resource/speed_arc/speed_arc_15.bin",
                "/resource/speed_arc/speed_arc_16.bin"
            };
            uint16_t index = (16 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (speed_arc_timer_cnt > seg2_start && speed_arc_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = speed_arc_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // 图片序列动画: 16 张图片
            const void *img_data_array[16] = {
                "/resource/speed_arc/speed_arc_15.bin",
                "/resource/speed_arc/speed_arc_14.bin",
                "/resource/speed_arc/speed_arc_13.bin",
                "/resource/speed_arc/speed_arc_12.bin",
                "/resource/speed_arc/speed_arc_11.bin",
                "/resource/speed_arc/speed_arc_10.bin",
                "/resource/speed_arc/speed_arc_09.bin",
                "/resource/speed_arc/speed_arc_08.bin",
                "/resource/speed_arc/speed_arc_07.bin",
                "/resource/speed_arc/speed_arc_06.bin",
                "/resource/speed_arc/speed_arc_05.bin",
                "/resource/speed_arc/speed_arc_04.bin",
                "/resource/speed_arc/speed_arc_03.bin",
                "/resource/speed_arc/speed_arc_02.bin",
                "/resource/speed_arc/speed_arc_01.bin",
                "/resource/speed_arc/speed_arc_00.bin"
            };
            uint16_t index = (16 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 等待 1000ms
    else if (speed_arc_timer_cnt > seg3_start && speed_arc_timer_cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (speed_arc_timer_cnt > seg4_start && speed_arc_timer_cnt <= seg4_end) {
            // 切换定时动画: arc_animate
            speed_arc_timer_cnt = 0; // 清零计数器
            gui_obj_create_timer(target, 100, true, speed_arc_timer_0_cb);
            gui_obj_start_timer(target);
            return; // 切换定时动画后立即返回
            
    }
    
    if (speed_arc_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        speed_arc_timer_cnt = 0; // 重置计数器
    }
}


/**
 * rotate
 * 组件: dail_pointer_s
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void dail_pointer_s_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    dail_pointer_s_timer_cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (dail_pointer_s_timer_cnt > seg0_start && dail_pointer_s_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = dail_pointer_s_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整旋转: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    
    if (dail_pointer_s_timer_cnt >= total_cnt_max) {
        dail_pointer_s_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * entrance
 * 组件: dail_pointer_s
 * 模式: 预设动作（多段动画）
 * 段数: 5
 */
void dail_pointer_s_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 164;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 97;
    const uint16_t seg1_start = 97;
    const uint16_t seg1_end = 113;
    const uint16_t seg2_start = 113;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 163;
    const uint16_t seg4_start = 163;
    const uint16_t seg4_end = 164;
    
    dail_pointer_s_timer_cnt++;
    
    // 段 1: 等待 2900ms
    if (dail_pointer_s_timer_cnt > seg0_start && dail_pointer_s_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (dail_pointer_s_timer_cnt > seg1_start && dail_pointer_s_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = dail_pointer_s_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 调整旋转: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (dail_pointer_s_timer_cnt > seg2_start && dail_pointer_s_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = dail_pointer_s_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // 调整旋转: 720° -> 360°
            const float angle_origin = 720;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 4: 等待 1000ms
    else if (dail_pointer_s_timer_cnt > seg3_start && dail_pointer_s_timer_cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (dail_pointer_s_timer_cnt > seg4_start && dail_pointer_s_timer_cnt <= seg4_end) {
            // 切换定时动画: rotate
            dail_pointer_s_timer_cnt = 0; // 清零计数器
            gui_obj_create_timer(target, 100, true, dail_pointer_s_timer_0_cb);
            gui_obj_start_timer(target);
            return; // 切换定时动画后立即返回
            
    }
    
    if (dail_pointer_s_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        dail_pointer_s_timer_cnt = 0; // 重置计数器
    }
}


/**
 * arc_animate
 * 组件: power_arc
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void power_arc_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    power_arc_timer_cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (power_arc_timer_cnt > seg0_start && power_arc_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = power_arc_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 图片序列动画: 16 张图片
            const void *img_data_array[16] = {
                "/resource/power_arc/power_arc_01.bin",
                "/resource/power_arc/power_arc_02.bin",
                "/resource/power_arc/power_arc_03.bin",
                "/resource/power_arc/power_arc_04.bin",
                "/resource/power_arc/power_arc_05.bin",
                "/resource/power_arc/power_arc_06.bin",
                "/resource/power_arc/power_arc_07.bin",
                "/resource/power_arc/power_arc_08.bin",
                "/resource/power_arc/power_arc_09.bin",
                "/resource/power_arc/power_arc_10.bin",
                "/resource/power_arc/power_arc_11.bin",
                "/resource/power_arc/power_arc_12.bin",
                "/resource/power_arc/power_arc_13.bin",
                "/resource/power_arc/power_arc_14.bin",
                "/resource/power_arc/power_arc_15.bin",
                "/resource/power_arc/power_arc_00.bin"
            };
            uint16_t index = (16 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (power_arc_timer_cnt >= total_cnt_max) {
        power_arc_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * entrance
 * 组件: power_arc
 * 模式: 预设动作（多段动画）
 * 段数: 5
 */
void power_arc_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 164;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 97;
    const uint16_t seg1_start = 97;
    const uint16_t seg1_end = 113;
    const uint16_t seg2_start = 113;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 163;
    const uint16_t seg4_start = 163;
    const uint16_t seg4_end = 164;
    
    power_arc_timer_cnt++;
    
    // 段 1: 等待 2900ms
    if (power_arc_timer_cnt > seg0_start && power_arc_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (power_arc_timer_cnt > seg1_start && power_arc_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = power_arc_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 图片序列动画: 16 张图片
            const void *img_data_array[16] = {
                "/resource/power_arc/power_arc_01.bin",
                "/resource/power_arc/power_arc_02.bin",
                "/resource/power_arc/power_arc_03.bin",
                "/resource/power_arc/power_arc_04.bin",
                "/resource/power_arc/power_arc_05.bin",
                "/resource/power_arc/power_arc_06.bin",
                "/resource/power_arc/power_arc_07.bin",
                "/resource/power_arc/power_arc_08.bin",
                "/resource/power_arc/power_arc_09.bin",
                "/resource/power_arc/power_arc_10.bin",
                "/resource/power_arc/power_arc_11.bin",
                "/resource/power_arc/power_arc_12.bin",
                "/resource/power_arc/power_arc_13.bin",
                "/resource/power_arc/power_arc_14.bin",
                "/resource/power_arc/power_arc_15.bin",
                "/resource/power_arc/power_arc_16.bin"
            };
            uint16_t index = (16 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (power_arc_timer_cnt > seg2_start && power_arc_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = power_arc_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // 图片序列动画: 16 张图片
            const void *img_data_array[16] = {
                "/resource/power_arc/power_arc_15.bin",
                "/resource/power_arc/power_arc_14.bin",
                "/resource/power_arc/power_arc_13.bin",
                "/resource/power_arc/power_arc_12.bin",
                "/resource/power_arc/power_arc_11.bin",
                "/resource/power_arc/power_arc_10.bin",
                "/resource/power_arc/power_arc_09.bin",
                "/resource/power_arc/power_arc_08.bin",
                "/resource/power_arc/power_arc_07.bin",
                "/resource/power_arc/power_arc_06.bin",
                "/resource/power_arc/power_arc_05.bin",
                "/resource/power_arc/power_arc_04.bin",
                "/resource/power_arc/power_arc_03.bin",
                "/resource/power_arc/power_arc_02.bin",
                "/resource/power_arc/power_arc_01.bin",
                "/resource/power_arc/power_arc_00.bin"
            };
            uint16_t index = (16 - 1) * seg_cnt / seg_cnt_max;
            gui_img_set_src((gui_img_t *)target, img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 等待 1000ms
    else if (power_arc_timer_cnt > seg3_start && power_arc_timer_cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (power_arc_timer_cnt > seg4_start && power_arc_timer_cnt <= seg4_end) {
            // 切换定时动画: arc_animate
            power_arc_timer_cnt = 0; // 清零计数器
            gui_obj_create_timer(target, 100, true, power_arc_timer_0_cb);
            gui_obj_start_timer(target);
            return; // 切换定时动画后立即返回
            
    }
    
    if (power_arc_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        power_arc_timer_cnt = 0; // 重置计数器
    }
}


/**
 * rotate
 * 组件: dail_pointer_p
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void dail_pointer_p_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    dail_pointer_p_timer_cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (dail_pointer_p_timer_cnt > seg0_start && dail_pointer_p_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = dail_pointer_p_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整旋转: 0° -> -360°
            const float angle_origin = 0;
            const float angle_target = -360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    
    if (dail_pointer_p_timer_cnt >= total_cnt_max) {
        dail_pointer_p_timer_cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * entrance
 * 组件: dail_pointer_p
 * 模式: 预设动作（多段动画）
 * 段数: 5
 */
void dail_pointer_p_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 164;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 97;
    const uint16_t seg1_start = 97;
    const uint16_t seg1_end = 113;
    const uint16_t seg2_start = 113;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 163;
    const uint16_t seg4_start = 163;
    const uint16_t seg4_end = 164;
    
    dail_pointer_p_timer_cnt++;
    
    // 段 1: 等待 2900ms
    if (dail_pointer_p_timer_cnt > seg0_start && dail_pointer_p_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (dail_pointer_p_timer_cnt > seg1_start && dail_pointer_p_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = dail_pointer_p_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 调整旋转: 0° -> -360°
            const float angle_origin = 0;
            const float angle_target = -360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (dail_pointer_p_timer_cnt > seg2_start && dail_pointer_p_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = dail_pointer_p_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // 调整旋转: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 4: 等待 1000ms
    else if (dail_pointer_p_timer_cnt > seg3_start && dail_pointer_p_timer_cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (dail_pointer_p_timer_cnt > seg4_start && dail_pointer_p_timer_cnt <= seg4_end) {
            // 切换定时动画: rotate
            dail_pointer_p_timer_cnt = 0; // 清零计数器
            gui_obj_create_timer(target, 100, true, dail_pointer_p_timer_0_cb);
            gui_obj_start_timer(target);
            return; // 切换定时动画后立即返回
            
    }
    
    if (dail_pointer_p_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        dail_pointer_p_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: win_common
 * 模式: 预设动作（多段动画）
 * 段数: 2
 */
void win_common_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 100;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 99;
    const uint16_t seg1_start = 99;
    const uint16_t seg1_end = 100;
    
    win_common_timer_cnt++;
    
    // 段 1: 等待 1980ms
    if (win_common_timer_cnt > seg0_start && win_common_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 20ms, 1 个动作
    else if (win_common_timer_cnt > seg1_start && win_common_timer_cnt <= seg1_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (win_common_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_common_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: turn_l_icon
 * 模式: 预设动作（多段动画）
 * 段数: 8
 */
void turn_l_icon_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 159;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 67;
    const uint16_t seg1_start = 67;
    const uint16_t seg1_end = 77;
    const uint16_t seg2_start = 77;
    const uint16_t seg2_end = 87;
    const uint16_t seg3_start = 87;
    const uint16_t seg3_end = 97;
    const uint16_t seg4_start = 97;
    const uint16_t seg4_end = 129;
    const uint16_t seg5_start = 129;
    const uint16_t seg5_end = 139;
    const uint16_t seg6_start = 139;
    const uint16_t seg6_end = 149;
    const uint16_t seg7_start = 149;
    const uint16_t seg7_end = 159;
    
    turn_l_icon_timer_cnt++;
    
    // 段 1: 等待 2000ms
    if (turn_l_icon_timer_cnt > seg0_start && turn_l_icon_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (turn_l_icon_timer_cnt > seg1_start && turn_l_icon_timer_cnt <= seg1_end) {
            // 更换图片: /resource/Turnleft_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnleft_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 300ms, 1 个动作
    else if (turn_l_icon_timer_cnt > seg2_start && turn_l_icon_timer_cnt <= seg2_end) {
            // 更换图片: /resource/Turnleft_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnleft_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 300ms, 1 个动作
    else if (turn_l_icon_timer_cnt > seg3_start && turn_l_icon_timer_cnt <= seg3_end) {
            // 更换图片: /resource/Turnleft_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnleft_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 5: 等待 960ms
    else if (turn_l_icon_timer_cnt > seg4_start && turn_l_icon_timer_cnt <= seg4_end) {
        // 无动作，仅等待
    }
    // 段 6: 300ms, 1 个动作
    else if (turn_l_icon_timer_cnt > seg5_start && turn_l_icon_timer_cnt <= seg5_end) {
            // 更换图片: /resource/Turnleft_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnleft_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 7: 300ms, 1 个动作
    else if (turn_l_icon_timer_cnt > seg6_start && turn_l_icon_timer_cnt <= seg6_end) {
            // 更换图片: /resource/Turnleft_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnleft_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 8: 300ms, 1 个动作
    else if (turn_l_icon_timer_cnt > seg7_start && turn_l_icon_timer_cnt <= seg7_end) {
            // 更换图片: /resource/Turnleft_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnleft_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (turn_l_icon_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        turn_l_icon_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: turn_r_icon
 * 模式: 预设动作（多段动画）
 * 段数: 8
 */
void turn_r_icon_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 159;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 67;
    const uint16_t seg1_start = 67;
    const uint16_t seg1_end = 77;
    const uint16_t seg2_start = 77;
    const uint16_t seg2_end = 87;
    const uint16_t seg3_start = 87;
    const uint16_t seg3_end = 97;
    const uint16_t seg4_start = 97;
    const uint16_t seg4_end = 129;
    const uint16_t seg5_start = 129;
    const uint16_t seg5_end = 139;
    const uint16_t seg6_start = 139;
    const uint16_t seg6_end = 149;
    const uint16_t seg7_start = 149;
    const uint16_t seg7_end = 159;
    
    turn_r_icon_timer_cnt++;
    
    // 段 1: 等待 2000ms
    if (turn_r_icon_timer_cnt > seg0_start && turn_r_icon_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (turn_r_icon_timer_cnt > seg1_start && turn_r_icon_timer_cnt <= seg1_end) {
            // 更换图片: /resource/Turnright_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnright_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 300ms, 1 个动作
    else if (turn_r_icon_timer_cnt > seg2_start && turn_r_icon_timer_cnt <= seg2_end) {
            // 更换图片: /resource/Turnright_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnright_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 300ms, 1 个动作
    else if (turn_r_icon_timer_cnt > seg3_start && turn_r_icon_timer_cnt <= seg3_end) {
            // 更换图片: /resource/Turnright_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnright_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 5: 等待 960ms
    else if (turn_r_icon_timer_cnt > seg4_start && turn_r_icon_timer_cnt <= seg4_end) {
        // 无动作，仅等待
    }
    // 段 6: 300ms, 1 个动作
    else if (turn_r_icon_timer_cnt > seg5_start && turn_r_icon_timer_cnt <= seg5_end) {
            // 更换图片: /resource/Turnright_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnright_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 7: 300ms, 1 个动作
    else if (turn_r_icon_timer_cnt > seg6_start && turn_r_icon_timer_cnt <= seg6_end) {
            // 更换图片: /resource/Turnright_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnright_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 8: 300ms, 1 个动作
    else if (turn_r_icon_timer_cnt > seg7_start && turn_r_icon_timer_cnt <= seg7_end) {
            // 更换图片: /resource/Turnright_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/Turnright_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (turn_r_icon_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        turn_r_icon_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: led_0
 * 模式: 预设动作（多段动画）
 * 段数: 4
 */
void led_0_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 139;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 87;
    const uint16_t seg1_start = 87;
    const uint16_t seg1_end = 97;
    const uint16_t seg2_start = 97;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 139;
    
    led_0_timer_cnt++;
    
    // 段 1: 等待 2600ms
    if (led_0_timer_cnt > seg0_start && led_0_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (led_0_timer_cnt > seg1_start && led_0_timer_cnt <= seg1_end) {
            // 更换图片: /resource/LED0_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED0_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 960ms
    else if (led_0_timer_cnt > seg2_start && led_0_timer_cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (led_0_timer_cnt > seg3_start && led_0_timer_cnt <= seg3_end) {
            // 更换图片: /resource/LED0_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED0_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_0_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_0_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: led_1
 * 模式: 预设动作（多段动画）
 * 段数: 4
 */
void led_1_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 149;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 77;
    const uint16_t seg1_start = 77;
    const uint16_t seg1_end = 87;
    const uint16_t seg2_start = 87;
    const uint16_t seg2_end = 139;
    const uint16_t seg3_start = 139;
    const uint16_t seg3_end = 149;
    
    led_1_timer_cnt++;
    
    // 段 1: 等待 2300ms
    if (led_1_timer_cnt > seg0_start && led_1_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (led_1_timer_cnt > seg1_start && led_1_timer_cnt <= seg1_end) {
            // 更换图片: /resource/LED1_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED1_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 1560ms
    else if (led_1_timer_cnt > seg2_start && led_1_timer_cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (led_1_timer_cnt > seg3_start && led_1_timer_cnt <= seg3_end) {
            // 更换图片: /resource/LED1_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED1_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_1_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_1_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: led_2
 * 模式: 预设动作（多段动画）
 * 段数: 4
 */
void led_2_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 159;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 67;
    const uint16_t seg1_start = 67;
    const uint16_t seg1_end = 77;
    const uint16_t seg2_start = 77;
    const uint16_t seg2_end = 149;
    const uint16_t seg3_start = 149;
    const uint16_t seg3_end = 159;
    
    led_2_timer_cnt++;
    
    // 段 1: 等待 2000ms
    if (led_2_timer_cnt > seg0_start && led_2_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (led_2_timer_cnt > seg1_start && led_2_timer_cnt <= seg1_end) {
            // 更换图片: /resource/LED2_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED2_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 2160ms
    else if (led_2_timer_cnt > seg2_start && led_2_timer_cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (led_2_timer_cnt > seg3_start && led_2_timer_cnt <= seg3_end) {
            // 更换图片: /resource/LED2_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED2_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_2_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_2_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: led_3
 * 模式: 预设动作（多段动画）
 * 段数: 4
 */
void led_3_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 139;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 87;
    const uint16_t seg1_start = 87;
    const uint16_t seg1_end = 97;
    const uint16_t seg2_start = 97;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 139;
    
    led_3_timer_cnt++;
    
    // 段 1: 等待 2600ms
    if (led_3_timer_cnt > seg0_start && led_3_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (led_3_timer_cnt > seg1_start && led_3_timer_cnt <= seg1_end) {
            // 更换图片: /resource/LED3_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED3_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 960ms
    else if (led_3_timer_cnt > seg2_start && led_3_timer_cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (led_3_timer_cnt > seg3_start && led_3_timer_cnt <= seg3_end) {
            // 更换图片: /resource/LED3_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED3_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_3_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_3_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: led_4
 * 模式: 预设动作（多段动画）
 * 段数: 4
 */
void led_4_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 149;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 77;
    const uint16_t seg1_start = 77;
    const uint16_t seg1_end = 87;
    const uint16_t seg2_start = 87;
    const uint16_t seg2_end = 139;
    const uint16_t seg3_start = 139;
    const uint16_t seg3_end = 149;
    
    led_4_timer_cnt++;
    
    // 段 1: 等待 2300ms
    if (led_4_timer_cnt > seg0_start && led_4_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (led_4_timer_cnt > seg1_start && led_4_timer_cnt <= seg1_end) {
            // 更换图片: /resource/LED4_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED4_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 1560ms
    else if (led_4_timer_cnt > seg2_start && led_4_timer_cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (led_4_timer_cnt > seg3_start && led_4_timer_cnt <= seg3_end) {
            // 更换图片: /resource/LED4_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED4_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_4_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_4_timer_cnt = 0; // 重置计数器
    }
}


/**
 * entrance
 * 组件: led_5
 * 模式: 预设动作（多段动画）
 * 段数: 4
 */
void led_5_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 159;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 67;
    const uint16_t seg1_start = 67;
    const uint16_t seg1_end = 77;
    const uint16_t seg2_start = 77;
    const uint16_t seg2_end = 149;
    const uint16_t seg3_start = 149;
    const uint16_t seg3_end = 159;
    
    led_5_timer_cnt++;
    
    // 段 1: 等待 2000ms
    if (led_5_timer_cnt > seg0_start && led_5_timer_cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (led_5_timer_cnt > seg1_start && led_5_timer_cnt <= seg1_end) {
            // 更换图片: /resource/LED5_on.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED5_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 2160ms
    else if (led_5_timer_cnt > seg2_start && led_5_timer_cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (led_5_timer_cnt > seg3_start && led_5_timer_cnt <= seg3_end) {
            // 更换图片: /resource/LED5_off.bin
            gui_img_set_src((gui_img_t *)target, "/resource/LED5_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_5_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_5_timer_cnt = 0; // 重置计数器
    }
}


/**
 * pos func
 * 组件: win_speed_text
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_speed_text_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_speed_text_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_speed_text_timer_cnt > seg0_start && win_speed_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_speed_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (38, 64) -> (38, -30)
            const int16_t x_origin = 38;
            const int16_t y_origin = 64;
            const int16_t x_target = 38;
            const int16_t y_target = -30;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (win_speed_text_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_speed_text_timer_cnt = 0; // 重置计数器
    }
}


/**
 * pos default
 * 组件: win_speed_text
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_speed_text_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_speed_text_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_speed_text_timer_cnt > seg0_start && win_speed_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_speed_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (38, -30) -> (38, 64)
            const int16_t x_origin = 38;
            const int16_t y_origin = -30;
            const int16_t x_target = 38;
            const int16_t y_target = 64;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (win_speed_text_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_speed_text_timer_cnt = 0; // 重置计数器
    }
}


/**
 * func pos
 * 组件: win_power_text
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_power_text_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_power_text_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_power_text_timer_cnt > seg0_start && win_power_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_power_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (470, 64) -> (470, -30)
            const int16_t x_origin = 470;
            const int16_t y_origin = 64;
            const int16_t x_target = 470;
            const int16_t y_target = -30;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (win_power_text_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_power_text_timer_cnt = 0; // 重置计数器
    }
}


/**
 * default pos
 * 组件: win_power_text
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_power_text_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_power_text_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_power_text_timer_cnt > seg0_start && win_power_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_power_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整位置: (470, -30) -> (470, 64)
            const int16_t x_origin = 470;
            const int16_t y_origin = -30;
            const int16_t x_target = 470;
            const int16_t y_target = 64;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (win_power_text_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_power_text_timer_cnt = 0; // 重置计数器
    }
}


/**
 * show win_func
 * 组件: win_func
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_func_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_func_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_func_timer_cnt > seg0_start && win_func_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (win_func_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_func_timer_cnt = 0; // 重置计数器
    }
}


/**
 * hide win_func
 * 组件: win_func
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_func_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_func_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_func_timer_cnt > seg0_start && win_func_timer_cnt <= seg0_end) {
            // 设置可见性: 隐藏
            gui_obj_show(target, false);
            
    }
    
    if (win_func_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_func_timer_cnt = 0; // 重置计数器
    }
}


/**
 * show
 * 组件: win_app_list
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_app_list_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_list_timer_cnt++;
    
    // 段 1: 10ms, 2 个动作
    if (win_app_list_timer_cnt > seg0_start && win_app_list_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
            // 设置焦点
            gui_obj_focus_set(target);
            
    }
    
    if (win_app_list_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_list_timer_cnt = 0; // 重置计数器
    }
}


/**
 * hide
 * 组件: win_app_list
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_app_list_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_list_timer_cnt++;
    
    // 段 1: 10ms, 1 个动作
    if (win_app_list_timer_cnt > seg0_start && win_app_list_timer_cnt <= seg0_end) {
            // 设置可见性: 隐藏
            gui_obj_show(target, false);
            
    }
    
    if (win_app_list_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_list_timer_cnt = 0; // 重置计数器
    }
}


/**
 * show
 * 组件: win_app_weather
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_app_weather_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_weather_timer_cnt++;
    
    // 段 1: 20ms, 2 个动作
    if (win_app_weather_timer_cnt > seg0_start && win_app_weather_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
            // 设置焦点
            gui_obj_focus_set(target);
            
    }
    
    if (win_app_weather_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_weather_timer_cnt = 0; // 重置计数器
    }
}


/**
 * hide
 * 组件: win_app_weather
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_app_weather_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 2;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 2;
    
    win_app_weather_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_app_weather_timer_cnt > seg0_start && win_app_weather_timer_cnt <= seg0_end) {
            // 设置可见性: 隐藏
            gui_obj_show(target, false);
            
    }
    
    if (win_app_weather_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_weather_timer_cnt = 0; // 重置计数器
    }
}


/**
 * show
 * 组件: win_app_developing
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_app_developing_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_developing_timer_cnt++;
    
    // 段 1: 20ms, 2 个动作
    if (win_app_developing_timer_cnt > seg0_start && win_app_developing_timer_cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
            // 设置焦点
            gui_obj_focus_set(target);
            
    }
    
    if (win_app_developing_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_developing_timer_cnt = 0; // 重置计数器
    }
}


/**
 * hide
 * 组件: win_app_developing
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void win_app_developing_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_developing_timer_cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (win_app_developing_timer_cnt > seg0_start && win_app_developing_timer_cnt <= seg0_end) {
            // 设置可见性: 隐藏
            gui_obj_show(target, false);
            
    }
    
    if (win_app_developing_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_developing_timer_cnt = 0; // 重置计数器
    }
}


/* @protected start custom_functions */
// 自定义函数
char speed_str[4] = {0};
uint8_t speed_val = 0;
void text_speed_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    speed_val += 10;
    speed_val %= 160;
    sprintf(speed_str, "%d", speed_val);
    gui_text_content_set(obj, speed_str, strlen(speed_str));
}

void text_speed_timer_1_cb(void *obj)
{
    GUI_UNUSED(obj);
    static uint16_t cnt = 0;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 97;
    const uint16_t seg1_start = 97;
    const uint16_t seg1_end = 113;
    const uint16_t seg2_start = 113;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 163;
    const uint16_t seg4_start = 163;
    const uint16_t seg4_end = 164;
    
    cnt++;
    
    // 段 1: 等待 2900ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
        speed_val = 0;
    }
    // 段 2: 480ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
        speed_val += 10;
    }
    // 段 3: 480ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
        speed_val -= 10;
    }
    // 段 4: 等待 1000ms
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (cnt > seg4_start && cnt <= seg4_end) {
            gui_obj_create_timer(obj, 100, true, text_speed_timer_0_cb);
            gui_obj_start_timer(obj);
            cnt = 0;
            return; // 切换定时动画后立即返回
            
    }
    sprintf(speed_str, "%d", speed_val);
    gui_text_content_set(obj, speed_str, strlen(speed_str));
}

char power_str[4] = {0}; 
uint8_t power_val = 0;
void text_power_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    power_val += 10;
    power_val %= 160;
    sprintf(power_str, "%d", power_val);
    gui_text_content_set(obj, power_str, strlen(power_str));
}

void text_power_timer_1_cb(void *obj)
{
    GUI_UNUSED(obj);
    static uint16_t cnt = 0;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 97;
    const uint16_t seg1_start = 97;
    const uint16_t seg1_end = 113;
    const uint16_t seg2_start = 113;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 163;
    const uint16_t seg4_start = 163;
    const uint16_t seg4_end = 164;
    
    cnt++;
    
    // 段 1: 等待 2900ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
        power_val = 0;
    }
    // 段 2: 480ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
        power_val += 10;
    }
    // 段 3: 480ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
        power_val -= 10;
    }
    // 段 4: 等待 1000ms
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (cnt > seg4_start && cnt <= seg4_end) {
            gui_obj_create_timer(obj, 100, true, text_power_timer_0_cb);
            gui_obj_start_timer(obj);
            cnt = 0;
            return; // 切换定时动画后立即返回
            
    }
    sprintf(power_str, "%d", power_val);
    gui_text_content_set(obj, power_str, strlen(power_str));
}

/**
 * 定时动画 1
 * 组件: text_time
 */
static char time_str[8] = "00:00";
void text_time_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo = localtime(&rawtime);
    if (timeinfo)
    {
        sprintf(time_str, "%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min);
    }
    gui_text_content_set(obj, time_str, strlen(time_str));
}

void zoom_animation(gui_obj_t *obj, float scale)
{
    matrix_translate(obj->w / 2, obj->h / 2, obj->matrix);
    if (scale == 0)
    {
        matrix_scale(1.f, 1.f, obj->matrix);
    }
    else
    {
        matrix_scale(scale, scale, obj->matrix);
    }
    matrix_translate(obj->w / -2, obj->h / -2, obj->matrix);
}

void win_speed_text_timer_0_cb(void *obj)
{
    static uint16_t cnt = 0;
    uint16_t cnt_max = 50;
    cnt++;
    float scale = (float)cnt / cnt_max;
    zoom_animation(obj, scale);
    if (cnt >= cnt_max)
    {
        cnt = 0;
        gui_obj_stop_timer(obj);
    }
}

void win_power_text_timer_0_cb(void *obj)
{
    static uint16_t cnt = 0;
    uint16_t cnt_max = 50;
    cnt++;
    float scale = (float)cnt / cnt_max;
    zoom_animation(obj, scale);
    if (cnt >= cnt_max)
    {
        cnt = 0;
        gui_obj_stop_timer(obj);
    }
}

static bool menu_disp = false;
static uint8_t menu_func_index = 0;

void root_menu_msg_show_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    if (!menu_disp)
    {
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, root_menu_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
        menu_disp = true;
    }
    else
    {
        void *cb = NULL;
        switch (menu_func_index)
        {
        case 0:
            cb = root_menu_timer_3_cb;
            break;
        case 1:
            cb = root_menu_timer_4_cb;
            break;
        case 2:
            cb = root_menu_timer_5_cb;
            break;
        case 3:
            cb = root_menu_timer_6_cb;
            break;
        default:
            break;
        }
        menu_func_index++;
        menu_func_index %= 4;
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
    }
}

void root_menu_msg_enter_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (obj->not_show || !menu_disp) return;
    
    switch (menu_func_index)
    {
    case 0:
        gui_obj_create_timer(GUI_BASE(win_map), 10, true, win_map_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_map));
        gui_obj_create_timer(GUI_BASE(win_dail), 10, true, win_dail_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_dail));
        gui_obj_create_timer(GUI_BASE(win_speed_text), 10, true, win_speed_text_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_speed_text));
        gui_obj_create_timer(GUI_BASE(win_power_text), 10, true, win_power_text_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_power_text));
        obj->y = 480;
        menu_disp = false;
        break;
    case 1:
        gui_obj_create_timer(GUI_BASE(win_func), 10, true, win_func_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(win_func));
        gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(win_app_list));
        gui_obj_create_timer(GUI_BASE(win_map), 10, true, win_map_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_map));
        gui_obj_create_timer(GUI_BASE(win_dail), 10, true, win_dail_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_dail));
        gui_obj_create_timer(GUI_BASE(win_speed_text), 10, true, win_speed_text_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_speed_text));
        gui_obj_create_timer(GUI_BASE(win_power_text), 10, true, win_power_text_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_power_text));
        obj->y = 480;
        menu_disp = false;
        break;
    default:
        break;
    }
}

void root_menu_msg_hide_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    if (menu_disp)
    {
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, root_menu_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
        menu_disp = false;
    }
}

void root_menu_msg_left_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    if (menu_disp)
    {
        void *cb = NULL;
        switch (menu_func_index)
        {
        case 0:
            cb = root_menu_timer_7_cb;
            break;
        case 3:
            cb = root_menu_timer_8_cb;
            break;
        case 2:
            cb = root_menu_timer_9_cb;
            break;
        case 1:
            cb = root_menu_timer_10_cb;
            break;
        default:
            break;
        }
        menu_func_index--;
        menu_func_index %= 4;
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
    }
}

void root_menu_msg_right_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    if (menu_disp)
    {
        void *cb = NULL;
        switch (menu_func_index)
        {
        case 0:
            cb = root_menu_timer_3_cb;
            break;
        case 1:
            cb = root_menu_timer_4_cb;
            break;
        case 2:
            cb = root_menu_timer_5_cb;
            break;
        case 3:
            cb = root_menu_timer_6_cb;
            break;
        default:
            break;
        }
        menu_func_index++;
        menu_func_index %= 4;
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
    }
}

uint8_t app_index = 0;
/**
 * pos update
 * 组件: tab_hightlight
 */
void tab_hightlight_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_obj_t *target = obj;
    int16_t y = 0;
    switch (app_index)
    {
    case 1:
        y = 90;
        break;
    case 2:
        y = 180;
        break;
    case 4:
        y = 90;
        break;
    case 5:
        y = 180;
        break;
    default:
        break;
    }
    gui_obj_move(target, target->x, y);
}

/**
 * show app note 1
 * 组件: app_list
 */
void app_list_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_list_set_offset(obj, 0);
    gui_obj_stop_timer(obj);
}

/**
 * show app note 2
 * 组件: app_list
 */
void app_list_timer_1_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_list_set_offset(obj, -280);
    gui_obj_stop_timer(obj);
}

uint8_t weather_note_index = 0;
/**
 * adjust weather note
 * 组件: list_weather
 */
void list_weather_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_list_set_offset(obj, weather_note_index * -280);
    gui_obj_stop_timer(obj);
    // TODO: 实现定时器回调逻辑
}

void win_app_list_msg_enter_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    if (app_index == 3)
    {
        gui_obj_create_timer(GUI_BASE(win_app_weather), 10, true, win_app_weather_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(win_app_weather));
    }
    else
    {
        gui_obj_create_timer(GUI_BASE(win_app_developing), 10, true, win_app_developing_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(win_app_developing));
    }
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
}

void win_app_list_msg_exit_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    app_index = 0;
    gui_obj_create_timer(GUI_BASE(win_func), 10, true, win_func_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_func));
    gui_obj_create_timer(GUI_BASE(win_dail), 10, true, win_dail_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_dail));
    gui_obj_create_timer(GUI_BASE(win_speed_text), 10, true, win_speed_text_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(win_speed_text));
    gui_obj_create_timer(GUI_BASE(win_power_text), 10, true, win_power_text_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(win_power_text));
    gui_obj_create_timer(GUI_BASE(root_menu), 10, true, root_menu_timer_11_cb);
    gui_obj_start_timer(GUI_BASE(root_menu));
    speed_arc_timer_cnt = 0;
    dail_pointer_s_timer_cnt = 0;
    power_arc_timer_cnt = 0;
    dail_pointer_p_timer_cnt = 0;
    speed_val = 0;
    power_val = 0;
}

void win_app_list_msg_last_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    if (app_index == 0) return;
    app_index--;
    if (app_index == 2)
    {
        gui_obj_create_timer(GUI_BASE(app_list), 10, true, app_list_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(app_list));
    }
}

void win_app_list_msg_next_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    app_index++;
    if (app_index == 3)
    {
        gui_obj_create_timer(GUI_BASE(app_list), 10, true, app_list_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(app_list));
    }
    else if (app_index == 6)
    {
        app_index = 0;
        gui_obj_create_timer(GUI_BASE(app_list), 10, true, app_list_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(app_list));
    }


}

void win_app_developing_msg_exit_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
    gui_obj_create_timer(GUI_BASE(win_app_developing), 10, true, win_app_developing_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_developing));
}

void win_app_weather_msg_next_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    weather_note_index++;
    weather_note_index %= 2;
    gui_obj_create_timer(GUI_BASE(list_weather), 10, true, list_weather_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(list_weather));
}

void win_app_weather_msg_exit_cb(gui_obj_t *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
    gui_obj_create_timer(GUI_BASE(win_app_weather), 10, true, win_app_weather_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_weather));
}

/* @protected end custom_functions */
