#include "gui_api.h"
#include "gui_view.h"
#include "gui_components_init.h"
#include "gui_vfs.h"
#include "hg_romfs.h"

extern const struct romfs_dirent app_romfs_root;

static int app_init(void)
{
#ifdef _HONEYGUI_SIMULATOR_
    // Simulator: Mount POSIX filesystem
    gui_vfs_mount_posix("/", "./assets");
#else
    // SOC: Mount romfs from embedded data
    gui_vfs_mount_romfs("/", &app_romfs_root, 0);
#endif

    gui_view_create(gui_obj_get_root(), "dashboardMainView", 0, 0, 0, 0);
    return 0;
}

GUI_INIT_APP_EXPORT(app_init);
