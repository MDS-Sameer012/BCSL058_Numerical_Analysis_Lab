#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return (pow(x, 2) - x - 20);
}

double bisectionMethod(double &low, double &high, double tolerance, int &iteration, int maxIteration)
{

    // checking if given interval is correct or not
    if (f(low) * f(high) > 0)
    {
        cerr << "Invalid Interval , The value of f(x) should be of opposite sign for both endpoints"<<endl<<endl;
        return NAN;
    }

    double x;

    do
    {
        printf("Iteration : %d \t low : %lf \t high : %lf \t x : %lf \t f(x) : %lf\n", iteration, low, high, x, f(x));

        iteration++;

        x = (low + high) / 2;

        if (f(x) == 0 || (fabs(f(x)) < tolerance) || iteration >= maxIteration)
        {
            return x;
        }
        else if (f(x) > 0)
        {
            high = x;
        }
        else
        {
            low = x;
        }
    } while (true);
}

int main(int argc, char const *argv[])
{
    double low = 4.0;
    double high = 5.0;
    double tolerance = 0.0001;
    int iteration = 0;
    int maxIteration = 1000;

    cout << endl
         << "\t\t\t\t\t BISECTION METHOD \t\t\t" << endl
         << endl;
    double root = bisectionMethod(low, high, tolerance, iteration, maxIteration);
    if (isnan(root))
    {
        cout << "Please Enter/Update Correct value of high and low" << endl;
    }
    else
    {
        cout << endl
             << "*********************************************************************************************************************" << endl;
        cout << "FINAL VALUES" << endl
             << endl;
        ;
        cout << "Number of Iterations : " << iteration << endl;
        cout << "Low : " << low << endl;
        cout << "high : " << high << endl;
        cout << "Root(x) : " << root << endl;
        cout << "f(x) : " << f(root) << endl;
    }
    return 0;
}
