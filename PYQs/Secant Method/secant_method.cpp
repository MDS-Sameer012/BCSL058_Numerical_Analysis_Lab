#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return (pow(x,3) + x - 6);
}

double secantMethod(double &low,double &high,double tolerance,int iteration, int maxIteration){

    // checking for valid interval
    if(f(low)*f(high)>0){
        cerr<<"Invalid Interval,the vlaue of f(x) for endpoints of interval should be of opp. sign"<<endl;
        return NAN;
    }

    double x;

    do{
        iteration++;

        x = ((low*f(high))-(high*f(low)))/(f(high)-f(low));

        cout<<"Iteration : "<<iteration<<"\t low : "<<low<<"\t high : "<<high<<"\t x : "<<x<<"\t f(x) : "<<f(x)<<"\t fabs(f(x)) : "<<fabs(f(x))<<endl;

        if(f(x)==0 || fabs(f(x))<tolerance || iteration>=maxIteration){
            return x ;
        }
        else{
            low =  high;
            high = x;
        }
    }while(true);
}
int main(int argc, char const *argv[])
{
    double low=1;
    double high=2;
    double tolerance = 0.00001;
    int iteration =0;
    int maxIteration = 1000;

    cout<<"\t\t\t\t\t SECANT METHOD"<<endl;

    double root = secantMethod(low,high,tolerance,iteration,maxIteration);

    cout<<"*******************************************************************************************"<<endl;

    cout<<"FINAL VALUES"<<endl;
    cout<<"low : "<<low<<endl;
    cout<<"high : "<<high<<endl;
    cout<<"root(x) : "<<root<<endl;
    cout<<"f(x) : "<<f(root)<<endl;

    return 0;
}
