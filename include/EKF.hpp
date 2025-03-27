#ifndef EKF_HPP
#define EKF_HPP

#include "dynamics.hpp"

class EKF {
public:
    EKF();
    void update(const std::pair<double, double>& gnss_data, double imu_data, double dt);
    State getState() const;

private:
    State state;
    // Example: EKF parameters like process noise, measurement noise, etc.
    double process_noise, measurement_noise;
};

#endif // EKF_HPP
