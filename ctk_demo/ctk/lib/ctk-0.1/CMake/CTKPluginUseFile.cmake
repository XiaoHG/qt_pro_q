# List all plugins
set(CTK_PLUGIN_LIBRARIES org_commontk_configadmin;org_commontk_eventadmin;org_commontk_log;org_commontk_metatype)

if(NOT CTK_PLUGIN_LIBRARIES_set)
  set_property(GLOBAL APPEND PROPERTY CTK_PLUGIN_LIBRARIES_VARS CTK_PLUGIN_LIBRARIES)
  set(CTK_PLUGIN_LIBRARIES_set 1)
endif()

# Plugin specific include directories

set(org_commontk_configadmin_INCLUDE_DIRS "E:/ctk/Plugins/org.commontk.configadmin;E:/ctk/build/CTK-build/Plugins/org.commontk.configadmin;E:/ctk/build/CTK-build;E:/ctk/Libs/PluginFramework;E:/ctk/build/CTK-build/Libs/PluginFramework;E:/ctk/Libs/Core;E:/ctk/build/CTK-build/Libs/Core")
set(org_commontk_eventadmin_INCLUDE_DIRS "E:/ctk/Plugins/org.commontk.eventadmin;E:/ctk/build/CTK-build/Plugins/org.commontk.eventadmin;E:/ctk/build/CTK-build;E:/ctk/Libs/PluginFramework;E:/ctk/build/CTK-build/Libs/PluginFramework;E:/ctk/Libs/Core;E:/ctk/build/CTK-build/Libs/Core")
set(org_commontk_log_INCLUDE_DIRS "E:/ctk/Plugins/org.commontk.log;E:/ctk/build/CTK-build/Plugins/org.commontk.log;E:/ctk/build/CTK-build;E:/ctk/Libs/PluginFramework;E:/ctk/build/CTK-build/Libs/PluginFramework;E:/ctk/Libs/Core;E:/ctk/build/CTK-build/Libs/Core")
set(org_commontk_metatype_INCLUDE_DIRS "E:/ctk/Plugins/org.commontk.metatype;E:/ctk/build/CTK-build/Plugins/org.commontk.metatype;E:/ctk/build/CTK-build;E:/ctk/Libs/PluginFramework;E:/ctk/build/CTK-build/Libs/PluginFramework;E:/ctk/Libs/Core;E:/ctk/build/CTK-build/Libs/Core")

# Plugin specific library directories

set(org_commontk_configadmin_LIBRARY_DIRS "")
set(org_commontk_eventadmin_LIBRARY_DIRS "")
set(org_commontk_log_LIBRARY_DIRS "")
set(org_commontk_metatype_LIBRARY_DIRS "")
