#ifndef DYNAMICS_HPP
#define DYNAMICS_HPP

#include <iostream>
#include <random>

struct State {
    double x, y, theta, velocity;
};

class Dynamics {
public:
    Dynamics();
    void update(double dt);
    void applyControl(double control_signal);
    State getState() const;
    std::pair<double, double> getNoisyGNSS() const;
    double getNoisyIMU() const;

private:
    State state;
    std::default_random_engine generator;
    std::normal_distribution<double> gnss_noise;
    std::normal_distribution<double> imu_noise;
};

#endif // DYNAMICS_HPP
