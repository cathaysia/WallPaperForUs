

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_executable(App WIN32 ${SOURCE_FILES})
else ()
    add_executable(App ${SOURCE_FILES})
endif ()

target_sources(App PRIVATE main.cpp)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
target_link_libraries(App PRIVATE Ui Qt${QT_VERSION_MAJOR}::Core)
target_compile_options(App PRIVATE /source-charset:utf-8)
