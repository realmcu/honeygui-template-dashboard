#ifndef DASHBOARDMAIN_CALLBACKS_H
#define DASHBOARDMAIN_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"

// 事件回调函数声明
void off_icon_switch_view_cb(void *obj, gui_event_t event, void *param);
void start_engine_animation_set_0_cb(void *obj, gui_event_t event, void *param);
void start_engine_animation_set_1_cb(void *obj, gui_event_t event, void *param);

// 用户配置的定时器回调函数声明
void gloom_timer_0_cb(void *obj);
void shadow_timer_0_cb(void *obj);
void shadow_timer_1_cb(void *obj);
void win_map_timer_0_cb(void *obj);
void map_timer_0_cb(void *obj);
void map_timer_1_cb(void *obj);
void root_menu_timer_0_cb(void *obj);
void root_menu_timer_1_cb(void *obj);
void root_menu_timer_2_cb(void *obj);
void root_menu_timer_3_cb(void *obj);
void root_menu_timer_4_cb(void *obj);
void root_menu_timer_5_cb(void *obj);
void root_menu_timer_6_cb(void *obj);
void root_menu_timer_7_cb(void *obj);
void root_menu_timer_8_cb(void *obj);
void root_menu_timer_9_cb(void *obj);
void root_menu_timer_10_cb(void *obj);
void win_dail_timer_0_cb(void *obj);
void win_line_timer_0_cb(void *obj);
void line_left_timer_0_cb(void *obj);
void line_right_timer_0_cb(void *obj);
void speed_arc_timer_0_cb(void *obj);
void speed_arc_timer_1_cb(void *obj);
void dail_pointer_s_timer_0_cb(void *obj);
void dail_pointer_s_timer_1_cb(void *obj);
void power_arc_timer_0_cb(void *obj);
void power_arc_timer_1_cb(void *obj);
void dail_pointer_p_timer_0_cb(void *obj);
void dail_pointer_p_timer_1_cb(void *obj);
void win_common_timer_0_cb(void *obj);
void turn_l_icon_timer_0_cb(void *obj);
void turn_r_icon_timer_0_cb(void *obj);
void text_time_timer_0_cb(void *obj);
void led_0_timer_0_cb(void *obj);
void led_1_timer_0_cb(void *obj);
void led_2_timer_0_cb(void *obj);
void led_3_timer_0_cb(void *obj);
void led_4_timer_0_cb(void *obj);
void led_5_timer_0_cb(void *obj);
void win_speed_text_timer_0_cb(void *obj);
void text_speed_timer_0_cb(void *obj);
void text_speed_timer_1_cb(void *obj);
void win_power_text_timer_0_cb(void *obj);
void text_power_timer_0_cb(void *obj);
void text_power_timer_1_cb(void *obj);

// 自定义函数声明（从 callbacks.c 保护区自动提取）
void text_speed_timer_0_cb(void *obj);
void text_speed_timer_1_cb(void *obj);
void text_power_timer_0_cb(void *obj);
void text_power_timer_1_cb(void *obj);
void text_time_timer_0_cb(void *obj);
void zoom_animation(gui_obj_t *obj, float scale);
void win_speed_text_timer_0_cb(void *obj);
void win_power_text_timer_0_cb(void *obj);
void root_menu_msg_up_cb(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void root_menu_msg_down_cb(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void root_menu_msg_left_cb(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void root_menu_msg_right_cb(gui_obj_t *obj, const char *topic, void *data, uint16_t len);

#endif // DASHBOARDMAIN_CALLBACKS_H
