#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double equation(double x){
    return (pow(x,3) - (4*x) -9);
}

double bisectionMethod(double &low , double &high ,double tolerance , int &iteration){
    
    // checking if given interval is valid or not 
    if(equation(low)*equation(high)>0){
        cerr<<"Invalid Interval , The function should give opposite sign for give interval endpoints"<<endl;
        return NAN;
    }
    
    double x;
    cout<<"iteration \t low \t high \t x \t f(x)";
    do{
        x = (low+high)/2;
        iteration++;
        cout<<iteration<<" \t "<<low<<" \t "<<high<<" \t "<<x<<" \t "<<equation(x)<<endl;
        if((equation(x)==0) || (fabs(high-low)<tolerance))
        {
            return x;
        }
        else if(equation(x)>0){
            high = x;
        }
        else{
            low = x; 
        }
    }while(true);
    // return x;
}

int main(){
    double low = 2.0;
    double high = 3.0;
    double tolerance = 0.001;
    int iteration = 0;

    double root  = bisectionMethod(low,high,tolerance,iteration);

    cout<<endl<<"Final Values "<<endl<<endl;
    cout<<"Iterations : "<<fixed<<setprecision(3)<<iteration<<endl;
    cout<<"Low : "<<fixed<<setprecision(3)<<low<<endl;
    cout<<"High : "<<fixed<<setprecision(3)<<high<<endl;
    cout<<"f(x) : "<<fixed<<setprecision(3)<<equation(root)<<endl;
    cout<<"x : "<<fixed<<setprecision(3)<<root<<endl;
    return 0;
}