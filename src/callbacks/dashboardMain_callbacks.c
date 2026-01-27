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
    gui_obj_create_timer(GUI_BASE(bg_gloom), 20, true, bg_gloom_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(bg_gloom));
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
    
    // 段 1: 3000ms, 1 个动作
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
 * 定时动画 1
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
                "/resource/speed_arc/speed_arc_16.bin"
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
                "/resource/power_arc/power_arc_16.bin"
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
 * 定时动画 1
 * 组件: text_time
 */
void text_time_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // TODO: 实现定时器回调逻辑
}

/* @protected start custom_functions */
// 自定义函数
char speed_str[4] = {0};
uint8_t speed_val = 0;
void text_speed_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    speed_val += 10;
    if (speed_val == 170) speed_val = 10;
    sprintf(speed_str, "%d", speed_val);
    gui_text_content_set(obj, speed_str, strlen(speed_str));
}

char power_str[4] = {0}; 
uint8_t power_val = 0;
void text_power_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    power_val += 10;
    if (power_val == 170) power_val = 10;
    sprintf(power_str, "%d", power_val);
    gui_text_content_set(obj, power_str, strlen(power_str));
}
/* @protected end custom_functions */
