#include "gtest/gtest.h"
#include "pathplanning.hpp"

TEST(PathPlanningTest, TestPathFinding) {
    PathPlanning planner;
    auto path = planner.findPath({0.0, 0.0, 0.0, 0.0}, {10.0, 10.0});
    EXPECT_GT(path.size(), 0);
}
