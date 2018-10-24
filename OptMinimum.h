
#ifndef ZERO_ORDER_OPT_METHODS_OPTMINIMUM_H
#define ZERO_ORDER_OPT_METHODS_OPTMINIMUM_H

#include<iostream>
#include <math.h>

using namespace std;

class OptMinimum {
private:
    double a;
    double b;
    double eps;
    double fib(unsigned int n);
public:
    OptMinimum(double leftB, double rightB, double epsilon);
    double fun(double x);
    double passiveSearch();
    double dichotomy();
    double goldRatio();
    double fibonacci();
};


#endif //ZERO_ORDER_OPT_METHODS_OPTMINIMUM_H
