/**
 * DashboardMain UI Implementation (Auto-generated, do not modify manually)
 * Generated at: 2026-07-07T03:30:52.950Z
 */
#include "DashboardMain_ui.h"
#include "../callbacks/DashboardMain_callbacks.h"
#include "../user/DashboardMain_user.h"
#include <stddef.h>

// Component handle definitions
gui_img_t *gloom = NULL;
gui_img_t *start_engine = NULL;
gui_img_t *shadow = NULL;
gui_win_t *win_map = NULL;
gui_img_t *map = NULL;
gui_win_t *win_func = NULL;
gui_win_t *win_app_list = NULL;
gui_list_t *app_list = NULL;
gui_text_t *text_app_name_0 = NULL;
gui_text_t *text_app_name_1 = NULL;
gui_text_t *text_app_name_2 = NULL;
gui_img_t *interval_line_1 = NULL;
gui_img_t *interval_line_2 = NULL;
gui_img_t *arrow_down = NULL;
gui_text_t *text_app_name_3 = NULL;
gui_text_t *text_app_name_4 = NULL;
gui_text_t *text_app_name_5 = NULL;
gui_img_t *interval_line_3 = NULL;
gui_img_t *interval_line_4 = NULL;
gui_img_t *arrow_up = NULL;
gui_img_t *tab_hightlight = NULL;
gui_win_t *win_app_weather = NULL;
gui_list_t *list_weather = NULL;
gui_img_t *weather_1 = NULL;
gui_img_t *weather_2 = NULL;
gui_win_t *win_app_developing = NULL;
gui_text_t *text_app_developing = NULL;
gui_img_t *root_menu = NULL;
gui_win_t *win_dail = NULL;
gui_img_t *dail_speed = NULL;
gui_img_t *speed_arc = NULL;
gui_img_t *dail_pointer_s = NULL;
gui_img_t *dail_power = NULL;
gui_img_t *power_arc = NULL;
gui_img_t *dail_pointer_p = NULL;
gui_img_t *leftbottom_gloom = NULL;
gui_img_t *rightbottom_gloom = NULL;
gui_img_t *connect_line = NULL;
gui_win_t *win_common = NULL;
gui_img_t *turn_l_icon = NULL;
gui_img_t *turn_r_icon = NULL;
gui_img_t *bt_icon = NULL;
gui_img_t *wifi_icon = NULL;
gui_text_t *text_loc_temp = NULL;
gui_text_t *text_time = NULL;
gui_img_t *led_0 = NULL;
gui_img_t *led_1 = NULL;
gui_img_t *led_2 = NULL;
gui_img_t *led_3 = NULL;
gui_img_t *led_4 = NULL;
gui_img_t *led_5 = NULL;
gui_win_t *win_speed_text = NULL;
gui_text_t *text_speed = NULL;
gui_text_t *text_speed_unit = NULL;
gui_img_t *line = NULL;
gui_text_t *text_odo = NULL;
gui_win_t *win_power_text = NULL;
gui_text_t *text_power = NULL;
gui_text_t *text_power_unit = NULL;
gui_img_t *line_copy_1768894235876_3 = NULL;
gui_text_t *text_battery = NULL;
gui_win_t *win_volume = NULL;
gui_img_t *volume_icon = NULL;
gui_text_t *lbl_volume = NULL;
gui_win_t *win_music = NULL;
gui_img_t *music_cover = NULL;
gui_img_t *music_board = NULL;
gui_img_t *playbar_bg = NULL;
gui_win_t *win_playbar = NULL;
gui_img_t *playbar = NULL;
gui_text_t *lbl_music = NULL;
gui_text_t *lbl_artist = NULL;
gui_scroll_text_t *lbl_lyrics = NULL;

// List component note_design callback functions
// note_design callback function declaration
static void app_list_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void app_list_note_design(gui_obj_t *obj, void *param)
{
    GUI_UNUSED(param);
    
    // Cast obj to gui_list_note_t * type
    gui_list_note_t *note = (gui_list_note_t *)obj;
    uint16_t index = note->index;
    
    // Create different list_item content based on index
    switch (index)
    {
    case 0:
    {
        // Create text_app_name_0 (hg_label)
        text_app_name_0 = gui_text_create((gui_obj_t *)note, "text_app_name_0", 60, 0, 360, 90);
        gui_text_set((gui_text_t *)text_app_name_0, "Navigation", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 10, 30);
        gui_text_type_set((gui_text_t *)text_app_name_0, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
        gui_text_mode_set((gui_text_t *)text_app_name_0, MID_LEFT);
        // Create text_app_name_1 (hg_label)
        text_app_name_1 = gui_text_create((gui_obj_t *)note, "text_app_name_1", 60, 90, 360, 90);
        gui_text_set((gui_text_t *)text_app_name_1, "Music", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 30);
        gui_text_type_set((gui_text_t *)text_app_name_1, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
        gui_text_mode_set((gui_text_t *)text_app_name_1, MID_LEFT);
        // Create text_app_name_2 (hg_label)
        text_app_name_2 = gui_text_create((gui_obj_t *)note, "text_app_name_2", 60, 180, 360, 90);
        gui_text_set((gui_text_t *)text_app_name_2, "Call", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 4, 30);
        gui_text_type_set((gui_text_t *)text_app_name_2, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
        gui_text_mode_set((gui_text_t *)text_app_name_2, MID_LEFT);
        // Create interval_line_1 (hg_image)
        interval_line_1 = gui_img_create_from_fs((gui_obj_t *)note, "interval_line_1", "/resource/func/interval_line.bin", 40, 90, 420, 3);
        // Create interval_line_2 (hg_image)
        interval_line_2 = gui_img_create_from_fs((gui_obj_t *)note, "interval_line_2", "/resource/func/interval_line.bin", 40, 180, 420, 3);
        // Create arrow_down (hg_image)
        arrow_down = gui_img_create_from_fs((gui_obj_t *)note, "arrow_down", "/resource/func/arrow_down.bin", 460, 244, 31, 16);
        break;
    }
    case 1:
    {
        // Create text_app_name_3 (hg_label)
        text_app_name_3 = gui_text_create((gui_obj_t *)note, "text_app_name_3", 60, 0, 360, 90);
        gui_text_set((gui_text_t *)text_app_name_3, "Weather", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 7, 30);
        gui_text_type_set((gui_text_t *)text_app_name_3, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
        gui_text_mode_set((gui_text_t *)text_app_name_3, MID_LEFT);
        // Create text_app_name_4 (hg_label)
        text_app_name_4 = gui_text_create((gui_obj_t *)note, "text_app_name_4", 60, 90, 360, 90);
        gui_text_set((gui_text_t *)text_app_name_4, "Notification", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 12, 30);
        gui_text_type_set((gui_text_t *)text_app_name_4, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
        gui_text_mode_set((gui_text_t *)text_app_name_4, MID_LEFT);
        // Create text_app_name_5 (hg_label)
        text_app_name_5 = gui_text_create((gui_obj_t *)note, "text_app_name_5", 60, 180, 360, 90);
        gui_text_set((gui_text_t *)text_app_name_5, "Information Transfer", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 20, 30);
        gui_text_type_set((gui_text_t *)text_app_name_5, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
        gui_text_mode_set((gui_text_t *)text_app_name_5, MID_LEFT);
        // Create interval_line_3 (hg_image)
        interval_line_3 = gui_img_create_from_fs((gui_obj_t *)note, "interval_line_3", "/resource/func/interval_line.bin", 40, 90, 420, 3);
        // Create interval_line_4 (hg_image)
        interval_line_4 = gui_img_create_from_fs((gui_obj_t *)note, "interval_line_4", "/resource/func/interval_line.bin", 40, 180, 420, 3);
        // Create arrow_up (hg_image)
        arrow_up = gui_img_create_from_fs((gui_obj_t *)note, "arrow_up", "/resource/func/arrow_up.bin", 460, 22, 31, 16);
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void list_weather_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void list_weather_note_design(gui_obj_t *obj, void *param)
{
    GUI_UNUSED(param);
    
    // Cast obj to gui_list_note_t * type
    gui_list_note_t *note = (gui_list_note_t *)obj;
    uint16_t index = note->index;
    
    // Create different list_item content based on index
    switch (index)
    {
    case 0:
    {
        // Create weather_1 (hg_image)
        weather_1 = gui_img_create_from_fs((gui_obj_t *)note, "weather_1", "/resource/func/app_weather_1.bin", 0, 0, 500, 280);
        break;
    }
    case 1:
    {
        // Create weather_2 (hg_image)
        weather_2 = gui_img_create_from_fs((gui_obj_t *)note, "weather_2", "/resource/func/app_weather_2.bin", 0, 0, 500, 280);
        break;
    }
    default:
        break;
    }
}


// Create dashboardMainView (hg_view)
static void dashboardMainView_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void dashboardMainView_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 500);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    GUI_UNUSED(view);


    // Create gloom (hg_image)
    gloom = gui_img_create_from_fs((gui_obj_t *)view, "gloom", "/resource/StartEngineGloom.bin", 80, 58, 640, 364);
    gui_img_set_opacity((gui_img_t *)gloom, 0);

    // Create start_engine (hg_image)
    start_engine = gui_img_create_from_fs((gui_obj_t *)view, "start_engine", "/resource/StartEngine.bin", 305, 145, 190, 190);
    gui_obj_add_event_cb(start_engine, (gui_event_cb_t)start_engine_key_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)start_engine);

    // Create shadow (hg_image)
    shadow = gui_img_create_from_fs((gui_obj_t *)view, "shadow", "/resource/Start_Engine_Release.bin", 348, 187, 105, 105);
}
GUI_VIEW_INSTANCE("dashboardMainView", false, dashboardMainView_switch_in, dashboardMainView_switch_out, false);

// Create dashboard_view (hg_view)
static void dashboard_view_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void dashboard_view_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 500);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    GUI_UNUSED(view);


    // Create win_map (hg_window)
    win_map = gui_win_create((gui_obj_t *)view, "win_map", 0, 0, 800, 480);
    gui_obj_hidden((gui_obj_t *)win_map, true);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)win_map, 6000, false, win_map_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_map);


    // Create map (hg_image)
    map = gui_img_create_from_fs(win_map, "map", "/resource/map/map_00.bin", 141, 198, 518, 282);
    gui_img_set_mode((gui_img_t *)map, IMG_BYPASS_MODE);
    // Bind timer: map array
    gui_obj_create_timer((gui_obj_t *)map, 1000, true, map_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)map);

    // Create win_func (hg_window)
    win_func = gui_win_create((gui_obj_t *)view, "win_func", 150, 200, 500, 280);
    gui_obj_hidden((gui_obj_t *)win_func, true);


    // Create win_app_list (hg_window)
    win_app_list = gui_win_create(win_func, "win_app_list", 0, 0, 500, 280);


    // Create app_list (hg_list)
    app_list = gui_list_create(win_app_list, "app_list", 0, 0, 500, 280, 280, 0, VERTICAL, app_list_note_design, NULL, false);
    gui_list_set_style(app_list, LIST_CLASSIC);
    gui_list_set_note_num(app_list, 2);
    gui_list_set_inertia(app_list, false);

    // Create tab_hightlight (hg_image)
    tab_hightlight = gui_img_create_from_fs(win_app_list, "tab_hightlight", "/resource/func/tab_highlight.bin", 32, 0, 420, 94);
    // Bind timer: pos update
    gui_obj_create_timer((gui_obj_t *)tab_hightlight, 20, true, tab_hightlight_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)tab_hightlight);

    gui_obj_add_event_cb(GUI_BASE(win_app_list), (gui_event_cb_t)win_app_list_key_0_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)win_app_list);

    // Create win_app_weather (hg_window)
    win_app_weather = gui_win_create(win_func, "win_app_weather", 0, 0, 500, 280);
    gui_obj_hidden((gui_obj_t *)win_app_weather, true);


    // Create list_weather (hg_list)
    list_weather = gui_list_create(win_app_weather, "list_weather", 0, 0, 500, 280, 280, 0, VERTICAL, list_weather_note_design, NULL, false);
    gui_list_set_style(list_weather, LIST_CLASSIC);
    gui_list_set_note_num(list_weather, 2);
    gui_list_set_inertia(list_weather, false);

    gui_obj_add_event_cb(GUI_BASE(win_app_weather), (gui_event_cb_t)win_app_weather_key_0_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)win_app_weather);

    // Create win_app_developing (hg_window)
    win_app_developing = gui_win_create(win_func, "win_app_developing", 0, 0, 500, 280);
    gui_obj_hidden((gui_obj_t *)win_app_developing, true);


    // Create text_app_developing (hg_label)
    text_app_developing = gui_text_create(win_app_developing, "text_app_developing", 0, 0, 500, 280);
    gui_text_set((gui_text_t *)text_app_developing, "App is developing!", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 18, 36);
    gui_text_type_set((gui_text_t *)text_app_developing, "//HarmonyOS_Sans_Bold_size36_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_app_developing, MID_CENTER);

    gui_obj_add_event_cb(GUI_BASE(win_app_developing), (gui_event_cb_t)win_app_developing_key_0_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)win_app_developing);

    // Create root_menu (hg_image)
    root_menu = gui_img_create_from_fs((gui_obj_t *)view, "root_menu", "/resource/menu/menu_001.bin", 225, 481, 350, 190);
    gui_img_set_mode((gui_img_t *)root_menu, IMG_SRC_OVER_MODE);
    // Bind timer: set focus
    gui_obj_create_timer((gui_obj_t *)root_menu, 10, true, root_menu_timer_11_cb);
    gui_obj_add_event_cb(root_menu, (gui_event_cb_t)root_menu_key_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)root_menu);

    // Create win_dail (hg_window)
    win_dail = gui_win_create((gui_obj_t *)view, "win_dail", 0, 0, 800, 480);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)win_dail, 7, true, win_dail_timer_0_cb);


    // Create dail_speed (hg_image)
    dail_speed = gui_img_create_from_fs(win_dail, "dail_speed", "/resource/dail_speed.bin", 28, 50, 308, 311);
    gui_img_set_mode((gui_img_t *)dail_speed, IMG_SRC_OVER_MODE);

    // Create speed_arc (hg_image)
    speed_arc = gui_img_create_from_fs(win_dail, "speed_arc", "/resource/speed_arc/speed_arc_00.bin", 97, 120, 182, 182);
    gui_img_set_mode((gui_img_t *)speed_arc, IMG_SRC_OVER_MODE);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)speed_arc, 30, true, speed_arc_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)speed_arc);

    // Create dail_pointer_s (hg_image)
    dail_pointer_s = gui_img_create_from_fs(win_dail, "dail_pointer_s", "/resource/dail_pointer.bin", 184, 342, 4, 25);
    gui_img_set_mode((gui_img_t *)dail_pointer_s, IMG_BYPASS_MODE);
    gui_img_set_quality((gui_img_t *)dail_pointer_s, true);
    gui_img_translate((gui_img_t *)dail_pointer_s, 4.0f, -130.0f);
    gui_img_set_focus((gui_img_t *)dail_pointer_s, 2.0f, -65.0f);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)dail_pointer_s, 30, true, dail_pointer_s_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)dail_pointer_s);

    // Create dail_power (hg_image)
    dail_power = gui_img_create_from_fs(win_dail, "dail_power", "/resource/dail_power.bin", 467, 50, 308, 311);
    gui_img_set_mode((gui_img_t *)dail_power, IMG_SRC_OVER_MODE);
    gui_obj_add_event_cb(dail_power, (gui_event_cb_t)dail_power_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create power_arc (hg_image)
    power_arc = gui_img_create_from_fs(win_dail, "power_arc", "/resource/power_arc/power_arc_00.bin", 524, 120, 182, 182);
    gui_img_set_mode((gui_img_t *)power_arc, IMG_SRC_OVER_MODE);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)power_arc, 30, true, power_arc_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)power_arc);

    // Create dail_pointer_p (hg_image)
    dail_pointer_p = gui_img_create_from_fs(win_dail, "dail_pointer_p", "/resource/dail_pointer.bin", 611, 342, 4, 25);
    gui_img_set_mode((gui_img_t *)dail_pointer_p, IMG_BYPASS_MODE);
    gui_img_set_quality((gui_img_t *)dail_pointer_p, true);
    gui_img_translate((gui_img_t *)dail_pointer_p, 4.0f, -130.0f);
    gui_img_set_focus((gui_img_t *)dail_pointer_p, 2.0f, -65.0f);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)dail_pointer_p, 30, true, dail_pointer_p_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)dail_pointer_p);

    // Create leftbottom_gloom (hg_image)
    leftbottom_gloom = gui_img_create_from_fs(win_dail, "leftbottom_gloom", "/resource/LeftBottomGloomV1.bin", 34, 360, 103, 127);
    gui_img_set_mode((gui_img_t *)leftbottom_gloom, IMG_SRC_OVER_MODE);

    // Create rightbottom_gloom (hg_image)
    rightbottom_gloom = gui_img_create_from_fs(win_dail, "rightbottom_gloom", "/resource/RightBottomGloomV1.bin", 664, 360, 103, 127);
    gui_img_set_mode((gui_img_t *)rightbottom_gloom, IMG_SRC_OVER_MODE);

    // Create connect_line (hg_image)
    connect_line = gui_img_create_from_fs(win_dail, "connect_line", "/resource/connect_line.bin", 335, 149, 133, 1);
    gui_img_set_mode((gui_img_t *)connect_line, IMG_BYPASS_MODE);

    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_dail), "speed", win_dail_msg_cb_0);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_dail), "power", win_dail_msg_cb_1);

    // Create win_common (hg_window)
    win_common = gui_win_create((gui_obj_t *)view, "win_common", 0, 0, 800, 480);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)win_common, 20, true, win_common_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_common);


    // Create turn_l_icon (hg_image)
    turn_l_icon = gui_img_create_from_fs(win_common, "turn_l_icon", "/resource/Turnleft_off.bin", 20, 64, 35, 19);
    gui_img_set_mode((gui_img_t *)turn_l_icon, IMG_BYPASS_MODE);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)turn_l_icon, 30, true, turn_l_icon_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)turn_l_icon);

    // Create turn_r_icon (hg_image)
    turn_r_icon = gui_img_create_from_fs(win_common, "turn_r_icon", "/resource/Turnright_off.bin", 745, 64, 35, 19);
    gui_img_set_mode((gui_img_t *)turn_r_icon, IMG_BYPASS_MODE);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)turn_r_icon, 30, true, turn_r_icon_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)turn_r_icon);

    // Create bt_icon (hg_image)
    bt_icon = gui_img_create_from_fs(win_common, "bt_icon", "/resource/bt.bin", 294, 52, 14, 20);
    gui_img_set_mode((gui_img_t *)bt_icon, IMG_BYPASS_MODE);
    gui_img_set_opacity((gui_img_t *)bt_icon, 122);

    // Create wifi_icon (hg_image)
    wifi_icon = gui_img_create_from_fs(win_common, "wifi_icon", "/resource/wifi.bin", 478, 52, 28, 20);
    gui_img_set_mode((gui_img_t *)wifi_icon, IMG_BYPASS_MODE);
    gui_img_set_opacity((gui_img_t *)wifi_icon, 122);

    // Create text_loc_temp (hg_label)
    text_loc_temp = gui_text_create(win_common, "text_loc_temp", 250, 32, 300, 24);
    gui_text_set((gui_text_t *)text_loc_temp, "Suzhou 25°C", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 12, 22);
    gui_text_type_set((gui_text_t *)text_loc_temp, "//HarmonyOS_Sans_Bold_size22_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_loc_temp, CENTER);

    // Create text_time (hg_label)
    text_time = gui_text_create(win_common, "text_time", 334, 55, 132, 22);
    gui_text_set((gui_text_t *)text_time, "10:10", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 22);
    gui_text_type_set((gui_text_t *)text_time, "//HarmonyOS_Sans_Bold_size22_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_time, CENTER);
    // Bind timer: time update
    gui_obj_create_timer((gui_obj_t *)text_time, 1000, true, text_time_timer_0_cb);

    // Create led_0 (hg_image)
    led_0 = gui_img_create_from_fs(win_common, "led_0", "/resource/LED0_off.bin", 85, 360, 27, 27);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)led_0, 30, true, led_0_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_0);

    // Create led_1 (hg_image)
    led_1 = gui_img_create_from_fs(win_common, "led_1", "/resource/LED1_off.bin", 65, 400, 27, 27);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)led_1, 30, true, led_1_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_1);

    // Create led_2 (hg_image)
    led_2 = gui_img_create_from_fs(win_common, "led_2", "/resource/LED2_off.bin", 45, 440, 27, 27);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)led_2, 30, true, led_2_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_2);

    // Create led_3 (hg_image)
    led_3 = gui_img_create_from_fs(win_common, "led_3", "/resource/LED3_off.bin", 690, 360, 27, 27);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)led_3, 30, true, led_3_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_3);

    // Create led_4 (hg_image)
    led_4 = gui_img_create_from_fs(win_common, "led_4", "/resource/LED4_off.bin", 710, 400, 27, 27);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)led_4, 30, true, led_4_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_4);

    // Create led_5 (hg_image)
    led_5 = gui_img_create_from_fs(win_common, "led_5", "/resource/LED5_off.bin", 730, 440, 26, 27);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)led_5, 30, true, led_5_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)led_5);

    // Create win_speed_text (hg_window)
    win_speed_text = gui_win_create(win_common, "win_speed_text", 41, 64, 294, 294);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)win_speed_text, 8, true, win_speed_text_timer_0_cb);


    // Create text_speed (hg_label)
    text_speed = gui_text_create(win_speed_text, "text_speed", 0, 106, 294, 50);
    gui_text_set((gui_text_t *)text_speed, "0", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 1, 40);
    gui_text_type_set((gui_text_t *)text_speed, "//HarmonyOS_Sans_Bold_size40_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_speed, CENTER);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)text_speed, 30, true, text_speed_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)text_speed);

    // Create text_speed_unit (hg_label)
    text_speed_unit = gui_text_create(win_speed_text, "text_speed_unit", 0, 141, 294, 30);
    gui_text_set((gui_text_t *)text_speed_unit, "km/h", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 4, 26);
    gui_text_type_set((gui_text_t *)text_speed_unit, "//HarmonyOS_Sans_Bold_size26_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_speed_unit, CENTER);

    // Create line (hg_image)
    line = gui_img_create_from_fs(win_speed_text, "line", "/resource/dividing_line.bin", 96, 168, 101, 2);
    gui_img_set_mode((gui_img_t *)line, IMG_BYPASS_MODE);

    // Create text_odo (hg_label)
    text_odo = gui_text_create(win_speed_text, "text_odo", 0, 177, 294, 20);
    gui_text_set((gui_text_t *)text_odo, "ODO 300km", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 9, 16);
    gui_text_type_set((gui_text_t *)text_odo, "//HarmonyOS_Sans_Bold_size16_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_odo, CENTER);
    // Bind timer: 动画 1
    gui_obj_create_timer((gui_obj_t *)text_odo, 1000, true, text_odo_timer_0_cb);

    // Create win_power_text (hg_window)
    win_power_text = gui_win_create(win_common, "win_power_text", 470, 64, 294, 294);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)win_power_text, 8, true, win_power_text_timer_0_cb);


    // Create text_power (hg_label)
    text_power = gui_text_create(win_power_text, "text_power", 0, 106, 294, 50);
    gui_text_set((gui_text_t *)text_power, "0", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 1, 40);
    gui_text_type_set((gui_text_t *)text_power, "//HarmonyOS_Sans_Bold_size40_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_power, CENTER);
    // Bind timer: entrance
    gui_obj_create_timer((gui_obj_t *)text_power, 30, true, text_power_timer_1_cb);
    gui_obj_start_timer((gui_obj_t *)text_power);

    // Create text_power_unit (hg_label)
    text_power_unit = gui_text_create(win_power_text, "text_power_unit", 0, 141, 294, 30);
    gui_text_set((gui_text_t *)text_power_unit, "kW", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 2, 26);
    gui_text_type_set((gui_text_t *)text_power_unit, "//HarmonyOS_Sans_Bold_size26_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_power_unit, CENTER);

    // Create line_copy_1768894235876_3 (hg_image)
    line_copy_1768894235876_3 = gui_img_create_from_fs(win_power_text, "line_copy_1768894235876_3", "/resource/dividing_line.bin", 96, 168, 101, 2);
    gui_img_set_mode((gui_img_t *)line_copy_1768894235876_3, IMG_BYPASS_MODE);

    // Create text_battery (hg_label)
    text_battery = gui_text_create(win_power_text, "text_battery", 0, 177, 294, 20);
    gui_text_set((gui_text_t *)text_battery, "BATT 65%", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 8, 16);
    gui_text_type_set((gui_text_t *)text_battery, "//HarmonyOS_Sans_Bold_size16_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)text_battery, CENTER);
    // Bind timer: 动画 1
    gui_obj_create_timer((gui_obj_t *)text_battery, 1000, true, text_battery_timer_0_cb);

    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "led0", win_common_msg_cb_0);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "led1", win_common_msg_cb_1);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "led2", win_common_msg_cb_2);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "led3", win_common_msg_cb_3);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "led4", win_common_msg_cb_4);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "led5", win_common_msg_cb_5);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "turnl", win_common_msg_cb_6);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "turnr", win_common_msg_cb_7);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "bt", win_common_msg_cb_8);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "wifi", win_common_msg_cb_9);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "volume", win_common_msg_cb_10);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "location", win_common_msg_cb_11);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "temp", win_common_msg_cb_12);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "play", win_common_msg_cb_13);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "odo", win_common_msg_cb_14);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "battery", win_common_msg_cb_15);
    gui_msg_subscribe((gui_obj_t *)GUI_BASE(win_common), "map", win_common_msg_cb_16);

    // Create win_volume (hg_window)
    win_volume = gui_win_create((gui_obj_t *)view, "win_volume", 335, 98, 135, 50);
    gui_obj_hidden((gui_obj_t *)win_volume, true);


    // Create volume_icon (hg_image)
    volume_icon = gui_img_create_from_fs(win_volume, "volume_icon", "/resource/volume_icon.bin", 14, 10, 39, 31);

    // Create lbl_volume (hg_label)
    lbl_volume = gui_text_create(win_volume, "lbl_volume", 66, 7, 56, 37);
    gui_text_set((gui_text_t *)lbl_volume, "100", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 3, 30);
    gui_text_type_set((gui_text_t *)lbl_volume, "//HarmonyOS_Sans_Bold_size30_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_volume, MID_CENTER);
    // Bind timer: 动画 1
    gui_obj_create_timer((gui_obj_t *)lbl_volume, 100, true, lbl_volume_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)lbl_volume);

    // Create win_music (hg_window)
    win_music = gui_win_create((gui_obj_t *)view, "win_music", 0, 0, 800, 480);
    gui_obj_hidden((gui_obj_t *)win_music, true);
    // Bind timer: 动画 1
    gui_obj_create_timer((gui_obj_t *)win_music, 1000, true, win_music_timer_0_cb);
    gui_obj_start_timer((gui_obj_t *)win_music);


    // Create music_cover (hg_image)
    music_cover = gui_img_create_from_fs(win_music, "music_cover", "/resource/music/COVER_0.bin", 186, 370, 100, 100);
    gui_img_set_mode((gui_img_t *)music_cover, IMG_SRC_OVER_MODE);

    // Create music_board (hg_image)
    music_board = gui_img_create_from_fs(win_music, "music_board", "/resource/music/music_board.bin", 306, 370, 312, 100);

    // Create playbar_bg (hg_image)
    playbar_bg = gui_img_create_from_fs(win_music, "playbar_bg", "/resource/music/playbar.bin", 337, 458, 250, 6);

    // Create win_playbar (hg_window)
    win_playbar = gui_win_create(win_music, "win_playbar", 337, 456, 1, 10);


    // Create playbar (hg_image)
    playbar = gui_img_create_from_fs(win_playbar, "playbar", "/resource/music/playbar_on.bin", 0, 2, 250, 6);

    // Create lbl_music (hg_label)
    lbl_music = gui_text_create(win_music, "lbl_music", 320, 372, 296, 29);
    gui_text_set((gui_text_t *)lbl_music, "Music", GUI_FONT_SRC_BMP, gui_rgb(3, 3, 3), 5, 16);
    gui_text_type_set((gui_text_t *)lbl_music, "//HarmonyOS_Sans_Bold_size16_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_music, MID_LEFT);

    // Create lbl_artist (hg_label)
    lbl_artist = gui_text_create(win_music, "lbl_artist", 320, 398, 296, 29);
    gui_text_set((gui_text_t *)lbl_artist, "Artist", GUI_FONT_SRC_BMP, gui_rgb(3, 3, 3), 6, 16);
    gui_text_type_set((gui_text_t *)lbl_artist, "//HarmonyOS_Sans_Bold_size16_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_artist, MID_LEFT);

    // Create lbl_lyrics (hg_label)
    lbl_lyrics = gui_scroll_text_create(win_music, "lbl_lyrics", 320, 418, 290, 40);
    gui_scroll_text_set((gui_scroll_text_t *)lbl_lyrics, "Lyrics...", GUI_FONT_SRC_BMP, gui_rgb(3, 3, 3), 9, 24);
    gui_scroll_text_type_set((gui_scroll_text_t *)lbl_lyrics, "//HarmonyOS_Sans_Bold_size24_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_scroll_text_scroll_set((gui_scroll_text_t *)lbl_lyrics, SCROLL_X_MID, 0, 300, 6000, 0);
}
GUI_VIEW_INSTANCE("dashboard_view", false, dashboard_view_switch_in, dashboard_view_switch_out, false);
