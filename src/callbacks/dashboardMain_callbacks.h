#ifndef DASHBOARDMAIN_CALLBACKS_H
#define DASHBOARDMAIN_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"

// 事件回调函数声明
void off_icon_switch_view_cb(void *obj, gui_event_t event, void *param);
void start_engine_animation_set_0_cb(void *obj, gui_event_t event, void *param);
void start_engine_animation_set_1_cb(void *obj, gui_event_t event, void *param);

// 用户配置的定时器回调函数声明
void bg_gloom_timer_0_cb(void *obj);
void shadow_timer_0_cb(void *obj);
void shadow_timer_1_cb(void *obj);
void win_map_timer_0_cb(void *obj);
void text_time_timer_0_cb(void *obj);

#endif // DASHBOARDMAIN_CALLBACKS_H
