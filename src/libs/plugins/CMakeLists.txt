add_library(PluginManager STATIC  PluginManager.h Plugin.h PluginManager.cpp)

find_package(spdlog CONFIG REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets WebEngineWidgets REQUIRED)

include(FindQtAV)
target_include_directories(PluginManager PRIVATE ${QTAV_INCLUDE_DIRS} ${QTAVWIDGETS_INCLUDE_DIRS})
target_link_libraries(PluginManager PRIVATE
        spdlog::spdlog spdlog::spdlog_header_only
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::WebEngineWidgets
        ${QTAV_LIBRARIES}
        ${QTAVWIDGETS_LIBRARIES})
target_compile_options(PluginManager PRIVATE /source-charset:utf-8)
