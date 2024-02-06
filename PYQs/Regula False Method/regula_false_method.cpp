#include <iostream>
#include <cmath>

using  namespace std;

double equation(double x){
    return (pow(x,3) + 4*pow(x,2) -10);
}

double regulaFalsiMethod(double &low,double &high,double tolerance ,int iteration,int maxIteration){
    // checking if given interval is valid

    if(equation(low)*equation(high)>0){
        cerr<<"Invalid Interval , Value of f(x) should be of opp. sign for endpoints of interval"<<endl;
        return NAN;
    }

    double x;

    do{
        iteration++;
        x = ((low*equation(high))-(high*equation(low)))/(equation(high)-equation(low));

        cout<<"iteration : "<<iteration<<"\t low : "<<low<<"\t high : "<<high<<"\t x : "<<x<<"\t f(x) : "<<equation(x)<<endl;

        if((equation(x)==0) || (fabs(equation(x))<tolerance) || (iteration>=maxIteration)){
            return x; 
        }else if(equation(x)>0){
            high= x;
        }
        else{
            low = x;
        }
    }while(true);
}

int main(int argc, char const *argv[])
{
    double low=1 ;
    double high=2;
    double tolerance = 0.00001;
    double iteration =0;
    double maxIteration=1000;

    cout<<"\t\t\t\t\t Regula Falsi Method"<<endl;

    double root = regulaFalsiMethod(low,high,tolerance,iteration,maxIteration);

    cout<<"*************************************************************************************"<<endl;
    cout<<"FINAL VALUES"<<endl;
    cout<<"low : "<<low<<endl;
    cout<<"high : "<<high<<endl;
    cout<<"root(x) : "<<root<<endl;
    cout<<"f(x) : "<<equation(root)<<endl;
    return 0;
}
