#include "DashboardMain_callbacks.h"
#include "../ui/DashboardMain_ui.h"
#include "../user/DashboardMain_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Timer animation counters
uint16_t gloom_timer_cnt = 0;
uint16_t dashboard_view_timer_cnt = 0;
uint16_t map_timer_cnt = 0;
uint16_t win_func_timer_cnt = 0;
uint16_t win_app_list_timer_cnt = 0;
uint16_t app_list_timer_cnt = 0;
uint16_t tab_hightlight_timer_cnt = 0;
uint16_t win_app_weather_timer_cnt = 0;
uint16_t list_weather_timer_cnt = 0;
uint16_t win_app_developing_timer_cnt = 0;
uint16_t root_menu_timer_cnt = 0;
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
uint16_t text_odo_timer_cnt = 0;
uint16_t win_power_text_timer_cnt = 0;
uint16_t text_power_timer_cnt = 0;
uint16_t text_battery_timer_cnt = 0;
uint16_t win_volume_timer_cnt = 0;
uint16_t lbl_volume_timer_cnt = 0;
uint16_t win_music_timer_cnt = 0;
uint16_t win_carplay_timer_cnt = 0;
uint16_t carplay_time_timer_cnt = 0;
uint16_t carplay_speed_arc_timer_cnt = 0;
uint16_t win_music_bar_timer_cnt = 0;

// Event callback function implementations

void start_engine_key_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Power") == 0)
    {
        gloom_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(gloom), 20, true, gloom_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(gloom));
    }
}

void win_app_list_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
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
    // Check key name
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
    // Check key name
    if (strcmp(e->indev_name, "Back") == 0)
    {
        win_app_developing_msg_exit_cb(obj, e);
    }
}

void root_menu_key_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        root_menu_msg_enter_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        root_menu_msg_hide_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        root_menu_msg_show_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Power") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
    }
}

void dail_power_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // TODO: Implement event handling logic
}

void carplay_view_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Power") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "dashboardMainView", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
    }
    else if (strcmp(e->indev_name, "Home") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "dashboard_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "dashboard_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
    }
}

void win_dail_msg_cb_0(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_speed(obj, topic, data, len);
}

void win_dail_msg_cb_1(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_power(obj, topic, data, len);
}

void win_common_msg_cb_0(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led0(obj, topic, data, len);
}

void win_common_msg_cb_1(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led1(obj, topic, data, len);
}

void win_common_msg_cb_2(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led2(obj, topic, data, len);
}

void win_common_msg_cb_3(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led3(obj, topic, data, len);
}

void win_common_msg_cb_4(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led4(obj, topic, data, len);
}

void win_common_msg_cb_5(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led5(obj, topic, data, len);
}

void win_common_msg_cb_6(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led_turn_l(obj, topic, data, len);
}

void win_common_msg_cb_7(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_led_turn_r(obj, topic, data, len);
}

void win_common_msg_cb_8(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_bt(obj, topic, data, len);
}

void win_common_msg_cb_9(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_wifi(obj, topic, data, len);
}

void win_common_msg_cb_10(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_volume(obj, topic, data, len);
}

void win_common_msg_cb_11(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_location(obj, topic, data, len);
}

void win_common_msg_cb_12(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_temp(obj, topic, data, len);
}

void win_common_msg_cb_13(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_music_play(obj, topic, data, len);
}

void win_common_msg_cb_14(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_odo(obj, topic, data, len);
}

void win_common_msg_cb_15(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_batt(obj, topic, data, len);
}

void win_common_msg_cb_16(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_map(obj, topic, data, len);
}

void win_carplay_msg_cb_0(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_location(obj, topic, data, len);
}

void win_carplay_msg_cb_1(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_temp(obj, topic, data, len);
}

void win_carplay_msg_cb_2(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_music_play(obj, topic, data, len);
}

void win_carplay_msg_cb_3(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_odo(obj, topic, data, len);
}

void win_carplay_msg_cb_4(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_batt(obj, topic, data, len);
}

void win_carplay_msg_cb_5(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    update_dashboard_speed(obj, topic, data, len);
}

// Preset timer callback functions

/**
 * exit
 * Component: gloom
 * Mode: Preset actions (multi-segment animation)
 * Segments: 3
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
    
    // Segment 1: 600ms, 1 action(s)
    if (gloom_timer_cnt > seg0_start && gloom_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = gloom_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 255
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: Wait 100ms
    else if (gloom_timer_cnt > seg1_start && gloom_timer_cnt <= seg1_end) {
        // No action, just wait
    }
    // Segment 3: 20ms, 1 action(s)
    else if (gloom_timer_cnt > seg2_start && gloom_timer_cnt <= seg2_end) {
            // Switch view: dashboard_view
            gui_view_switch_direct(gui_view_get_current(), "dashboard_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
            
    }
    
    if (gloom_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        gloom_timer_cnt = 0; // Reset counter
    }
}


/**
 * map array
 * Component: map
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void map_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 13;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 13;
    
    map_timer_cnt++;
    
    // Segment 1: 13000ms, 1 action(s)
    if (map_timer_cnt > seg0_start && map_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = map_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 13 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (map_timer_cnt >= total_cnt_max) {
        map_timer_cnt = 0; // Reset counter, continue loop
    }
}


/**
 * entrance
 * Component: map
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void map_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    map_timer_cnt++;
    
    // Segment 1: 6000ms, 2 action(s)
    if (map_timer_cnt > seg0_start && map_timer_cnt <= seg0_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
            // Timer control
            // Start timer animation: map array
            map_timer_cnt = 0; // Reset counter
            gui_obj_create_timer(target, 1000, true, map_timer_0_cb);
            gui_obj_start_timer(target);
            return; // Return immediately after timer control
            
    }
    
    if (map_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        map_timer_cnt = 0; // Reset counter
    }
}


/**
 * show win_func
 * Component: win_func
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_func_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_func_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_func_timer_cnt > seg0_start && win_func_timer_cnt <= seg0_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
    }
    
    if (win_func_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_func_timer_cnt = 0; // Reset counter
    }
}


/**
 * hide win_func
 * Component: win_func
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_func_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_func_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_func_timer_cnt > seg0_start && win_func_timer_cnt <= seg0_end) {
            // Set visibility: hide
            gui_obj_hidden(target, true);
            
    }
    
    if (win_func_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_func_timer_cnt = 0; // Reset counter
    }
}


/**
 * show
 * Component: win_app_list
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_app_list_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_list_timer_cnt++;
    
    // Segment 1: 10ms, 2 action(s)
    if (win_app_list_timer_cnt > seg0_start && win_app_list_timer_cnt <= seg0_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
            // Set focus
            gui_obj_focus_set(target);
            
    }
    
    if (win_app_list_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_list_timer_cnt = 0; // Reset counter
    }
}


/**
 * hide
 * Component: win_app_list
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_app_list_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_list_timer_cnt++;
    
    // Segment 1: 10ms, 1 action(s)
    if (win_app_list_timer_cnt > seg0_start && win_app_list_timer_cnt <= seg0_end) {
            // Set visibility: hide
            gui_obj_hidden(target, true);
            
    }
    
    if (win_app_list_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_list_timer_cnt = 0; // Reset counter
    }
}


/**
 * show
 * Component: win_app_weather
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_app_weather_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_weather_timer_cnt++;
    
    // Segment 1: 20ms, 2 action(s)
    if (win_app_weather_timer_cnt > seg0_start && win_app_weather_timer_cnt <= seg0_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
            // Set focus
            gui_obj_focus_set(target);
            
    }
    
    if (win_app_weather_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_weather_timer_cnt = 0; // Reset counter
    }
}


/**
 * hide
 * Component: win_app_weather
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_app_weather_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 2;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 2;
    
    win_app_weather_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_app_weather_timer_cnt > seg0_start && win_app_weather_timer_cnt <= seg0_end) {
            // Set visibility: hide
            gui_obj_hidden(target, true);
            
    }
    
    if (win_app_weather_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_weather_timer_cnt = 0; // Reset counter
    }
}


/**
 * show
 * Component: win_app_developing
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_app_developing_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_developing_timer_cnt++;
    
    // Segment 1: 20ms, 2 action(s)
    if (win_app_developing_timer_cnt > seg0_start && win_app_developing_timer_cnt <= seg0_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
            // Set focus
            gui_obj_focus_set(target);
            
    }
    
    if (win_app_developing_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_developing_timer_cnt = 0; // Reset counter
    }
}


/**
 * hide
 * Component: win_app_developing
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_app_developing_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_app_developing_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_app_developing_timer_cnt > seg0_start && win_app_developing_timer_cnt <= seg0_end) {
            // Set visibility: hide
            gui_obj_hidden(target, true);
            
    }
    
    if (win_app_developing_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_app_developing_timer_cnt = 0; // Reset counter
    }
}


/**
 * menu array
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 120;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 120;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 2400ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 60 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        root_menu_timer_cnt = 0; // Reset counter, continue loop
    }
}


/**
 * move up
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 150ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust position: (225, 480) -> (225, 293)
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
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * move down
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 150ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust position: (225, 293) -> (225, 480)
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
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 1 to 2
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_3_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 300ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 15 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 2 to 3
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_4_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 300ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 15 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 3 to 4
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_5_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 300ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 15 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 4 to 1
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_6_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 15;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 15;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 299ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 15 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 1 to 4
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_7_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 280ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 14 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 4 to 3
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_8_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 280ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 14 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 3 to 2
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_9_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 280ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 14 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * 2 to 1
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_10_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 14;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 14;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 280ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = root_menu_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Image sequence animation: 14 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * set focus
 * Component: root_menu
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void root_menu_timer_11_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    root_menu_timer_cnt++;
    
    // Segment 1: 10ms, 1 action(s)
    if (root_menu_timer_cnt > seg0_start && root_menu_timer_cnt <= seg0_end) {
            // Set focus
            gui_obj_focus_set(target);
            
    }
    
    if (root_menu_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        root_menu_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: win_dail
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_dail_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 100;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 100;
    
    win_dail_timer_cnt++;
    
    // Segment 1: 1000ms, 1 action(s)
    if (win_dail_timer_cnt > seg0_start && win_dail_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_dail_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            target->opacity_value = opacity_cur;
            
    }
    
    if (win_dail_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_dail_timer_cnt = 0; // Reset counter
    }
}


/**
 * show
 * Component: win_dail
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_dail_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_dail_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_dail_timer_cnt > seg0_start && win_dail_timer_cnt <= seg0_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
    }
    
    if (win_dail_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_dail_timer_cnt = 0; // Reset counter
    }
}


/**
 * hide
 * Component: win_dail
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_dail_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_dail_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_dail_timer_cnt > seg0_start && win_dail_timer_cnt <= seg0_end) {
            // Set visibility: hide
            gui_obj_hidden(target, true);
            
    }
    
    if (win_dail_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_dail_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: speed_arc
 * Mode: Preset actions (multi-segment animation)
 * Segments: 5
 */
void speed_arc_timer_0_cb(void *obj)
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
    
    // Segment 1: Wait 2900ms
    if (speed_arc_timer_cnt > seg0_start && speed_arc_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 480ms, 1 action(s)
    else if (speed_arc_timer_cnt > seg1_start && speed_arc_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = speed_arc_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Image sequence animation: 16 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: 480ms, 1 action(s)
    else if (speed_arc_timer_cnt > seg2_start && speed_arc_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = speed_arc_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // Image sequence animation: 16 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 4: Wait 1000ms
    else if (speed_arc_timer_cnt > seg3_start && speed_arc_timer_cnt <= seg3_end) {
        // No action, just wait
    }
    // Segment 5: Wait 30ms
    else if (speed_arc_timer_cnt > seg4_start && speed_arc_timer_cnt <= seg4_end) {
        // No action, just wait
    }
    
    if (speed_arc_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        speed_arc_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: dail_pointer_s
 * Mode: Preset actions (multi-segment animation)
 * Segments: 5
 */
void dail_pointer_s_timer_0_cb(void *obj)
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
    
    // Segment 1: Wait 2900ms
    if (dail_pointer_s_timer_cnt > seg0_start && dail_pointer_s_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 480ms, 1 action(s)
    else if (dail_pointer_s_timer_cnt > seg1_start && dail_pointer_s_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = dail_pointer_s_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust rotation: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // Segment 3: 480ms, 1 action(s)
    else if (dail_pointer_s_timer_cnt > seg2_start && dail_pointer_s_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = dail_pointer_s_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // Adjust rotation: 720° -> 360°
            const float angle_origin = 720;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // Segment 4: Wait 1000ms
    else if (dail_pointer_s_timer_cnt > seg3_start && dail_pointer_s_timer_cnt <= seg3_end) {
        // No action, just wait
    }
    // Segment 5: Wait 30ms
    else if (dail_pointer_s_timer_cnt > seg4_start && dail_pointer_s_timer_cnt <= seg4_end) {
        // No action, just wait
    }
    
    if (dail_pointer_s_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        dail_pointer_s_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: power_arc
 * Mode: Preset actions (multi-segment animation)
 * Segments: 5
 */
void power_arc_timer_0_cb(void *obj)
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
    
    // Segment 1: Wait 2900ms
    if (power_arc_timer_cnt > seg0_start && power_arc_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 480ms, 1 action(s)
    else if (power_arc_timer_cnt > seg1_start && power_arc_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = power_arc_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Image sequence animation: 16 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: 480ms, 1 action(s)
    else if (power_arc_timer_cnt > seg2_start && power_arc_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = power_arc_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // Image sequence animation: 16 images
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
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 4: Wait 1000ms
    else if (power_arc_timer_cnt > seg3_start && power_arc_timer_cnt <= seg3_end) {
        // No action, just wait
    }
    // Segment 5: Wait 30ms
    else if (power_arc_timer_cnt > seg4_start && power_arc_timer_cnt <= seg4_end) {
        // No action, just wait
    }
    
    if (power_arc_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        power_arc_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: dail_pointer_p
 * Mode: Preset actions (multi-segment animation)
 * Segments: 5
 */
void dail_pointer_p_timer_0_cb(void *obj)
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
    
    // Segment 1: Wait 2900ms
    if (dail_pointer_p_timer_cnt > seg0_start && dail_pointer_p_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 480ms, 1 action(s)
    else if (dail_pointer_p_timer_cnt > seg1_start && dail_pointer_p_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = dail_pointer_p_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust rotation: 0° -> -360°
            const float angle_origin = 0;
            const float angle_target = -360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // Segment 3: 480ms, 1 action(s)
    else if (dail_pointer_p_timer_cnt > seg2_start && dail_pointer_p_timer_cnt <= seg2_end) {
        uint16_t seg_cnt = dail_pointer_p_timer_cnt - seg2_start;
        const uint16_t seg_cnt_max = seg2_end - seg2_start;
        
            // Adjust rotation: 0° -> 360°
            const float angle_origin = 0;
            const float angle_target = 360;
            float angle_cur = angle_origin + (angle_target - angle_origin) * seg_cnt / seg_cnt_max;
            gui_img_rotation((gui_img_t *)target, angle_cur);
            
    }
    // Segment 4: Wait 1000ms
    else if (dail_pointer_p_timer_cnt > seg3_start && dail_pointer_p_timer_cnt <= seg3_end) {
        // No action, just wait
    }
    // Segment 5: Wait 30ms
    else if (dail_pointer_p_timer_cnt > seg4_start && dail_pointer_p_timer_cnt <= seg4_end) {
        // No action, just wait
    }
    
    if (dail_pointer_p_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        dail_pointer_p_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: win_common
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
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
    
    // Segment 1: Wait 1980ms
    if (win_common_timer_cnt > seg0_start && win_common_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 20ms, 1 action(s)
    else if (win_common_timer_cnt > seg1_start && win_common_timer_cnt <= seg1_end) {
            // Set visibility: show
            gui_obj_hidden(target, false);
            
    }
    
    if (win_common_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_common_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: turn_l_icon
 * Mode: Preset actions (multi-segment animation)
 * Segments: 8
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
    
    // Segment 1: Wait 2000ms
    if (turn_l_icon_timer_cnt > seg0_start && turn_l_icon_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (turn_l_icon_timer_cnt > seg1_start && turn_l_icon_timer_cnt <= seg1_end) {
            // Change image: /resource/Turnleft_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnleft_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: 300ms, 1 action(s)
    else if (turn_l_icon_timer_cnt > seg2_start && turn_l_icon_timer_cnt <= seg2_end) {
            // Change image: /resource/Turnleft_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnleft_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 4: 300ms, 1 action(s)
    else if (turn_l_icon_timer_cnt > seg3_start && turn_l_icon_timer_cnt <= seg3_end) {
            // Change image: /resource/Turnleft_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnleft_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 5: Wait 960ms
    else if (turn_l_icon_timer_cnt > seg4_start && turn_l_icon_timer_cnt <= seg4_end) {
        // No action, just wait
    }
    // Segment 6: 300ms, 1 action(s)
    else if (turn_l_icon_timer_cnt > seg5_start && turn_l_icon_timer_cnt <= seg5_end) {
            // Change image: /resource/Turnleft_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnleft_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 7: 300ms, 1 action(s)
    else if (turn_l_icon_timer_cnt > seg6_start && turn_l_icon_timer_cnt <= seg6_end) {
            // Change image: /resource/Turnleft_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnleft_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 8: 300ms, 1 action(s)
    else if (turn_l_icon_timer_cnt > seg7_start && turn_l_icon_timer_cnt <= seg7_end) {
            // Change image: /resource/Turnleft_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnleft_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (turn_l_icon_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        turn_l_icon_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: turn_r_icon
 * Mode: Preset actions (multi-segment animation)
 * Segments: 8
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
    
    // Segment 1: Wait 2000ms
    if (turn_r_icon_timer_cnt > seg0_start && turn_r_icon_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (turn_r_icon_timer_cnt > seg1_start && turn_r_icon_timer_cnt <= seg1_end) {
            // Change image: /resource/Turnright_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnright_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: 300ms, 1 action(s)
    else if (turn_r_icon_timer_cnt > seg2_start && turn_r_icon_timer_cnt <= seg2_end) {
            // Change image: /resource/Turnright_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnright_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 4: 300ms, 1 action(s)
    else if (turn_r_icon_timer_cnt > seg3_start && turn_r_icon_timer_cnt <= seg3_end) {
            // Change image: /resource/Turnright_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnright_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 5: Wait 960ms
    else if (turn_r_icon_timer_cnt > seg4_start && turn_r_icon_timer_cnt <= seg4_end) {
        // No action, just wait
    }
    // Segment 6: 300ms, 1 action(s)
    else if (turn_r_icon_timer_cnt > seg5_start && turn_r_icon_timer_cnt <= seg5_end) {
            // Change image: /resource/Turnright_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnright_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 7: 300ms, 1 action(s)
    else if (turn_r_icon_timer_cnt > seg6_start && turn_r_icon_timer_cnt <= seg6_end) {
            // Change image: /resource/Turnright_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnright_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 8: 300ms, 1 action(s)
    else if (turn_r_icon_timer_cnt > seg7_start && turn_r_icon_timer_cnt <= seg7_end) {
            // Change image: /resource/Turnright_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/Turnright_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (turn_r_icon_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        turn_r_icon_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: led_0
 * Mode: Preset actions (multi-segment animation)
 * Segments: 4
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
    
    // Segment 1: Wait 2600ms
    if (led_0_timer_cnt > seg0_start && led_0_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (led_0_timer_cnt > seg1_start && led_0_timer_cnt <= seg1_end) {
            // Change image: /resource/LED0_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED0_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: Wait 960ms
    else if (led_0_timer_cnt > seg2_start && led_0_timer_cnt <= seg2_end) {
        // No action, just wait
    }
    // Segment 4: 300ms, 1 action(s)
    else if (led_0_timer_cnt > seg3_start && led_0_timer_cnt <= seg3_end) {
            // Change image: /resource/LED0_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED0_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_0_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_0_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: led_1
 * Mode: Preset actions (multi-segment animation)
 * Segments: 4
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
    
    // Segment 1: Wait 2300ms
    if (led_1_timer_cnt > seg0_start && led_1_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (led_1_timer_cnt > seg1_start && led_1_timer_cnt <= seg1_end) {
            // Change image: /resource/LED1_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED1_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: Wait 1560ms
    else if (led_1_timer_cnt > seg2_start && led_1_timer_cnt <= seg2_end) {
        // No action, just wait
    }
    // Segment 4: 300ms, 1 action(s)
    else if (led_1_timer_cnt > seg3_start && led_1_timer_cnt <= seg3_end) {
            // Change image: /resource/LED1_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED1_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_1_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_1_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: led_2
 * Mode: Preset actions (multi-segment animation)
 * Segments: 4
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
    
    // Segment 1: Wait 2000ms
    if (led_2_timer_cnt > seg0_start && led_2_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (led_2_timer_cnt > seg1_start && led_2_timer_cnt <= seg1_end) {
            // Change image: /resource/LED2_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED2_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: Wait 2160ms
    else if (led_2_timer_cnt > seg2_start && led_2_timer_cnt <= seg2_end) {
        // No action, just wait
    }
    // Segment 4: 300ms, 1 action(s)
    else if (led_2_timer_cnt > seg3_start && led_2_timer_cnt <= seg3_end) {
            // Change image: /resource/LED2_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED2_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_2_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_2_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: led_3
 * Mode: Preset actions (multi-segment animation)
 * Segments: 4
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
    
    // Segment 1: Wait 2600ms
    if (led_3_timer_cnt > seg0_start && led_3_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (led_3_timer_cnt > seg1_start && led_3_timer_cnt <= seg1_end) {
            // Change image: /resource/LED3_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED3_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: Wait 960ms
    else if (led_3_timer_cnt > seg2_start && led_3_timer_cnt <= seg2_end) {
        // No action, just wait
    }
    // Segment 4: 300ms, 1 action(s)
    else if (led_3_timer_cnt > seg3_start && led_3_timer_cnt <= seg3_end) {
            // Change image: /resource/LED3_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED3_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_3_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_3_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: led_4
 * Mode: Preset actions (multi-segment animation)
 * Segments: 4
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
    
    // Segment 1: Wait 2300ms
    if (led_4_timer_cnt > seg0_start && led_4_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (led_4_timer_cnt > seg1_start && led_4_timer_cnt <= seg1_end) {
            // Change image: /resource/LED4_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED4_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: Wait 1560ms
    else if (led_4_timer_cnt > seg2_start && led_4_timer_cnt <= seg2_end) {
        // No action, just wait
    }
    // Segment 4: 300ms, 1 action(s)
    else if (led_4_timer_cnt > seg3_start && led_4_timer_cnt <= seg3_end) {
            // Change image: /resource/LED4_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED4_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_4_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_4_timer_cnt = 0; // Reset counter
    }
}


/**
 * entrance
 * Component: led_5
 * Mode: Preset actions (multi-segment animation)
 * Segments: 4
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
    
    // Segment 1: Wait 2000ms
    if (led_5_timer_cnt > seg0_start && led_5_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 300ms, 1 action(s)
    else if (led_5_timer_cnt > seg1_start && led_5_timer_cnt <= seg1_end) {
            // Change image: /resource/LED5_on.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED5_on.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    // Segment 3: Wait 2160ms
    else if (led_5_timer_cnt > seg2_start && led_5_timer_cnt <= seg2_end) {
        // No action, just wait
    }
    // Segment 4: 300ms, 1 action(s)
    else if (led_5_timer_cnt > seg3_start && led_5_timer_cnt <= seg3_end) {
            // Change image: /resource/LED5_off.bin
            gui_img_set_src((gui_img_t *)target, (const uint8_t *)"/resource/LED5_off.bin", IMG_SRC_FILESYS);
            gui_img_refresh_size((gui_img_t *)target);
            
    }
    
    if (led_5_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        led_5_timer_cnt = 0; // Reset counter
    }
}


/**
 * pos func
 * Component: win_speed_text
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_speed_text_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_speed_text_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_speed_text_timer_cnt > seg0_start && win_speed_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_speed_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust position: (38, 64) -> (38, -30)
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
        win_speed_text_timer_cnt = 0; // Reset counter
    }
}


/**
 * pos default
 * Component: win_speed_text
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_speed_text_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_speed_text_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_speed_text_timer_cnt > seg0_start && win_speed_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_speed_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust position: (38, -30) -> (38, 64)
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
        win_speed_text_timer_cnt = 0; // Reset counter
    }
}


/**
 * func pos
 * Component: win_power_text
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_power_text_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_power_text_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_power_text_timer_cnt > seg0_start && win_power_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_power_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust position: (470, 64) -> (470, -30)
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
        win_power_text_timer_cnt = 0; // Reset counter
    }
}


/**
 * default pos
 * Component: win_power_text
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void win_power_text_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 1;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 1;
    
    win_power_text_timer_cnt++;
    
    // Segment 1: 20ms, 1 action(s)
    if (win_power_text_timer_cnt > seg0_start && win_power_text_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = win_power_text_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust position: (470, -30) -> (470, 64)
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
        win_power_text_timer_cnt = 0; // Reset counter
    }
}


/**
 * volume
 * Component: win_volume
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void win_volume_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 3;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 2;
    const uint16_t seg1_start = 2;
    const uint16_t seg1_end = 3;
    
    win_volume_timer_cnt++;
    
    // Segment 1: Wait 2000ms
    if (win_volume_timer_cnt > seg0_start && win_volume_timer_cnt <= seg0_end) {
        // No action, just wait
    }
    // Segment 2: 1000ms, 1 action(s)
    else if (win_volume_timer_cnt > seg1_start && win_volume_timer_cnt <= seg1_end) {
            // Set visibility: hide
            gui_obj_hidden(target, true);
            
    }
    
    if (win_volume_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        win_volume_timer_cnt = 0; // Reset counter
    }
}


/* @protected start custom_functions */
// Custom functions
void text_odo_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_text_content_set(obj, odo_str, strlen(odo_str));
}

void text_battery_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_text_content_set(obj, batt_str, strlen(batt_str));
}

char speed_str[6] = {0};
void text_speed_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    dashboard_info.speed_val += 10;
    dashboard_info.speed_val %= 160;
    sprintf(speed_str, "%u", dashboard_info.speed_val);
    gui_text_content_set(obj, speed_str, strlen(speed_str));

    const void *img_data_array[16] =
    {
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
    uint16_t index = dashboard_info.speed_val / 10;
    gui_img_set_src(speed_arc, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);

    const float angle_origin = 0;
    const float angle_target = 360;
    float angle_cur = angle_origin + (angle_target - angle_origin) * (index + 1) / 16;
    gui_img_rotation(dail_pointer_s, angle_cur);
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
    
    if (cnt > seg0_start && cnt <= seg0_end) {
        // wait
        dashboard_info.speed_val = 0;
    }
    else if (cnt > seg1_start && cnt <= seg1_end) {
        dashboard_info.speed_val += 10;
    }
    else if (cnt > seg2_start && cnt <= seg2_end) {
        dashboard_info.speed_val -= 10;
    }
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // wait
    }
    else if (cnt > seg4_start && cnt <= seg4_end) {
            gui_obj_create_timer(obj, 100, true, text_speed_timer_0_cb);
            gui_obj_start_timer(obj);
            // gui_obj_stop_timer(obj);
            cnt = 0;
            return;
    }
    sprintf(speed_str, "%u", dashboard_info.speed_val);
    gui_text_content_set(obj, speed_str, strlen(speed_str));
}

char power_str[6] = {0};
void text_power_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    dashboard_info.power_val += 10;
    dashboard_info.power_val %= 160;
    sprintf(power_str, "%u", dashboard_info.power_val);
    gui_text_content_set(obj, power_str, strlen(power_str));

    const void *img_data_array[16] =
    {
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
    uint16_t index = dashboard_info.power_val / 10;
    gui_img_set_src(power_arc, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);

    const float angle_origin = 0;
    const float angle_target = -360;
    float angle_cur = angle_origin + (angle_target - angle_origin) * (index + 1) / 16;
    gui_img_rotation(dail_pointer_p, angle_cur);
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
    
    if (cnt > seg0_start && cnt <= seg0_end) {
        // wait
        dashboard_info.power_val = 0;
    }
    else if (cnt > seg1_start && cnt <= seg1_end) {
        dashboard_info.power_val += 10;
    }
    else if (cnt > seg2_start && cnt <= seg2_end) {
        dashboard_info.power_val -= 10;
    }
    else if (cnt > seg3_start && cnt <= seg3_end) {
        // wait
    }
    else if (cnt > seg4_start && cnt <= seg4_end) {
            gui_obj_create_timer(obj, 100, true, text_power_timer_0_cb);
            gui_obj_start_timer(obj);
            // gui_obj_stop_timer(obj);
            cnt = 0;
            return;
    }
    sprintf(power_str, "%u", dashboard_info.power_val);
    gui_text_content_set(obj, power_str, strlen(power_str));
}

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

uint8_t app_index = 0;

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

void app_list_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_list_set_offset(obj, 0);
    gui_obj_stop_timer(obj);
}

void app_list_timer_1_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_list_set_offset(obj, -280);
    gui_obj_stop_timer(obj);
}

uint8_t weather_note_index = 0;
void list_weather_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_list_set_offset(obj, weather_note_index * -280);
    gui_obj_stop_timer(obj);
}

char volume_str[4] = {0};
void lbl_volume_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    sprintf(volume_str, "%u", dashboard_info.volume_val);
    gui_text_content_set(obj, volume_str, strlen(volume_str));
}

void win_music_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    if (dashboard_info.music_play_time < dashboard_info.music_duration)
    {
        if (dashboard_info.music_status == true)
        {
            dashboard_info.music_play_time += 1;
        }
        GUI_BASE(win_playbar)->w = 250 * dashboard_info.music_play_time / dashboard_info.music_duration;
    }
}

void carplay_music_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    if (dashboard_info.music_play_time < dashboard_info.music_duration)
    {
        if (dashboard_info.music_status == true)
        {
            dashboard_info.music_play_time += 1;
        }
        GUI_BASE(win_music_bar)->w = 250 * dashboard_info.music_play_time / dashboard_info.music_duration;
    }
}

void dashboard_entrance_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    gui_view_t *view_c = gui_view_get_current();
    if (view_c && strcmp(view_c->base.name, "carplay_view") == 0) // no entrance animation
    {
        gui_obj_create_timer((gui_obj_t *)map, 1000, true, map_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)map);
        gui_obj_hidden((gui_obj_t *)map, false);

        dashboard_info.speed_val = 0;
        dashboard_info.power_val = 0;
        gui_obj_create_timer((gui_obj_t *)text_speed, 100, true, text_speed_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)text_speed);
        gui_obj_create_timer((gui_obj_t *)text_power, 100, true, text_power_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)text_power);
    }
    else
    {
        gui_obj_create_timer((gui_obj_t *)map, 6000, true, map_timer_1_cb);
        gui_obj_start_timer((gui_obj_t *)map);

        gui_obj_create_timer((gui_obj_t *)win_dail, 10, true, win_dail_timer_0_cb);

        gui_obj_create_timer((gui_obj_t *)speed_arc, 30, true, speed_arc_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)speed_arc);
        gui_obj_create_timer((gui_obj_t *)dail_pointer_s, 30, true, dail_pointer_s_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)dail_pointer_s);

        gui_obj_create_timer((gui_obj_t *)power_arc, 30, true, power_arc_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)power_arc);
        gui_obj_create_timer((gui_obj_t *)dail_pointer_p, 30, true, dail_pointer_p_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)dail_pointer_p);

        gui_obj_create_timer((gui_obj_t *)win_common, 20, true, win_common_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)win_common);

        gui_obj_create_timer((gui_obj_t *)turn_l_icon, 30, true, turn_l_icon_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)turn_l_icon);
        gui_obj_create_timer((gui_obj_t *)turn_r_icon, 30, true, turn_r_icon_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)turn_r_icon);
        gui_obj_create_timer((gui_obj_t *)led_0, 30, true, led_0_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)led_0);
        gui_obj_create_timer((gui_obj_t *)led_1, 30, true, led_1_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)led_1);
        gui_obj_create_timer((gui_obj_t *)led_2, 30, true, led_2_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)led_2);
        gui_obj_create_timer((gui_obj_t *)led_3, 30, true, led_3_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)led_3);
        gui_obj_create_timer((gui_obj_t *)led_4, 30, true, led_4_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)led_4);
        gui_obj_create_timer((gui_obj_t *)led_5, 30, true, led_5_timer_0_cb);
        gui_obj_start_timer((gui_obj_t *)led_5);

        gui_obj_create_timer((gui_obj_t *)win_speed_text, 8, true, win_speed_text_timer_0_cb);
        gui_obj_create_timer((gui_obj_t *)win_power_text, 8, true, win_power_text_timer_0_cb);

        gui_obj_create_timer((gui_obj_t *)text_speed, 30, true, text_speed_timer_1_cb);
        gui_obj_start_timer((gui_obj_t *)text_speed);
        gui_obj_create_timer((gui_obj_t *)text_power, 30, true, text_power_timer_1_cb);
        gui_obj_start_timer((gui_obj_t *)text_power);
    }

    if (dashboard_info.cover != NULL)
    {
#ifdef _HONEYGUI_SIMULATOR_
        gui_img_set_src(music_cover, (const uint8_t *)dashboard_info.cover, IMG_SRC_FILESYS);
#else
    // gui_img_set_src(music_cover, (const uint8_t *)dashboard_info.cover, IMG_SRC_MEMADDR); // A8565 100*100
#endif
        gui_text_content_set(lbl_music, dashboard_info.music_name, strlen(dashboard_info.music_name));
        gui_text_content_set(lbl_artist, dashboard_info.artist_name, strlen(dashboard_info.artist_name));
        gui_scroll_text_content_set(lbl_lyrics, dashboard_info.lyrics, strlen(dashboard_info.lyrics));
    }
    if (dashboard_info.music_status)
    {
        gui_obj_hidden(GUI_BASE(win_music), false);
        gui_obj_hidden(GUI_BASE(map), true);
    }
    menu_disp = false;

    gui_obj_stop_timer(obj);
}

// Carplay view
void carplay_speed_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    dashboard_info.speed_val += 10;
    dashboard_info.speed_val %= 160;
    sprintf(speed_str, "%u", dashboard_info.speed_val);
    gui_text_content_set(carplay_speed, speed_str, strlen(speed_str));

    const void *img_data_array[16] =
    {
        "/resource/carplay/sp_arc_00.bin",
        "/resource/carplay/sp_arc_01.bin",
        "/resource/carplay/sp_arc_02.bin",
        "/resource/carplay/sp_arc_03.bin",
        "/resource/carplay/sp_arc_04.bin",
        "/resource/carplay/sp_arc_05.bin",
        "/resource/carplay/sp_arc_06.bin",
        "/resource/carplay/sp_arc_07.bin",
        "/resource/carplay/sp_arc_08.bin",
        "/resource/carplay/sp_arc_09.bin",
        "/resource/carplay/sp_arc_10.bin",
        "/resource/carplay/sp_arc_11.bin",
        "/resource/carplay/sp_arc_12.bin",
        "/resource/carplay/sp_arc_13.bin",
        "/resource/carplay/sp_arc_14.bin",
        "/resource/carplay/sp_arc_15.bin",
    };
    uint16_t index = dashboard_info.speed_val / 10;
    gui_img_set_src((gui_img_t *)carplay_speed_arc, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
}

void carplay_entrance_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    if (dashboard_info.music_status)
    {
        dashboard_info.music_duration = dashboard_info.music_duration;
        dashboard_info.music_play_time = dashboard_info.music_play_time;
        if (dashboard_info.cover != NULL)
        {
#ifdef _HONEYGUI_SIMULATOR_
            gui_img_set_src(carplay_music_cover, (const uint8_t *)dashboard_info.cover, IMG_SRC_FILESYS);
#else
            gui_img_set_src(carplay_music_cover, (const uint8_t *)dashboard_info.cover, IMG_SRC_MEMADDR); // A8565 100*100
#endif
            gui_img_set_src(carplay_music_play, (const uint8_t *)"/resource/carplay/icon_media_pause.bin", IMG_SRC_FILESYS);
            gui_scroll_text_content_set(carplay_music_name, dashboard_info.music_name, strlen(dashboard_info.music_name));
            gui_scroll_text_content_set(carplay_music_artist, dashboard_info.artist_name, strlen(dashboard_info.artist_name));
            gui_scroll_text_content_set(carplay_music_lyrics, dashboard_info.lyrics, strlen(dashboard_info.lyrics));
        }
    }
    else
    {
        if (dashboard_info.cover != NULL)
        {
            gui_img_set_src(carplay_music_play, (const uint8_t *)"/resource/carplay/icon_media_play.bin", IMG_SRC_FILESYS);
        }
    }
    gui_obj_stop_timer(obj);
}

/* @protected end custom_functions */
