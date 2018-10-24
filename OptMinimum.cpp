#include "OptMinimum.h"

double OptMinimum :: fib(unsigned int n) {
    if (n < 3) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

OptMinimum :: OptMinimum(double leftB, double rightB, double epsilon) {
    a = leftB;
    b = rightB;
    eps = epsilon;
}

double OptMinimum :: fun(double x) {
    //cout << "computed" << endl;
    return x*x*x*x + 4*x*x - 32*x + 1;
}

double OptMinimum :: passiveSearch()
{
    double A = a;
    double B = b;
    double xmin;
    double fmin = 9999999999;
    short int counter = 0;
    int n = ((B - A) / eps) + 2;
    double func_arr[n], x_arr[n];
    for (int i = 0; i < n; i++)
    {
        x_arr[i] = A + ((B - A) / n) * i;
        func_arr[i] = fun(x_arr[i]);
        counter++;
        if (fmin > func_arr[i])
        {
            fmin = func_arr[i];
            xmin = x_arr[i];
        }
    }
    cout << "Function computed " << counter << " times, result for ";
    return xmin;
}

double OptMinimum :: dichotomy()
{
    double A = a;
    double B = b;
    double belta = eps;
    double c = ((A + B) / 2) - (belta / 2);
    double d = ((A + B) / 2) + (belta / 2);
    short int counter = 0;
    double func, fund;
    while (((B - A) / 2) > eps)
    {
        counter += 2;
        func = fun(c);
        fund = fun(d);
        if (func <= fund)
        {
            B = d;
        }
        if (func > fund)
        {
            A = c;
        }
        c = ((A + B) / 2) - (belta / 2);
        d = ((A + B) / 2) + (belta / 2);
    }
    cout << "Function computed " << counter << " times, result for ";
    return (c + d) / 2 ;
}


double OptMinimum :: goldRatio()
{
    double A = a;
    double B = b;
    double c = ((3 - sqrt(5))/2)*(B - A) + A;
    double d = ((sqrt(5) - 1)/2)*(B - A) + A;
    double func = fun(c);
    double fund = fun(d);
    short int counter = 2;
    while (((B - A) / 2) > eps)
    {
        if (func <= fund)
        {
            B = d;
            d = c;
            fund = func;
            c = ((3 - sqrt(5))/2)*(B - A) + A;
            func = fun(c);
            counter++;
        }
        if (func > fund)
        {
            A = c;
            c = d;
            func = fund;
            d = ((sqrt(5) - 1)/2)*(B - A) + A;
            fund = fun(d);
            counter++;
        }
    }
    cout << "Function computed " << counter << " times, result for ";
    return (c + d) / 2 ;
}

double OptMinimum :: fibonacci() {
    double A = a;
    double B = b;
    unsigned int n = 1;
    while (fib(n + 2) < ((B - A) / eps)) {
        n++;
    }
    double c = A + (B - A) * (fib(n) / fib(n + 2));
    double d = A + (B - A) * (fib(n + 1) / fib(n + 2));
    double func = fun(c);
    double fund = fun(d);
    short int counter = 2;
    for (int i = 2; i < n + 1; i++)
    {
        if (func <= fund)
        {
            B = d;
            d = c;
            fund = func;
            c = A + (B - A) * (fib(n + 1 - i) / fib(n + 3 - i));
            func = fun(c);
            counter++;
        }
        if (func > fund)
        {
            A = c;
            c = d;
            func = fund;
            d = A + (B - A) * (fib(n + 2 - i) / fib(n + 3 - i));
            fund = fun(d);
            counter++;
        }
    }
    cout << "Main function computed " << counter << " times, result for ";
    return c;
}