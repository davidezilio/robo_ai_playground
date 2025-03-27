#include "pid.hpp"

PID::PID(double Kp, double Ki, double Kd) : Kp(Kp), Ki(Ki), Kd(Kd), prev_error(0.0), integral(0.0) {}

double PID::compute(const State& current, const std::pair<double, double>& target, double dt) {
    double error = std::hypot(current.x - target.first, current.y - target.second);
    integral += error * dt;
    double derivative = (error - prev_error) / dt;
    prev_error = error;

    return Kp * error + Ki * integral + Kd * derivative;
}
