// 2D Car Simulator with EKF, A* Path Planning, and PID Control
// Organized into separate modules: dynamics, EKF, pathplanning, and PID
// Unit tests included with GTest

#include <iostream>
#include "dynamics.hpp"
#include "ekf.hpp"
#include "pathplanning.hpp"
#include "pid.hpp"

int main() {
    std::cout << "Starting 2D Car Simulator..." << std::endl;
    
    // Initialize simulator, sensor models, and control modules
    Dynamics car;
    EKF ekf;
    PathPlanning planner;
    PID controller(0.1, 0.01, 0.05); // Example PID gains
    
    // Simulation loop variables
    double dt = 0.1; // Time step
    double target_x = 10.0, target_y = 10.0;
    
    while (true) {
        // 1. Update car dynamics with noisy controls
        car.update(dt);
        
        // 2. Generate noisy GNSS and IMU data
        auto gnss_data = car.getNoisyGNSS();
        auto imu_data = car.getNoisyIMU();
        
        // 3. Apply EKF to estimate position
        ekf.update(gnss_data, imu_data, dt);
        auto estimated_position = ekf.getState();
        
        // 4. Compute target waypoints using A*
        auto path = planner.findPath(estimated_position, {target_x, target_y});
        if (path.empty()) {
            std::cerr << "No valid path found!" << std::endl;
            break;
        }
        
        // 5. Use PID to generate actuator commands
        auto control_signal = controller.compute(estimated_position, path.front(), dt);
        
        // 6. Update simulation based on control commands
        car.applyControl(control_signal);
        
        // Debug output
        std::cout << "Estimated Position: " << estimated_position.x << ", " << estimated_position.y << std::endl;
        
        // Exit condition for simulation
        if (std::hypot(estimated_position.x - target_x, estimated_position.y - target_y) < 0.5) {
            std::cout << "Target reached!" << std::endl;
            break;
        }
    }
    
    return 0;
}


