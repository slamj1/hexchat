#undef HAVE_STRINGS_H
#undef HAVE_MEMRCHR

#include "config.h"
#include "exports.h"
#include "hexchat-plugin.h"

static char *NAME = "python";
static char *VERSION = "1.0";
static hexchat_plugin *ph;

int
hexchat_plugin_init(hexchat_plugin *plugin_handle,
                    char **plugin_name,
                    char **plugin_desc,
                    char **plugin_version,
                    char *arg)
{
    ph = plugin_handle;
    *plugin_name = NAME;
    *plugin_version = VERSION;
    *plugin_desc = "FOoo";

    hexchat_hook_command(ph, "pytest", HEXCHAT_PRI_NORM, on_pytest, NULL, NULL);

    return 1;
}

int
hexchat_plugin_deinit(void)
{
    return 1;
}
