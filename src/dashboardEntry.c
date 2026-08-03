#include "gui_api.h"
#include "gui_view.h"
#include "gui_components_init.h"
#include "gui_vfs.h"

/* @protected start entry_includes */
// Add user includes here
/* @protected end entry_includes */

static int app_init(void)
{
#ifdef _HONEYGUI_SIMULATOR_
    // Simulator: Mount POSIX filesystem
    gui_vfs_mount_posix("/", "./assets");
#else
    // SOC: Mount romfs from flash address
    gui_vfs_mount_romfs("/", (void *)0x08440000, 0);
#endif

    /* @protected start app_init_pre */
    // Add user initialization code here (runs before the main view is created)
#if !defined(DASHBOARD_USE_THIRD_PARTY_NAV) || defined(_HONEYGUI_SIMULATOR_)
    extern int app_stream_transport_init(void);
    if (app_stream_transport_init() != 0)
    {
        gui_log("dashboard: stream transport init failed\n");
    }
#endif
    /* @protected end app_init_pre */

    gui_view_create(gui_obj_get_root(), "dashboardMainView", 0, 0, 0, 0);

    /* @protected start app_init_post */
    // Add user initialization code here (runs after the main view is created)
    /* @protected end app_init_post */

    return 0;
}

GUI_INIT_APP_EXPORT(app_init);
