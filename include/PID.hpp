#ifndef PID_HPP
#define PID_HPP

struct State {
    double x, y, theta;
};

class PID {
public:
    PID(double Kp, double Ki, double Kd);
    double compute(const State& current, const std::pair<double, double>& target, double dt);

private:
    double Kp, Ki, Kd;
    double prev_error;
    double integral;
};

#endif // PID_HPP
