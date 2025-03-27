#ifndef PATHPLANNING_HPP
#define PATHPLANNING_HPP

#include <vector>
#include <tuple>

class PathPlanning {
public:
    PathPlanning();
    std::vector<std::pair<double, double>> findPath(const State& current_state, std::pair<double, double> target);
};

#endif // PATHPLANNING_HPP
