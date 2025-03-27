#include "ekf.hpp"

EKF::EKF() : process_noise(0.1), measurement_noise(0.5) {}

void EKF::update(const std::pair<double, double>& gnss_data, double imu_data, double dt) {
    // A simple example of EKF update with basic state prediction and measurement update
    // Here, for simplicity, we are directly overwriting the state with noisy measurements
    state.x = gnss_data.first + process_noise;
    state.y = gnss_data.second + process_noise;
    state.theta = imu_data + process_noise;
}

State EKF::getState() const {
    return state;
}
