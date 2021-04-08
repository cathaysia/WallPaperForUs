add_library(Ui STATIC MainWindow.h MainWindow.cpp MainWindow.ui)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(Ui Qt${QT_VERSION_MAJOR}::Widgets spdlog::spdlog spdlog::spdlog_header_only PluginManager)
target_compile_options(Ui PRIVATE /source-charset:utf-8)
