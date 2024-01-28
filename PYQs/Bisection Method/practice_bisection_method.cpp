#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double equation(double x)
{
    return ((pow(x, 2)) + (2 * x) - 3);
}

double bisectionMethod(double &low, double &high, double tolerance, int &iteration)
{
    // checking if given interval is correct
    if (equation(low) * equation(high) > 0)
    {
        cerr << "Invalid Interval , The endpoint of interval should return opposite sign for f(x)" << endl;
        return NAN;
    }

    double x;

    do
    {
        iteration++;
        x = (low + high) / 2;

        printf("Iteration : %d \t Low : %.2f \t High : %.2f \t x : %.2f \t f(x) : %.2f \n", iteration, low, high, x, equation(x));

        if ((equation(x) == 0) || (fabs(high - low) < tolerance))
        {
            return x;
        }
        else if (equation(x) < 0)
        {
            low = x;
        }
        else
        {
            high = x;
        }
    } while (true);
}

int main()
{

    double low = 0;
    double high = 3;
    double tolerance = 0.01;
    int iteration = 0;

    double root = bisectionMethod(low, high, tolerance, iteration);

    cout << "*******************************************" << endl
         << endl;
    cout << "FINAL RESULT" << endl;
    cout << endl
         << "Number of Iteration : " << iteration << endl;
    cout << "low : " <<fixed<<setprecision(2)<< low << endl;
    cout << "high : " <<fixed<<setprecision(2)<< high << endl;
    cout << "x(root) : " <<fixed<<setprecision(2)<< root << endl;

    return 0;
}