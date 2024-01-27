#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double equation(double x)
{
    return (1 / (1 + pow(x, 2)));
}

void printtable(double arr[],int size,char name){

    cout<<name<<" : ";
    for (int i = 0; i < size; i++)
    {
        cout<<"\t"<<arr[i]<<" ["<<i<<"]";
    }
    cout<<endl;
}

double trapezoidalRule(double lowerLimit, double upperLimit, double h)
{
    int n = static_cast<int>((upperLimit - lowerLimit) / h)+1;

    double x[n];
    double y[n];

    for (int i = 0; i < n; i++)
    {
        x[i] = lowerLimit + (h*i);
        y[i] = equation(x[i]);
    }
    printtable(x,n,'X');
    printtable(y,n,'Y');

    double yo_yn = y[0] + y[n - 1];
    double y1_yn=0.0;
    for (int i = 1; i <= n - 2; i++)
    {
        y1_yn += y[i];
    }

    double ans = (h / 2) * (yo_yn + (2 * y1_yn));

    return ans;
}

int main()
{

    double lowerLimit = 0.0;
    double upperLimit = 1.0;
    double h = 0.25;

    double integralApproximation = trapezoidalRule(lowerLimit, upperLimit, h);

    cout<<"Answer : "<<fixed<<setprecision(4)<<integralApproximation<<endl;
    
    return 0;
}