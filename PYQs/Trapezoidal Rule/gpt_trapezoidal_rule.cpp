#include <iostream>

double function(double x) {
    return x + 15;
}

double trapezoidalRule(double a, double b, double h) {
    int n = static_cast<int>((b - a) / h);  // Number of subintervals

    double result = 0.5 * (function(a) + function(b));  // First and last terms

    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        result += function(x_i);
    }

    result *= h;

    return result;
}

int main() {
    double a = 0.2;
    double b = 15.0;
    double h = 0.2;

    double integralApproximation = trapezoidalRule(a, b, h);

    std::cout << "Approximated Integral: " << integralApproximation << std::endl;

    return 0;
}
