cmake_minimum_required(VERSION 3.10)
project(SensorProject)

# הפעלת C++17
set(CMAKE_CXX_STANDARD 17)

# הוספת קבצי קוד
add_executable(sensor_app src/main.cpp)
target_include_directories(sensor_app PRIVATE include)

# טסטים
enable_testing()

# הוספת אקזקיוטבל לטסטים
add_executable(sensor_tests tests/sensor_test.cpp)
target_include_directories(sensor_tests PRIVATE include)

# קישור ל-GoogleTest דרך vcpkg
find_package(GTest CONFIG REQUIRED)
target_link_libraries(sensor_tests PRIVATE GTest::gtest GTest::gtest_main)

# רישום הטסטים
include(GoogleTest)
gtest_discover_tests(sensor_tests)
