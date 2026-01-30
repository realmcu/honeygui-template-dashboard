#include "dashboardMain_callbacks.h"
#include "../ui/dashboardMain_ui.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// 事件回调函数实现

void off_icon_switch_view_cb(void *obj, gui_event_t event, void *param)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(event);
    GUI_UNUSED(param);
    gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
}

void start_engine_animation_set_0_cb(void *obj, gui_event_t event, void *param)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(event);
    GUI_UNUSED(param);
    gui_obj_create_timer(GUI_BASE(shadow), 20, true, shadow_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(shadow));
}

void start_engine_animation_set_1_cb(void *obj, gui_event_t event, void *param)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(event);
    GUI_UNUSED(param);
    gui_obj_create_timer(GUI_BASE(bg_gloom), 20, true, bg_gloom_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(bg_gloom));
    gui_obj_create_timer(GUI_BASE(shadow), 20, true, shadow_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(shadow));
}

void map_animation_set_0_cb(void *obj, gui_event_t event, void *param)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(event);
    GUI_UNUSED(param);
    gui_obj_create_timer(GUI_BASE(root_menu), 10, true, root_menu_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(root_menu));
}

// 预设定时器回调函数

/**
 * exit
 * 组件: bg_gloom
 * 模式: 预设动作（多段动画）
 * 段数: 3
 */
void bg_gloom_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 36;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    const uint16_t seg1_start = 30;
    const uint16_t seg1_end = 35;
    const uint16_t seg2_start = 35;
    const uint16_t seg2_end = 36;
    
    cnt++;
    
    // 段 1: 600ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整透明度: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // 段 2: 等待 100ms
    else if (cnt > seg1_start && cnt <= seg1_end) {
        // 无动作，仅等待
    }
    // 段 3: 20ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
            // 跳转界面: dashboard_view
            gui_view_switch_direct(gui_view_get_current(), "dashboard_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
    }
}


/**
 * press
 * 组件: shadow
 * 模式: 预设动作（多段动画）
 * 段数: 2
 */
void shadow_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 51;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    const uint16_t seg1_start = 1;
    const uint16_t seg1_end = 51;
    
    cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
            // 更换图片: /resource/Start_Engine_Press.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Start_Engine_Press.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 2: 等待 1000ms
    else if (cnt > seg1_start && cnt <= seg1_end) {
        // 无动作，仅等待
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    cnt++;
    
    // 段 1: 20ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
            // 更换图片: /resource/Start_Engine_Release.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Start_Engine_Release.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    cnt++;
    
    // 段 1: 5000ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
    }
}


/**
 * map_update
 * 组件: map
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void map_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 13;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 13;
    
    cnt++;
    
    // 段 1: 13000ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        cnt = 0; // 重置计数器，继续循环
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    cnt++;
    
    // 段 1: 5000ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
            // 切换定时动画: map_update
            gui_obj_create_timer(target, 1000, true, map_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 120;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 120;
    
    cnt++;
    
    // 段 1: 2400ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        cnt = 0; // 重置计数器，继续循环
    }
}


/**
 * entrance
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 1
 */
void root_menu_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    cnt++;
    
    // 段 1: 5000ms, 2 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
            // 切换定时动画: menu array
            gui_obj_create_timer(target, 20, true, root_menu_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
    }
}


/**
 * move up
 * 组件: root_menu
 * 模式: 预设动作（多段动画）
 * 段数: 2
 */
void root_menu_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 31;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    const uint16_t seg1_start = 30;
    const uint16_t seg1_end = 31;
    
    cnt++;
    
    // 段 1: 300ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
    // 段 2: 10ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 切换定时动画: menu array
            gui_obj_create_timer(target, 20, true, root_menu_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 62;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    const uint16_t seg1_start = 30;
    const uint16_t seg1_end = 62;
    
    cnt++;
    
    // 段 1: 900ms, 2 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
    else if (cnt > seg1_start && cnt <= seg1_end) {
        uint16_t seg_cnt = cnt - seg1_start;
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
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 30;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    
    cnt++;
    
    // 段 1: 900ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 30;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 30;
    
    cnt++;
    
    // 段 1: 900ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 125;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 125;
    
    cnt++;
    
    // 段 1: 1000ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整透明度: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            target->opacity_value = opacity_cur;
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        cnt = 0; // 重置计数器，继续循环
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
    static uint16_t cnt = 0;
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
    
    cnt++;
    
    // 段 1: 等待 2900ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
        uint16_t seg_cnt = cnt - seg1_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
        uint16_t seg_cnt = cnt - seg2_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 等待 1000ms
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (cnt > seg4_start && cnt <= seg4_end) {
            // 切换定时动画: arc_animate
            gui_obj_create_timer(target, 100, true, speed_arc_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整旋转: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    
    if (cnt >= total_cnt_max) {
        cnt = 0; // 重置计数器，继续循环
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
    static uint16_t cnt = 0;
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
    
    cnt++;
    
    // 段 1: 等待 2900ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
        uint16_t seg_cnt = cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 调整旋转: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
        uint16_t seg_cnt = cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // 调整旋转: 720° -> 360°
            const float angle_origin = 720;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 4: 等待 1000ms
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (cnt > seg4_start && cnt <= seg4_end) {
            // 切换定时动画: rotate
            gui_obj_create_timer(target, 100, true, dail_pointer_s_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        cnt = 0; // 重置计数器，继续循环
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
    static uint16_t cnt = 0;
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
    
    cnt++;
    
    // 段 1: 等待 2900ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
        uint16_t seg_cnt = cnt - seg1_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
        uint16_t seg_cnt = cnt - seg2_start;
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
            gui_img_set_image_data((gui_img_t *)target, img_data_array[index]);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 等待 1000ms
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (cnt > seg4_start && cnt <= seg4_end) {
            // 切换定时动画: arc_animate
            gui_obj_create_timer(target, 100, true, power_arc_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 16;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 16;
    
    cnt++;
    
    // 段 1: 1600ms, 1 个动作
    if (cnt > seg0_start && cnt <= seg0_end) {
        uint16_t seg_cnt = cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // 调整旋转: 0° -> -360°
            const float angle_origin = 0;
            const float angle_target = -360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    
    if (cnt >= total_cnt_max) {
        cnt = 0; // 重置计数器，继续循环
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
    static uint16_t cnt = 0;
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
    
    cnt++;
    
    // 段 1: 等待 2900ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 480ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
        uint16_t seg_cnt = cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // 调整旋转: 0° -> -360°
            const float angle_origin = 0;
            const float angle_target = -360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 3: 480ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
        uint16_t seg_cnt = cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // 调整旋转: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // 段 4: 等待 1000ms
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // 无动作，仅等待
    }
    // 段 5: 30ms, 1 个动作
    else if (cnt > seg4_start && cnt <= seg4_end) {
            // 切换定时动画: rotate
            gui_obj_create_timer(target, 100, true, dail_pointer_p_timer_0_cb);
            gui_obj_start_timer(target);
            cnt = 0; // 重置计数器
            return; // 切换定时动画后立即返回
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 100;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 99;
    const uint16_t seg1_start = 99;
    const uint16_t seg1_end = 100;
    
    cnt++;
    
    // 段 1: 等待 1980ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 20ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 设置可见性: 显示
            gui_obj_show(target, true);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
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
    
    cnt++;
    
    // 段 1: 等待 2000ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/Turnleft_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnleft_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 300ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
            // 更换图片: /resource/Turnleft_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnleft_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/Turnleft_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnleft_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 5: 等待 960ms
    else if (cnt > seg4_start && cnt <= seg4_end) {
        // 无动作，仅等待
    }
    // 段 6: 300ms, 1 个动作
    else if (cnt > seg5_start && cnt <= seg5_end) {
            // 更换图片: /resource/Turnleft_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnleft_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 7: 300ms, 1 个动作
    else if (cnt > seg6_start && cnt <= seg6_end) {
            // 更换图片: /resource/Turnleft_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnleft_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 8: 300ms, 1 个动作
    else if (cnt > seg7_start && cnt <= seg7_end) {
            // 更换图片: /resource/Turnleft_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnleft_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
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
    
    cnt++;
    
    // 段 1: 等待 2000ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/Turnright_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnright_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 300ms, 1 个动作
    else if (cnt > seg2_start && cnt <= seg2_end) {
            // 更换图片: /resource/Turnright_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnright_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/Turnright_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnright_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 5: 等待 960ms
    else if (cnt > seg4_start && cnt <= seg4_end) {
        // 无动作，仅等待
    }
    // 段 6: 300ms, 1 个动作
    else if (cnt > seg5_start && cnt <= seg5_end) {
            // 更换图片: /resource/Turnright_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnright_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 7: 300ms, 1 个动作
    else if (cnt > seg6_start && cnt <= seg6_end) {
            // 更换图片: /resource/Turnright_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnright_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 8: 300ms, 1 个动作
    else if (cnt > seg7_start && cnt <= seg7_end) {
            // 更换图片: /resource/Turnright_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/Turnright_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 139;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 87;
    const uint16_t seg1_start = 87;
    const uint16_t seg1_end = 97;
    const uint16_t seg2_start = 97;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 139;
    
    cnt++;
    
    // 段 1: 等待 2600ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/LED0_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED0_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 960ms
    else if (cnt > seg2_start && cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/LED0_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED0_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 149;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 77;
    const uint16_t seg1_start = 77;
    const uint16_t seg1_end = 87;
    const uint16_t seg2_start = 87;
    const uint16_t seg2_end = 139;
    const uint16_t seg3_start = 139;
    const uint16_t seg3_end = 149;
    
    cnt++;
    
    // 段 1: 等待 2300ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/LED1_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED1_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 1560ms
    else if (cnt > seg2_start && cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/LED1_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED1_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 159;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 67;
    const uint16_t seg1_start = 67;
    const uint16_t seg1_end = 77;
    const uint16_t seg2_start = 77;
    const uint16_t seg2_end = 149;
    const uint16_t seg3_start = 149;
    const uint16_t seg3_end = 159;
    
    cnt++;
    
    // 段 1: 等待 2000ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/LED2_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED2_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 2160ms
    else if (cnt > seg2_start && cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/LED2_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED2_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 139;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 87;
    const uint16_t seg1_start = 87;
    const uint16_t seg1_end = 97;
    const uint16_t seg2_start = 97;
    const uint16_t seg2_end = 129;
    const uint16_t seg3_start = 129;
    const uint16_t seg3_end = 139;
    
    cnt++;
    
    // 段 1: 等待 2600ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/LED3_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED3_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 960ms
    else if (cnt > seg2_start && cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/LED3_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED3_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 149;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 77;
    const uint16_t seg1_start = 77;
    const uint16_t seg1_end = 87;
    const uint16_t seg2_start = 87;
    const uint16_t seg2_end = 139;
    const uint16_t seg3_start = 139;
    const uint16_t seg3_end = 149;
    
    cnt++;
    
    // 段 1: 等待 2300ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/LED4_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED4_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 1560ms
    else if (cnt > seg2_start && cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/LED4_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED4_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    static uint16_t cnt = 0;
    const uint16_t total_cnt_max = 159;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 67;
    const uint16_t seg1_start = 67;
    const uint16_t seg1_end = 77;
    const uint16_t seg2_start = 77;
    const uint16_t seg2_end = 149;
    const uint16_t seg3_start = 149;
    const uint16_t seg3_end = 159;
    
    cnt++;
    
    // 段 1: 等待 2000ms
    if (cnt > seg0_start && cnt <= seg0_end) {
        // 无动作，仅等待
    }
    // 段 2: 300ms, 1 个动作
    else if (cnt > seg1_start && cnt <= seg1_end) {
            // 更换图片: /resource/LED5_on.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED5_on.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // 段 3: 等待 2160ms
    else if (cnt > seg2_start && cnt <= seg2_end) {
        // 无动作，仅等待
    }
    // 段 4: 300ms, 1 个动作
    else if (cnt > seg3_start && cnt <= seg3_end) {
            // 更换图片: /resource/LED5_off.bin
            gui_img_set_image_data((gui_img_t *)target, "/resource/LED5_off.bin");
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        cnt = 0; // 重置计数器
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
    uint16_t cnt_max = 30;
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
    uint16_t cnt_max = 30;
    cnt++;
    float scale = (float)cnt / cnt_max;
    zoom_animation(obj, scale);
    if (cnt >= cnt_max)
    {
        cnt = 0;
        gui_obj_stop_timer(obj);
    }
}

/* @protected end custom_functions */
