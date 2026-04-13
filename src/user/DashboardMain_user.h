#ifndef DASHBOARDMAIN_USER_H
#define DASHBOARDMAIN_USER_H

#include "../callbacks/DashboardMain_callbacks.h"
#include "../ui/DashboardMain_ui.h"

/**
 * User-defined header file
 * This file is generated once only, feel free to modify
 */

// Msg callback declarations (called from DashboardMain_callbacks.c)
void root_menu_msg_show_cb(void *obj, gui_event_t *e);
void root_menu_msg_hide_cb(void *obj, gui_event_t *e);
void root_menu_msg_enter_cb(void *obj, gui_event_t *e);
void win_app_list_msg_enter_cb(void *obj, gui_event_t *e);
void win_app_list_msg_exit_cb(void *obj, gui_event_t *e);
void win_app_list_msg_next_cb(void *obj, gui_event_t *e);
void win_app_weather_msg_next_cb(void *obj, gui_event_t *e);
void win_app_weather_msg_exit_cb(void *obj, gui_event_t *e);
void win_app_developing_msg_exit_cb(void *obj, gui_event_t *e);

#endif // DASHBOARDMAIN_USER_H
