#include "OptMinimum.h"

int main()
{
    //our function: f(x) = x^4 + 4*x^2 - 32*x + 1
    double a, b, eps;
    cout << "Define the segment by inputing 2 positive numbers a and b (a <= b):" << endl;
    cin >> a >> b;
    cout << "Input Epsilon:" << endl;
    cin >> eps;
    OptMinimum myConstrait(a, b, eps);
    cout << "Passive Search method: "<< myConstrait.passiveSearch() << endl;
    cout << "Dichotomy method: " << myConstrait.dichotomy() << endl;
    cout << "Gold Ratio method " << myConstrait.goldRatio() << endl;
    cout << "Fibonacci method: " << myConstrait.fibonacci() << endl;
    return 0;
}
