#include "dynamics.hpp"
#include <cmath>

Dynamics::Dynamics() : state{0.0, 0.0, 0.0, 0.0}, gnss_noise(0.0, 1.0), imu_noise(0.0, 0.05) {}

void Dynamics::update(double dt) {
    // Simple car dynamics: x' = v * cos(theta), y' = v * sin(theta), theta' = v / L
    state.x += state.velocity * cos(state.theta) * dt;
    state.y += state.velocity * sin(state.theta) * dt;
    state.theta += state.velocity * dt;  // Assuming a simple model for turning

    // Add random noise
    state.x += gnss_noise(generator);
    state.y += gnss_noise(generator);
    state.theta += imu_noise(generator);
}

void Dynamics::applyControl(double control_signal) {
    state.velocity = control_signal;  // Apply the control signal directly as speed
}

State Dynamics::getState() const {
    return state;
}

std::pair<double, double> Dynamics::getNoisyGNSS() const {
    return {state.x + gnss_noise(generator), state.y + gnss_noise(generator)};
}

double Dynamics::getNoisyIMU() const {
    return state.theta + imu_noise(generator);
}
