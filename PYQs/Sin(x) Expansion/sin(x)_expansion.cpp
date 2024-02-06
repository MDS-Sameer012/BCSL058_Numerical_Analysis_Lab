// sin(x) = x- (x^3/3!) + (x^5/5!) + ..... + (x^15/15!)

#include <iostream>
#include <cmath>

using namespace std;

double degreeToRadian(double degree)
{
    double radian = (degree * M_PI) / 180;
    cout<<"Angle in Degree : "<<degree<<endl;
    cout<<"Angle in Radian : "<<radian<<endl;
    return radian;
}

long fact(int n)
{
    long factorial = 1;
    while (n > 1)
    {
        factorial = factorial * n;
        n--;
    }
    return factorial;
}

double f(double x)
{
    double sign = 1.0;
    double result = 0;
    for (int i = 1; i <= 15; i += 2)
    {
        result = result + (sign * (pow(x, i) / fact(i)));
        sign = sign * -1.0;
    }
    return result;
}
int main(int argc, char const *argv[])
{
    double x;
    cout << "Enter Angle in Degree : ";
    cin >> x;

    double angle = degreeToRadian(x);

    double sin_x = f(angle);

    cout << "Using defined function value of Sin(" << x << ") is " << sin_x << endl;
    return 0;
}
