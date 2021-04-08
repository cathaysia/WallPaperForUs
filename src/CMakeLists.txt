set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set qt version
if(NOT DEFINED ENV{QT_VERSION_MAJOR})
    set(QT_VERSION_MAJOR 5)
endif()

# for qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(libs)
add_subdirectory(libs)

add_subdirectory(app)
