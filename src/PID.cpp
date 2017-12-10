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
    this->p_error = 0.0;
    this->i_error = 0.0; 
    this->d_error = 0.0;
    this->sse = 0.0;
    this->n = 1;
}

void PID::UpdateError(double cte) {
    sse += cte*cte;
    //double avg_error = sse / n;
    //cout << n-1 << ";" << average_error << ";" << cte << endl;
    //n++; 

    this->d_error = cte - this->p_error;
    this->p_error = cte;
    this->i_error += cte;
}

double PID::TotalError() {
  return this->Kp * this->p_error
         + this->Ki * this->i_error
         + this->Kd * this->d_error;
}

