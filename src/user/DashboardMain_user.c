#include "DashboardMain_user.h"
#include "stream_transport.h"
#include "gui_vfs.h"
#ifndef _HONEYGUI_SIMULATOR_
#include "dashboard_img_rx.h"
#endif
#ifdef _HONEYGUI_SIMULATOR_
#include "shell.h"
#endif

/**
 * User-defined implementation
 * This file is generated once only, feel free to modify
 */

// Msg callback stubs (called from DashboardMain_callbacks.c)
gui_dashboard_t dashboard_info =
{
    .bt_status = 0,
    .wifi_status = 0,
    .led0_status = 0,
    .led1_status = 0,
    .led2_status = 0,
    .led3_status = 0,
    .led4_status = 0,
    .led5_status = 0,
    .led_turn_l_status = 0,
    .led_turn_r_status = 0,
    .speed_val = 0,
    .power_val = 0,
    .odo_val = 0,
    .soc_val = 0,
    .temp_val = 25,
    .location = "Suzhou",
};


bool menu_disp = false;
static char top_info_str[30];
static uint8_t menu_func_index = 0;
extern uint8_t app_index;
extern uint8_t weather_note_index;
extern char power_str[6];
extern char speed_str[6];
char odo_str[12] = "ODO 300km";
char batt_str[12] = "BATT 65%";

#define MUSIC_COUNT  4
uint8_t music_index = 0;
uint8_t lyrics_index = 0;

uint16_t music_time_array[MUSIC_COUNT] =
{
    300, //Second
    320, 
    340, 
    360,
};

const char *music_cover_array[MUSIC_COUNT] = 
{
    "/resource/music/COVER_0.bin",
    "/resource/music/COVER_1.bin",
    "/resource/music/COVER_2.bin",
    "/resource/music/COVER_3.bin",
};

const char *music_name_array[MUSIC_COUNT] = 
{
    "Music 0",
    "Music 1",
    "Music 2",
    "Music 3",
};

const char *artist_name_array[MUSIC_COUNT] = 
{
    "Artist 0",
    "Artist 1",
    "Artist 2",
    "Artist 3",
};

const char *lyrics_array[MUSIC_COUNT] = 
{
    "Lyrics 0000000000",
    "Lyrics 1111111111111",
    "Lyrics 22222222222222222",
    "Lyrics 333333333333333333333",
};

// Update dashboard info by shell command
#ifdef _HONEYGUI_SIMULATOR_
void dashboard_info_update(int argc, char *argv[])
{
    // if (get_dashboard_info() == NULL) { return; }
    int i = 1;
    // gui_log("dashboard_info_update: %d, %s", argc, argv[0]);
    while (i < argc)
    {
        if (!strcmp(argv[i], "map"))
        {
            static uint8_t map_index = 0;
            map_index++;
            map_index %= 13;
            gui_msg_publish("map", &map_index, sizeof(uint8_t));
        }
        else if (!strcmp(argv[i], "speed"))
        {
            uint16_t speed = atoi(argv[++i]);
            gui_msg_publish("speed", &speed, sizeof(uint16_t));
        }
        else if (!strcmp(argv[i], "power"))
        {
            uint16_t power = atoi(argv[++i]);
            gui_msg_publish("power", &power, sizeof(uint16_t));
        }
        else if (!strcmp(argv[i], "odo"))
        {
            uint16_t odo_val = atoi(argv[++i]);
            gui_msg_publish("odo", &odo_val, sizeof(uint16_t));
        }
        else if (!strcmp(argv[i], "battery"))
        {
            uint16_t batt_val = atoi(argv[++i]);
            gui_msg_publish("battery", &batt_val, sizeof(uint16_t));
        }
        else if (!strcmp(argv[i], "location"))
        {
            char *location = argv[++i];
            gui_msg_publish("location", location, sizeof(location));
        }
        else if (!strcmp(argv[i], "temp"))
        {
            uint8_t temp = atoi(argv[++i]);
            gui_msg_publish("temp", &temp, sizeof(uint8_t));
        }
        else if (!strcmp(argv[i], "turnl"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("turnl", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "turnr"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("turnr", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "bt"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("bt", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "wifi"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("wifi", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "led0"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("led0", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "led1"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("led1", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "led2"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("led2", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "led3"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("led3", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "led4"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("led4", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "led5"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("led5", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "volume"))
        {
            bool status = atoi(argv[++i]);
            gui_msg_publish("volume", &status, sizeof(bool));
        }
        else if (!strcmp(argv[i], "play"))
        {
            bool status = atoi(argv[++i]);
            gui_music_info_t music_info = 
            {
                .music_name = (char *)music_name_array[music_index],
                .artist_name = (char *)artist_name_array[music_index],
                .lyrics = (char *)lyrics_array[lyrics_index],
                .cover = (void *)music_cover_array[music_index],
                .music_duration = music_time_array[music_index],
                .music_status = status,
                .music_play_time = dashboard_info.music_play_time,
            };
            gui_msg_publish("play", &music_info, sizeof(gui_music_info_t));
        }
        else if (!strcmp(argv[i], "next"))
        {
            music_index = (music_index + 1) % MUSIC_COUNT;
            lyrics_index = 0;
            gui_music_info_t music_info = 
            {
                .music_name = (char *)music_name_array[music_index],
                .artist_name = (char *)artist_name_array[music_index],
                .lyrics = (char *)lyrics_array[lyrics_index],
                .cover = (void *)music_cover_array[music_index],
                .music_duration = music_time_array[music_index],
                .music_status = 1,
                .music_play_time = 0,
            };
            gui_msg_publish("play", &music_info, sizeof(gui_music_info_t));
        }
        else if (!strcmp(argv[i], "last"))
        {
            music_index = (music_index - 1 + MUSIC_COUNT) % MUSIC_COUNT;
            lyrics_index = 0;
            gui_music_info_t music_info = 
            {
                .music_name = (char *)music_name_array[music_index],
                .artist_name = (char *)artist_name_array[music_index],
                .lyrics = (char *)lyrics_array[lyrics_index],
                .cover = (void *)music_cover_array[music_index],
                .music_duration = music_time_array[music_index],
                .music_status = 1,
                .music_play_time = 0,
            };
            gui_msg_publish("play", &music_info, sizeof(gui_music_info_t));
        }
        else if (!strcmp(argv[i], "lyrics"))
        {
            lyrics_index = (lyrics_index + 1) % MUSIC_COUNT;
            gui_music_info_t music_info = 
            {
                .music_name = (char *)music_name_array[music_index],
                .artist_name = (char *)artist_name_array[music_index],
                .lyrics = (char *)lyrics_array[lyrics_index],
                .cover = (void *)music_cover_array[music_index],
                .music_duration = music_time_array[music_index],
                .music_status = dashboard_info.music_status,
                .music_play_time = dashboard_info.music_play_time,
            };
            gui_msg_publish("play", &music_info, sizeof(gui_music_info_t));
        }
        ++i;
    }
}
SHELL_EXPORT_CMD(
    SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN) | SHELL_CMD_DISABLE_RETURN,
    cmd, dashboard_info_update, test);
#endif

void root_menu_msg_show_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
    if (!menu_disp)
    {
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, root_menu_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
        gui_obj_hidden(GUI_BASE(win_music), true);
        gui_obj_hidden(GUI_BASE(map), true);
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

void root_menu_msg_enter_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden || !menu_disp)
    {
#ifdef DASHBOARD_USE_THIRD_PARTY_NAV
        gui_view_switch_direct(gui_view_get_current(), "third_party_nav_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
#else
        gui_view_switch_direct(gui_view_get_current(), "carplay_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
#endif
        return;
    }
    
    switch (menu_func_index)
    {
    case 0:
        gui_obj_hidden(GUI_BASE(map), false);
        gui_obj_create_timer(GUI_BASE(win_dail), 10, true, win_dail_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_dail));
        gui_obj_create_timer(GUI_BASE(win_speed_text), 10, true, win_speed_text_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_speed_text));
        gui_obj_create_timer(GUI_BASE(win_power_text), 10, true, win_power_text_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_power_text));
        GUI_BASE(obj)->y = 480;
        menu_disp = false;
        break;
    case 1:
        gui_obj_create_timer(GUI_BASE(win_func), 10, true, win_func_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(win_func));
        gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(win_app_list));
        gui_obj_hidden(GUI_BASE(map), true);
        gui_obj_create_timer(GUI_BASE(win_dail), 10, true, win_dail_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_dail));
        gui_obj_create_timer(GUI_BASE(win_speed_text), 10, true, win_speed_text_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_speed_text));
        gui_obj_create_timer(GUI_BASE(win_power_text), 10, true, win_power_text_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_power_text));
        GUI_BASE(obj)->y = 480;
        menu_disp = false;
        break;
    case 2:
        gui_obj_hidden(GUI_BASE(map), true);
        gui_obj_hidden(GUI_BASE(win_music), false);
        GUI_BASE(obj)->y = 480;
        menu_disp = false;
        break;
    default:
        break;
    }
}

void root_menu_msg_hide_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
    if (menu_disp)
    {
        gui_obj_create_timer(GUI_BASE(root_menu), 10, true, root_menu_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(root_menu));
        menu_disp = false;
    }
}

void root_menu_msg_left_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
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

void root_menu_msg_right_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
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

void win_app_list_msg_enter_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
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

void win_app_list_msg_exit_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
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
    dashboard_info.speed_val = 0;
    dashboard_info.power_val = 0;
}

void win_app_list_msg_last_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
    if (app_index == 0) return;
    app_index--;
    if (app_index == 2)
    {
        gui_obj_create_timer(GUI_BASE(app_list), 10, true, app_list_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(app_list));
    }
}

void win_app_list_msg_next_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
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

void win_app_developing_msg_exit_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
    gui_obj_create_timer(GUI_BASE(win_app_developing), 10, true, win_app_developing_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_developing));
}

void win_app_weather_msg_next_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
    weather_note_index++;
    weather_note_index %= 2;
    gui_obj_create_timer(GUI_BASE(list_weather), 10, true, list_weather_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(list_weather));
}

void win_app_weather_msg_exit_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->hidden) return;
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
    gui_obj_create_timer(GUI_BASE(win_app_weather), 10, true, win_app_weather_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_weather));
}

void update_dashboard_speed(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.speed_val = (*(uint16_t *)data) % 160;
    sprintf(speed_str, "%u", dashboard_info.speed_val);
    if (obj == (gui_obj_t *)win_common)
    {
        gui_text_content_set(text_speed, speed_str, strlen(speed_str));

        const void *img_data_array[16] = 
        {
            "/resource/speed_arc/speed_arc_00.bin",
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
        };
        uint16_t index = dashboard_info.speed_val / 10;
        gui_img_set_src(speed_arc, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
        gui_img_refresh_size(speed_arc);

        gui_img_rotation(dail_pointer_s, 360.f * index / 16.f);

        gui_obj_stop_timer(GUI_BASE(dail_pointer_s));
        gui_obj_stop_timer(GUI_BASE(speed_arc));
        gui_obj_stop_timer(GUI_BASE(text_speed));
    }
    else
    {
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
        gui_obj_stop_timer(GUI_BASE(carplay_speed_arc));
    }
}

void update_dashboard_power(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    dashboard_info.power_val = (*(uint16_t *)data) % 160;
    sprintf(power_str, "%u", dashboard_info.power_val);
    gui_text_content_set(text_power, power_str, strlen(power_str));
    
    const void *img_data_array[16] = 
    {
        "/resource/power_arc/power_arc_00.bin",
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
    };
    uint16_t index = dashboard_info.power_val / 10;
    gui_img_set_src(power_arc, (const uint8_t *)img_data_array[index], IMG_SRC_FILESYS);
    gui_img_refresh_size(power_arc);

    gui_img_rotation(dail_pointer_p, -360.f * index / 16.f);

    gui_obj_stop_timer(GUI_BASE(dail_pointer_p));
    gui_obj_stop_timer(GUI_BASE(power_arc));
    gui_obj_stop_timer(GUI_BASE(text_power));
}

void update_dashboard_led0(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led0_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led0_status)
    {
        img_data = "/resource/LED0_on.bin";
    }
    else
    {
        img_data = "/resource/LED0_off.bin";
    }
    gui_img_set_src((gui_img_t *)led_0, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led1(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led1_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led0_status)
    {
        img_data = "/resource/LED1_on.bin";
    }
    else
    {
        img_data = "/resource/LED1_off.bin";
    }
    gui_img_set_src((gui_img_t *)led_1, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led2(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led2_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led2_status)
    {
        img_data = "/resource/LED2_on.bin";
    }
    else
    {
        img_data = "/resource/LED2_off.bin";
    }
    gui_img_set_src((gui_img_t *)led_2, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led3(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led3_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led3_status)
    {
        img_data = "/resource/LED3_on.bin";
    }
    else
    {
        img_data = "/resource/LED3_off.bin";
    }
    gui_img_set_src((gui_img_t *)led_3, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led4(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led4_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led4_status)
    {
        img_data = "/resource/LED4_on.bin";
    }
    else
    {
        img_data = "/resource/LED4_off.bin";
    }
    gui_img_set_src((gui_img_t *)led_4, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led5(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led5_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led5_status)
    {
        img_data = "/resource/LED5_on.bin";
    }
    else
    {
        img_data = "/resource/LED5_off.bin";
    }
    gui_img_set_src((gui_img_t *)led_5, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led_turn_l(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led_turn_l_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led_turn_l_status)
    {
        img_data = "/resource/Turnleft_on.bin";
    }
    else
    {
        img_data = "/resource/Turnleft_off.bin";
    }
    gui_img_set_src((gui_img_t *)turn_l_icon, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_led_turn_r(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led_turn_r_status = *(bool *)data;
    void *img_data = NULL;
    if (dashboard_info.led_turn_l_status)
    {
        img_data = "/resource/Turnright_on.bin";
    }
    else
    {
        img_data = "/resource/Turnright_off.bin";
    }
    gui_img_set_src((gui_img_t *)turn_r_icon, (const uint8_t *)img_data, IMG_SRC_FILESYS);
}

void update_dashboard_bt(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.bt_status = *(bool *)data;
    uint8_t opacity = 122;
    if (dashboard_info.bt_status)
    {
        opacity = 255;
    }
    gui_img_set_opacity(bt_icon, opacity);
}

void update_dashboard_wifi(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.wifi_status = *(bool *)data;
    uint8_t opacity = 122;
    if (dashboard_info.wifi_status)
    {
        opacity = 255;
    }
    gui_img_set_opacity(wifi_icon, opacity);
}

void update_dashboard_volume(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    bool temp = *(bool *)data;
    if (temp)
    {
        if (dashboard_info.volume_val != 100)
        {
            dashboard_info.volume_val += 10;
        }
    }
    else
    {
        if (dashboard_info.volume_val != 0)
        {
            dashboard_info.volume_val -= 10;
        }
    }
    gui_obj_hidden(GUI_BASE(win_volume), false);
    win_volume_timer_cnt = 0;
    gui_obj_create_timer(GUI_BASE(win_volume), 1000, true, win_volume_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_volume));
}

void update_dashboard_location(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    snprintf(dashboard_info.location, len, "%s", (char *)data);
    sprintf(top_info_str, "%s %u°C", dashboard_info.location, dashboard_info.temp_val);
    if (obj == (gui_obj_t *)win_common)
    {
        gui_text_content_set(text_loc_temp, top_info_str, sizeof(top_info_str));
    }
    else
    {
        gui_text_content_set(carplay_loc_temp, top_info_str, sizeof(top_info_str));
    }  
}

void update_dashboard_temp(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.temp_val = *((uint8_t *)data);
    
    sprintf(top_info_str, "%s %u°C", dashboard_info.location, dashboard_info.temp_val);
    if (obj == (gui_obj_t *)win_common)
    {
        gui_text_content_set(text_loc_temp, top_info_str, sizeof(top_info_str));
    }
    else
    {
        gui_text_content_set(carplay_loc_temp, top_info_str, sizeof(top_info_str));
    }  
}

void update_dashboard_music_play(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    gui_music_info_t *music_info = (gui_music_info_t *)data;
    dashboard_info.music_status = music_info->music_status;
    if (obj == (gui_obj_t *)win_common)
    {
        if (dashboard_info.music_status)
        {
            dashboard_info.music_duration = music_info->music_duration;
            dashboard_info.music_play_time = music_info->music_play_time;
            dashboard_info.music_name = music_info->music_name;
            dashboard_info.artist_name = music_info->artist_name;
            dashboard_info.lyrics = music_info->lyrics;
            dashboard_info.cover = music_info->cover;
            if (dashboard_info.cover)
            {
#ifdef _HONEYGUI_SIMULATOR_
                gui_img_set_src(music_cover, (const uint8_t *)dashboard_info.cover, IMG_SRC_FILESYS);
#else
                gui_img_set_src(music_cover, (const uint8_t *)dashboard_info.cover, IMG_SRC_MEMADDR); // A8565 100*100
#endif
                gui_text_content_set(lbl_music, dashboard_info.music_name, strlen(dashboard_info.music_name));
                gui_text_content_set(lbl_artist, dashboard_info.artist_name, strlen(dashboard_info.artist_name));
                gui_scroll_text_content_set(lbl_lyrics, dashboard_info.lyrics, strlen(dashboard_info.lyrics));
                // gui_log("music play: %s %s %s", dashboard_info.music_name, dashboard_info.artist_name, dashboard_info.lyrics);
            }
        }
    }
    else
    {
        if (dashboard_info.music_status)
        {
            dashboard_info.music_duration = music_info->music_duration;
            dashboard_info.music_play_time = music_info->music_play_time;
            dashboard_info.music_name = music_info->music_name;
            dashboard_info.artist_name = music_info->artist_name;
            dashboard_info.lyrics = music_info->lyrics;
            dashboard_info.cover = music_info->cover;
            if (dashboard_info.cover)
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
            gui_img_set_src(carplay_music_play, (const uint8_t *)"/resource/carplay/icon_media_play.bin", IMG_SRC_FILESYS);        
        }
    }
}

void update_dashboard_odo(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);
    uint16_t odo_val = *((uint16_t *)data);
    sprintf(odo_str + 4, "%dkm", odo_val);
    if (obj == (gui_obj_t *)win_common)
    {
        gui_text_content_set(text_odo, odo_str, strlen(odo_str));
    }
    else
    {
        gui_text_content_set(carplay_odo, odo_str, strlen(odo_str));
    }
}

void update_dashboard_batt(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    uint16_t batt_val = *((uint16_t *)data);
    sprintf(batt_str + 5, "%d%%", batt_val);
    if (obj == (gui_obj_t *)win_common)
    {
        gui_text_content_set(text_battery, batt_str, strlen(batt_str));
    }
    else
    {
        gui_text_content_set(carplay_bat, batt_str, strlen(batt_str));
    }
}

void update_dashboard_map(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

#ifdef _HONEYGUI_SIMULATOR_
    gui_obj_stop_timer(GUI_BASE(map));
    const void *img_data_array[13] =
    {
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
    gui_img_set_src(map, img_data_array[*((uint8_t *)data)], IMG_SRC_FILESYS);
#endif
}

void carplay_map_release_cb(gui_view_t *view)
{
    carplay_map = NULL;
    map_streaming = NULL;
    (void)view;
#ifdef DASHBOARD_USE_WIFI_DISPLAY
    extern void dashboard_img_display_view_released(void);
    dashboard_img_display_view_released();
#endif
}

/* ============================ Live-video stream ============================
 *
 * This board owns a single live-video STP transport, created once at GUI init
 * via stp_instance_create() -- the transport allocates its own frame pool
 * internally through the porting allocator (stp_port_malloc). It is shared by:
 *
 *   producer : wifi/dashboard_img_rx.c (TCP RX -> stp_commit)
 *   consumer : the designer-generated gui_stream widget (stp_consume -> render)
 */
#ifndef _HONEYGUI_SIMULATOR_
#define APP_STREAM_MAX_FRAME   DASHBOARD_IMG_RX_MAX_JPEG
#else
#define APP_STREAM_MAX_FRAME   (256u * 1024u)
#endif
#define APP_STREAM_BUF_COUNT   4u

static const stp_class_cfg_t s_stream_classes[] =
{
    { .buf_size = APP_STREAM_MAX_FRAME, .buf_count = APP_STREAM_BUF_COUNT },
};

/* The one transport this board owns.  NULL until app_stream_transport_init()
 * has run; both ends fetch it through the getter below. */
static stp_transport_t *s_stream_tp = NULL;

/*
 * Shared accessor for the live-video transport.  Used by:
 *   - the designer gui_stream widget (consumer) to bind on creation, and
 *   - dashboard_img_rx.c (Wi-Fi producer) to push received JPEG frames.
 * Returns NULL before the transport has been created.
 */
stp_transport_t *gui_stream_transport_get(void)
{
    return s_stream_tp;
}

#ifdef _HONEYGUI_SIMULATOR_
/*--------------------------- Producer runtime -------------------------------*/
#define JPEG_MARK   0xFF
#define JPEG_SOI    0xD8
#define JPEG_EOI    0xD9
#define MAX_FRAME       (64u * 1024u)   /* per-buffer cap in the OS-port pool */

/* Producer-private state handed to the producer thread.  src/src_len point at
 * the encoded byte source; tp + interval_ms drive how frames are emitted. */
typedef struct
{
    stp_transport_t *tp;          /* shared transport (producer endpoint)     */
    const uint8_t   *src;         /* encoded source bytes                     */
    uint32_t         src_len;     /* length of the encoded source             */
    uint32_t         interval_ms; /* inter-frame pacing                       */
    volatile bool    running;     /* producer lifecycle flag                  */
} stream_producer_t;

static stream_producer_t s_producer;

static void producer_post_frame(stream_producer_t *prod, const uint8_t *payload,
                                uint32_t sz, bool keyframe)
{
    stp_frame_t f;

    while (prod->running)
    {
        if (stp_acquire_free(prod->tp, sz, &f))
        {
            memcpy(f.addr, payload, sz);              /* fill the buffer      */
            stp_commit(prod->tp, &f, sz, keyframe);   /* publish to consumer  */
            return;
        }
        gui_thread_mdelay(prod->interval_ms);         /* back-pressure        */
    }
}
static void mjpeg_producer_entry(void *param)
{
    stream_producer_t *prod = (stream_producer_t *)param;
    const uint8_t     *base = prod->src;
    const uint8_t     *end  = base + prod->src_len;
    const uint8_t     *cur  = base;

    while (prod->running)
    {
        while (cur + 1 < end && !(cur[0] == JPEG_MARK && cur[1] == JPEG_SOI))
        {
            cur++;
        }
        if (cur + 1 >= end)
        {
            cur = base;
            continue;
        }

        const uint8_t *soi = cur;
        const uint8_t *q   = soi + 2;
        while (q + 1 < end && !(q[0] == JPEG_MARK && q[1] == JPEG_EOI))
        {
            q++;
        }
        if (q + 1 >= end)
        {
            cur = base;
            continue;
        }

        uint32_t sz = (uint32_t)((q + 2) - soi);
        cur = q + 2;

        if (sz == 0u || sz > MAX_FRAME)
        {
            continue;
        }

        producer_post_frame(prod, soi, sz, true);
        gui_thread_mdelay(prod->interval_ms);
    }
}
int app_stream_transport_init(void)
{
    stp_config_t cfg;
    stp_config_default(&cfg);
    cfg.align       = 8;
    cfg.classes     = s_stream_classes;
    cfg.class_count = 1;
    cfg.drop_mode   = STP_DROP_UNCONDITIONAL;

    s_stream_tp = stp_instance_create(&cfg);
    if (!s_stream_tp)
    {
        gui_log("stream demo: stp_instance_create failed\n");
        return -1;
    }
    static void *data = NULL;
    int32_t size;
    if (data == NULL)
    {
        /* Fallback: read file into memory */
        gui_vfs_file_t *f = gui_vfs_open((const char *)"/user/carplay_map.mjpg", GUI_VFS_READ);
        GUI_ASSERT(f != NULL);
        gui_vfs_seek(f, 0, GUI_VFS_SEEK_END);
        size = gui_vfs_tell(f);

        if (size <= 0)
        {
            gui_vfs_close(f);
            return -1;
        }
        gui_vfs_seek(f, 0, GUI_VFS_SEEK_SET);
        data = gui_malloc(size);
        GUI_ASSERT(data != NULL);
        gui_vfs_read(f, (void *)data, size);
        gui_vfs_close(f);
    }

    s_producer.src     = (void *)data;
    s_producer.src_len = (uint32_t)size;
    s_producer.tp          = s_stream_tp;
    s_producer.interval_ms = 500;   /* emit at the source fps   */
    s_producer.running     = true;

    if (!gui_thread_create("stream_jpeg", mjpeg_producer_entry, &s_producer, 1024 * 8, 5))
    {
        gui_log("stream demo: stream_jpeg producer thread create failed\n");
        s_producer.running = false;
    }
    return 0;
}
#else
int app_stream_transport_init(void)
{
    stp_config_t cfg;
    stp_config_default(&cfg);
    cfg.align              = 8;
    cfg.classes            = s_stream_classes;
    cfg.class_count        = 1;
    cfg.drop_mode          = STP_DROP_UNCONDITIONAL;
    cfg.allow_oversize_fit = true;

    s_stream_tp = stp_instance_create(&cfg);
    if (s_stream_tp == NULL)
    {
        gui_log("app_stream: stp_instance_create failed\n");
        return -1;
    }

    gui_log("app_stream: transport ready (%u buffers x %u KB)\n",
            (unsigned)APP_STREAM_BUF_COUNT,
            (unsigned)(APP_STREAM_MAX_FRAME / 1024u));
    return 0;
}
#endif
