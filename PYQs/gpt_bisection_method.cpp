#include <iostream>
#include <cmath>

double equation(double x) {
    return pow(x, 3) - (4 * x) - 9;
}

double bisectionMethod(double a, double b, double tolerance) {
    if (equation(a) * equation(b) > 0) {
        std::cerr << "Invalid interval. The function values at endpoints must have opposite signs." << std::endl;
        return NAN;  // Return NaN (Not a Number) to indicate an error
    }

    double c;

    do {
        // Find midpoint
        c = (a + b) / 2;

        // Check if midpoint is the root or the tolerance is met
        if (equation(c) == 0 || (b - a) / 2 < tolerance)
            break;

        // Update interval based on the sign of the function at the midpoint
        (equation(c) * equation(a) < 0) ? b = c : a = c;

    } while (true);

    return c;
}

int main() {
    double a = 2.0;  // Lower limit of the interval
    double b = 3.0;  // Upper limit of the interval
    double tolerance = 0.001;  // Tolerance for stopping the iteration means correct upto how much decimal place

    double root = bisectionMethod(a, b, tolerance);

    if (!std::isnan(root))
        std::cout << "Root found at x = " << root << std::endl;
    
    printf("a : %f , b : %f\n",a,b);
    return 0;
}
