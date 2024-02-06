#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return (pow(x, 2) + x + 7);
}
double forwardDifferenceOperator(double start, double end, double h)
{
    double forwardDifference;
    for (double i = start; i <= end; i += h)
    {
        forwardDifference = (f(i + h) - f(i)) / h;
        cout << "Forward difference at x : " << i << " is " << forwardDifference << endl;
    }
    return forwardDifference;
}
int main(int argc, char const *argv[])
{
    double start = 2.0;
    double end = 7.0;
    double h = 1.0;
    double forwardDifference = forwardDifferenceOperator(start, end, h);
    cout<<endl<<"FINAL VALUE"<<endl<<endl;
    cout << "Forward difference at x : " << end << " is " << forwardDifference << endl;

    return 0;
}
