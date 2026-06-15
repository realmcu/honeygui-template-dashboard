#ifndef DASHBOARDMAIN_USER_H
#define DASHBOARDMAIN_USER_H

#include "../callbacks/DashboardMain_callbacks.h"
#include "../ui/DashboardMain_ui.h"

/**
 * User-defined header file
 * This file is generated once only, feel free to modify
 */
typedef struct gui_dashboard
{
    /* BT & WIFI status */
    uint32_t bt_status         : 1; // bluetooth status, 1: on, 0: off
    uint32_t wifi_status       : 1; // wifi status, 1: on, 0: off

    /* LED status */
    uint32_t led0_status       : 1; // 1: on, 0: off
    uint32_t led1_status       : 1;
    uint32_t led2_status       : 1;
    uint32_t led3_status       : 1;
    uint32_t led4_status       : 1;
    uint32_t led5_status       : 1;
    uint32_t led_turn_l_status : 1;
    uint32_t led_turn_r_status : 1;

    /* Music status */
    uint32_t music_status      : 1; // 1: on, 0: off
    uint32_t volume_val        : 8; // 0-100
    uint32_t music_play_time   : 10; // Second
    uint32_t music_duration    : 10; // Second

    // /* Map status */
    // uint32_t map_data_update   : 1;
    // uint32_t map_data_index    : 1;
    // void *map_data[2];     // map data pointer

    // /* OTA status */
    // uint32_t ota_in_progress   : 1; // OTA in progress flag

    // /* Message notification status */
    // uint32_t message_notify    : 1; // Message notification flag

    // /* Navigation status */
    // uint32_t navi_active       : 1; // Navigation active flag (NAVI_START=1, NAVI_IDLE/NAVI_PAUSE=0)

    uint32_t speed_val       : 16; // km/h
    uint32_t power_val       : 16; // kW
    uint32_t odo_val         : 8; // km
    uint32_t soc_val         : 8; // %
    uint32_t temp_val        : 6; // °C
    

    char location[24];

    // /* OTA data */
    // uint32_t ota_total_num;
    // uint32_t ota_current_num;

    // /* Message notification data */
    // char message_text[128];
    // uint16_t message_length;
    // uint8_t message_type;

    // /* Phone call status */
    // uint32_t phone_active      : 1; // Phone call active flag
    // uint32_t phone_calling     : 1; // In call flag

    // char phone_number[16];           // Phone number
    // uint8_t phone_number_len;        // Phone number length

} gui_dashboard_t;

typedef struct gui_music_info
{
    char *music_name;
    char *artist_name;
    char *lyrics;
    void *cover;
    uint32_t music_play_time    :10; // Second
    uint32_t music_duration     :10; // Second
    uint32_t music_status       :1; // 1: on, 0: off
} gui_music_info_t;

/*------------------------------------------*/
extern gui_dashboard_t dashboard_info;
extern char odo_str[12];
extern char batt_str[12];



/*------------------------------------------*/

// Msg callback declarations (called from DashboardMain_callbacks.c)
void root_menu_msg_show_cb(void *obj, gui_event_t *e);
void root_menu_msg_hide_cb(void *obj, gui_event_t *e);
void root_menu_msg_left_cb(void *obj, gui_event_t *e);
void root_menu_msg_right_cb(void *obj, gui_event_t *e);
void root_menu_msg_enter_cb(void *obj, gui_event_t *e);
void win_app_list_msg_enter_cb(void *obj, gui_event_t *e);
void win_app_list_msg_exit_cb(void *obj, gui_event_t *e);
void win_app_list_msg_last_cb(void *obj, gui_event_t *e);
void win_app_list_msg_next_cb(void *obj, gui_event_t *e);
void win_app_weather_msg_next_cb(void *obj, gui_event_t *e);
void win_app_weather_msg_exit_cb(void *obj, gui_event_t *e);
void win_app_developing_msg_exit_cb(void *obj, gui_event_t *e);


void update_dashbord_power(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_speed(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led0(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led1(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led2(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led3(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led4(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led5(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led_turn_l(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_led_turn_r(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_bt(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_wifi(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_volume(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_location(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_temp(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_music_play(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_odo(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_batt(gui_obj_t *obj, const char *topic, void *data, uint16_t len);
void update_dashbord_map(gui_obj_t *obj, const char *topic, void *data, uint16_t len);




#endif // DASHBOARDMAIN_USER_H
