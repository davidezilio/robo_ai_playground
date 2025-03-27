#include "gtest/gtest.h"
#include "pid.hpp"

TEST(PIDTest, TestControlSignal) {
    PID pid(0.1, 0.01, 0.05);
    double control_signal = pid.compute({0.0, 0.0, 0.0}, {5.0, 5.0}, 0.1);
    EXPECT_GT(control_signal, 0.0);
}
