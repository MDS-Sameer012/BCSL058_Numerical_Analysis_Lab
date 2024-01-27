#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double equation(double x){
    return (pow(x,3))-(4*x)-9;
}

double bisectionMethod(double &low,double &high,int &iteration,double tolerance){

    if(equation(low) * equation(high) >0){
        cout<<"Please Enter Correct Interval , The function value at endpoints must be of opposite sign"<<endl;
        return NAN;
    }
    double x;
    do{
    iteration++;
     x = double(low+high)/2;

    if((equation(x)==0) || (fabs(high-low) < tolerance)){
        break;
    }
    else if(equation(x) > 0){
        high = x;
    }
    else{
        low = x;
    } 
        cout<<"Iteration : "<<iteration<<"\tLow : "<<low<<"\tHigh : "<<high<<"\tx : "<<x<<"\tf(x) : "<<equation(x)<<endl;
    }while(true);
    return x;
}
int main(){
   
    double low = 2.0;
    double high = 3.0;
    double tolerance = 0.001;
    int iteration = 0;
    
    double root = bisectionMethod(low,high,iteration,tolerance);

    cout<<"**************************"<<endl;
    cout<<"no of iteration : "<<iteration<<endl;
    cout<<"low : "<<fixed<<setprecision(3)<<low<<endl;
    cout<<"high : "<<fixed<<setprecision(3)<<high<<endl;
    cout<<"root : "<<fixed<<setprecision(3)<<root<<endl;
    return 0;
}