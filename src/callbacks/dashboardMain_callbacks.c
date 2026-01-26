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
 * 组件: text_time
 */
void text_time_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // TODO: 实现定时器回调逻辑
}

/* @protected start custom_functions */
// 自定义函数
/* @protected end custom_functions */
