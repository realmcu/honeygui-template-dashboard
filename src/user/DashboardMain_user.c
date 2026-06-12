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


static bool menu_disp = false;
static char top_info_str[30];
static uint8_t menu_func_index = 0;
extern uint8_t app_index;
extern uint8_t weather_note_index;
extern char power_str[4];
extern char speed_str[4];

#define MUSIC_COUNT  4
uint8_t music_index = 0;
void *music_cover_array[MUSIC_COUNT] = 
{
    "/resource/music/COVER_0.bin",
    "/resource/music/COVER_1.bin",
    "/resource/music/COVER_2.bin",
    "/resource/music/COVER_3.bin",
};

// Update dashboard info by shell command
#ifdef _HONEYGUI_SIMULATOR_
void dashboard_info_update(int argc, char *argv[])
{
    // if (get_dashboard_info() == NULL) { return; }
    int i = 1;
    while (i < argc - 1)
    {
        if (!strcmp(argv[i], "map"))
        {
            // extern int open(const char *file, int flags, ...);
            // extern int read(int fd, void *buf, size_t len);
            // extern int close(int fd);
            // char path[100] = "example/application/screen_800_480/root_image_800_480/root/resource/map_";
            // strcat(path, argv[++i]);
            // strcat(path, ".bin");
            // int fd;
            // fd = open(path, 0);
            // if (fd < 0)
            // {
            //     printf("open %s Fail!\n", path);
            //     break;
            // }
            // void *map_data = gui_malloc(1024 * 500);
            // ssize_t bytes_read = read(fd, map_data, 1024 * 500);
            // if (bytes_read < 0)
            // {
            //     printf("read bin file failed!\n");
            //     close(fd);
            //     break;
            // }
            // close(fd);

            // dashboard_info.map_data_update = 1;
            // dashboard_info.map_data_index ^= 1;
            // if (dashboard_info.map_data[dashboard_info.map_data_index])
            // {
            //     gui_free(dashboard_info.map_data[dashboard_info.map_data_index]);
            // }
            // dashboard_info.map_data[dashboard_info.map_data_index] = map_data;
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
            dashboard_info.odo_val = atoi(argv[++i]);
        }
        else if (!strcmp(argv[i], "soc"))
        {
            dashboard_info.soc_val = atoi(argv[++i]);
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
            dashboard_info.led_turn_r_status = atoi(argv[++i]);
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show || !menu_disp) return;
    
    switch (menu_func_index)
    {
    case 0:
        gui_obj_create_timer(GUI_BASE(win_map), 10, true, win_map_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(win_map));
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
        gui_obj_create_timer(GUI_BASE(win_map), 10, true, win_map_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_map));
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
        gui_obj_create_timer(GUI_BASE(win_map), 10, true, win_map_timer_2_cb);
        gui_obj_start_timer(GUI_BASE(win_map));
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
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
    if (GUI_BASE(obj)->not_show) return;
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
    gui_obj_create_timer(GUI_BASE(win_app_developing), 10, true, win_app_developing_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_developing));
}

void win_app_weather_msg_next_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    weather_note_index++;
    weather_note_index %= 2;
    gui_obj_create_timer(GUI_BASE(list_weather), 10, true, list_weather_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(list_weather));
}

void win_app_weather_msg_exit_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if (GUI_BASE(obj)->not_show) return;
    gui_obj_create_timer(GUI_BASE(win_app_list), 10, true, win_app_list_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(win_app_list));
    gui_obj_create_timer(GUI_BASE(win_app_weather), 10, true, win_app_weather_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(win_app_weather));
}

void update_dashbord_speed(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.speed_val = (*(uint16_t *)data) % 160;
    sprintf(speed_str, "%u", dashboard_info.speed_val);
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

void update_dashbord_power(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
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

void update_dashbord_led0(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led0_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led0_status)
    {
        color = 0xFF10995E;
    }
    gui_img_a8_recolor(led_0, color);
}

void update_dashbord_led1(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led1_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led1_status)
    {
        color = 0xFF10995E;
    }
    gui_img_a8_recolor(led_1, color);
}

void update_dashbord_led2(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led2_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led2_status)
    {
        color = 0xFF10995E;
    }
    gui_img_a8_recolor(led_2, color);
}

void update_dashbord_led3(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led3_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led3_status)
    {
        color = 0xFFFFB53E;
    }
    gui_img_a8_recolor(led_3, color);
}

void update_dashbord_led4(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led4_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led4_status)
    {
        color = 0xFFFFB53E;
    }
    gui_img_a8_recolor(led_4, color);
}

void update_dashbord_led5(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led5_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led5_status)
    {
        color = 0xFFFFB53E;
    }
    gui_img_a8_recolor(led_5, color);
}

void update_dashbord_led_turn_l(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led_turn_l_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led_turn_l_status)
    {
        color = 0xFF10995E;
    }
    gui_img_a8_recolor(turn_l_icon, color);
}

void update_dashbord_led_turn_r(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.led_turn_r_status = *(bool *)data;
    uint32_t color = 0xFFFFFFFF;
    if (dashboard_info.led_turn_r_status)
    {
        color = 0xFF10995E;
    }
    gui_img_a8_recolor(turn_r_icon, color);
}

void update_dashbord_bt(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
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
    gui_img_a8_mix_alpha(bt_icon, opacity);
}

void update_dashbord_wifi(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
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
    gui_img_a8_mix_alpha(wifi_icon, opacity);
}

void update_dashbord_volume(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
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

void update_dashbord_location(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    snprintf(dashboard_info.location, len, "%s", (char *)data);
    sprintf(top_info_str, "%s %u°C", dashboard_info.location, dashboard_info.temp_val);
    gui_text_content_set(text_loc_temp, top_info_str, sizeof(top_info_str));
}

void update_dashbord_temp(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(topic);
    GUI_UNUSED(data);
    GUI_UNUSED(len);

    dashboard_info.temp_val = *((uint8_t *)data);
    
    sprintf(top_info_str, "%s %u°C", dashboard_info.location, dashboard_info.temp_val);
    gui_text_content_set(text_loc_temp, top_info_str, sizeof(top_info_str));
}