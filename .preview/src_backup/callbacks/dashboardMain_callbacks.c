#include "dashboardMain_callbacks.h"
#include "../ui/dashboardMain_ui.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// 事件回调函数实现

/* @protected start custom_functions */
// 自定义函数
static void char text_time_time_str[8] = {0};

void time_update_cb(void *p)
{
    GUI_UNUSED(p);
    gui_log("enter timer cb\n");
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(text_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    gui_log("%s\n", text_time_time_str);
    gui_text_content_set((gui_text_t *)p, text_time_time_str, strlen(text_time_time_str));
}
/* @protected end custom_functions */
