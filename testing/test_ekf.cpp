#include "gtest/gtest.h"
#include "ekf.hpp"

TEST(EKFTest, TestStateUpdate) {
    EKF ekf;
    ekf.update({5.0, 5.0}, 0.1, 0.1);
    auto state = ekf.getState();
    EXPECT_NEAR(state.x, 5.1, 0.1);
    EXPECT_NEAR(state.y, 5.1, 0.1);
    EXPECT_NEAR(state.theta, 0.15, 0.1);
}
