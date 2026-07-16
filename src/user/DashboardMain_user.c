#include "DashboardMain_user.h"
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
        gui_view_switch_direct(gui_view_get_current(), "carplay_view", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_NONE_ANIMATION);
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
        gui_obj_stop_timer(GUI_BASE(carplay_speed));
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
                gui_img_set_src(music_cover, (void *)dashboard_info.cover, IMG_SRC_FILESYS);
#else
                gui_img_set_src(music_cover, (void *)dashboard_info.cover, IMG_SRC_MEMADDR); // A8565 100*100
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
                gui_img_set_src(carplay_music_cover, (void *)dashboard_info.cover, IMG_SRC_FILESYS);
#else
                gui_img_set_src(carplay_music_cover, (void *)dashboard_info.cover, IMG_SRC_MEMADDR); // A8565 100*100
#endif
                gui_img_set_src(carplay_music_play, "/resource/carplay/icon_media_pause.bin", IMG_SRC_FILESYS);
                gui_scroll_text_content_set(carplay_music_name, dashboard_info.music_name, strlen(dashboard_info.music_name));
                gui_scroll_text_content_set(carplay_music_artist, dashboard_info.artist_name, strlen(dashboard_info.artist_name));
                gui_scroll_text_content_set(carplay_music_lyrics, dashboard_info.lyrics, strlen(dashboard_info.lyrics));
            }
        }
        else
        {
            gui_img_set_src(carplay_music_play, "/resource/carplay/icon_media_play.bin", IMG_SRC_FILESYS);        
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
    if (obj == (gui_obj_t *)win_common)
    {
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
    }
    else
    {
        const void *img_data_array[10] =
        {
            "/resource/carplay/carplay_map_00.bin",
            "/resource/carplay/carplay_map_01.bin",
            "/resource/carplay/carplay_map_02.bin",
            "/resource/carplay/carplay_map_03.bin",
            "/resource/carplay/carplay_map_04.bin",
            "/resource/carplay/carplay_map_05.bin",
            "/resource/carplay/carplay_map_06.bin",
            "/resource/carplay/carplay_map_07.bin",
            "/resource/carplay/carplay_map_08.bin",
            "/resource/carplay/carplay_map_09.bin",
        };
        gui_img_set_src(carplay_map, img_data_array[(*((uint8_t *)data)) % 10], IMG_SRC_FILESYS);
    }
#else
    // TODO: update map data
    gui_img_set_src(carplay_map, data, IMG_SRC_MEMADDR); // 565 410*370
#endif
}