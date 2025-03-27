#include "pathplanning.hpp"
#include <cmath>
#include <queue>

struct Node {
    double x, y;
    double cost, heuristic;
};

class CompareNode {
public:
    bool operator()(Node const& n1, Node const& n2) {
        return (n1.cost + n1.heuristic) > (n2.cost + n2.heuristic);
    }
};

PathPlanning::PathPlanning() {}

std::vector<std::pair<double, double>> PathPlanning::findPath(const State& current_state, std::pair<double, double> target) {
    std::vector<std::pair<double, double>> path;
    std::priority_queue<Node, std::vector<Node>, CompareNode> open_list;

    // Simple A* pathfinding: expand nodes towards the target
    open_list.push({current_state.x, current_state.y, 0.0, std::hypot(target.first - current_state.x, target.second - current_state.y)});

    while (!open_list.empty()) {
        Node current = open_list.top();
        open_list.pop();

        if (std::hypot(current.x - target.first, current.y - target.second) < 1.0) {
            path.push_back({current.x, current.y});
            break;
        }

        // Expand nodes (simplified)
        open_list.push({current.x + 1.0, current.y, current.cost + 1.0, std::hypot(target.first - (current.x + 1.0), target.second - current.y)});
        open_list.push({current.x, current.y + 1.0, current.cost + 1.0, std::hypot(target.first - current.x, target.second - (current.y + 1.0))});
    }

    return path;
}
