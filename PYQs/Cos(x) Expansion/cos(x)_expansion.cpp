// cos(x) = 1- (x^2/2!) + (x^4/4!) - (x^6/6!) +....

#include <iostream>
#include <cmath>

using namespace std;

double fact(double n)
{
    double factorial = 1;
    while (n > 1)
    {
        factorial *= n;
        n--;
    }
    return factorial;
}

double degreeToRadian(double degree)
{
    double radian = degree * (M_PI / 180);
    return radian;
}

double calculateCos(double x)
{
    double sign = 1.0;
    double result = 0;
    int no_of_steps = 3;

    for (int i = 0; i <= no_of_steps*2; i += 2)
    {
        result += sign * (pow(x, i) / fact(i));
        sign *= -1.0;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    double angleInDegree;
    cout << "Enter Angle in Degree : ";
    cin >> angleInDegree;

    double angle = degreeToRadian(angleInDegree);

    double cos_x = calculateCos(angle);

    cout << "Value of cos(" << angle << ") by User Defined Function is : " << cos_x << endl;
    cout << "Value of cos(" << angle << ") by Built in Function is : " << cos(angle) << endl;
    cout << "Difference in built-in cos function value and user defined cos function value is " << cos(angle) - calculateCos(angle) << endl;
    return 0;
}
