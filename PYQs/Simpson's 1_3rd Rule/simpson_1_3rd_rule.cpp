#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return (cbrt(x));
    // return (pow(x,2)+3);
}
void printArray(double arr[], int size, char name)
{
    cout << name << " : [ ";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {

            cout << arr[i] << " ]" << endl;
            break;
        }
        cout << arr[i] << " , ";
    }
}
double simpsonOneThirdRule(double lowerLimit, double upperLimit, double h)
{

    int n = ((upperLimit - lowerLimit) / h) + 1;
    double x[n], y[n];
    double sum;

    for (int i = 0; i < n; i++)
    {
        x[i] = lowerLimit + h * i;
        y[i] = f(x[i]);
    }

    sum = y[0] + y[n - 1];

    for (size_t i = 1; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + 2 * y[i];
        }
        else
        {
            sum = sum + 4 * y[i];
        }
    }
    double result = sum * (h / 3);
    printArray(x, n, 'X');
    printArray(y, n, 'Y');
    cout << "Lower Limit : " << lowerLimit << endl;
    cout << "Upper Limit : " << upperLimit << endl;
    cout << "Step Size (h) : " << h << endl;
    return result;
}

int main(int argc, char const *argv[])
{
    double lowerLimit = 0.2;
    double upperLimit = 1.0;
    double h = 0.2;

    double intergralApproximation = simpsonOneThirdRule(lowerLimit, upperLimit, h);

    cout << "Answer : " << intergralApproximation << endl;

    return 0;
}
