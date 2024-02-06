#include <iostream>
#include <cmath>

using namespace std;

double equation(double x){
    return (1/(1+pow(x,2)));
    // return (pow(x,2)+3);
}

double trapezoidalMethod(double lowerLimit,double upperLimit,double stepSize){

    int n = (upperLimit-lowerLimit)/stepSize +1;

    double x[n],y[n];

    for(int i=0;i<n;i++){
        x[i]=lowerLimit + stepSize*i ;
        y[i] = equation(x[i]);
    }

    double y0_plus_yn=y[0] + y[n-1];
    double y1_plus_yn_minus_1=0;

    for(int i = 1;i<n-1;i++){
        y1_plus_yn_minus_1 = y1_plus_yn_minus_1+y[i];
    }

    double result = (stepSize/2)*( y0_plus_yn + (2*y1_plus_yn_minus_1));

    cout<<"Lower Limit : "<<lowerLimit<<endl;
    cout<<"Upper Limit : "<<upperLimit<<endl;
    cout<<"Step Size(h) : "<<stepSize<<endl;
    cout<<"SubIntervals : "<<n<<endl;
    cout<<"[y0+yn] : "<<y0_plus_yn<<endl;
    cout<<"[y1+y(n-1)] : "<<y1_plus_yn_minus_1<<endl;

    return result;

}

int main(int argc, char const *argv[])
{
    double lowerLimit = 0.0;
    double upperLimit = 1.0;
    double stepSize = 0.25;

    double intergralApproximation = trapezoidalMethod(lowerLimit,upperLimit,stepSize);

    cout<<"Answer : "<<intergralApproximation<<endl;
    return 0;
}
