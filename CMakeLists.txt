cmake_minimum_required(VERSION 3.15)
project(SensorProject)

set(CMAKE_CXX_STANDARD 17)

# vcpkg
if(DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "Using vcpkg toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
endif()

# הוספת include
include_directories(include)

# ספריית קוד מקור
add_library(sensor_lib
    src/sensor.cpp
)
target_include_directories(sensor_lib PUBLIC include)

# הרצת הקוד הראשי
add_executable(sensor_app
    src/main.cpp
)
target_link_libraries(sensor_app PRIVATE sensor_lib spdlog::spdlog)
find_package(spdlog REQUIRED)

# -------------------
# טסטים
# -------------------

# הפעלת טסטינג
enable_testing()

# GoogleTest
find_package(GTest CONFIG REQUIRED)

# אקזקיוטבל של הטסטים
add_executable(sensor_tests
    tests/sensor_test.cpp
)
target_link_libraries(sensor_tests
    PRIVATE sensor_lib GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sensor_tests)
