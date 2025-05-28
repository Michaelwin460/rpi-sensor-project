cmake_minimum_required(VERSION 3.15)
project(SensorProject)

set(CMAKE_CXX_STANDARD 17)

# הוספת תמיכה ב-vcpkg
if(DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "Using vcpkg toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
endif()

# include לספריות שלך
include_directories(include)

# קובץ ההרצה
add_executable(sensor_app
    src/main.cpp
    src/sensor.cpp
)

# מציאת ספריית spdlog שהתקנת עם vcpkg
find_package(spdlog REQUIRED)
target_link_libraries(sensor_app PRIVATE spdlog::spdlog)
