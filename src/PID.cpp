#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    // Change from previous cte:
    d_error = cte - p_error;
    // Crosstrack error (how far off the center of the road):
    p_error = cte;
    // Cumulative error of other errors:
    i_error += cte;
}

double PID::TotalError() {
    return Kp * p_error + Ki * i_error + Kd * d_error;
}
