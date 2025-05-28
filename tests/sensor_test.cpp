#include <gtest/gtest.h>
#include "../include/sensor.h"

TEST(SensorTest, ReadReturnsValueBetween20And120) {
    Sensor s;
    double value = s.read();
    EXPECT_GE(value, 20.0) << "Value is too low: " << value;
    EXPECT_LE(value, 120.0) << "Value is too high: " << value;
}
