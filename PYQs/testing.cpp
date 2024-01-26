#include <iostream>
using namespace std;

float function(float *a , float *b , int n){
    for (int i = 0; i < n; i++)
    {
        *a = *a/2;
        *b = *b/2;
    }

    return *a+*b;
    
}
int main(){
    float a = 40;
    float b = 20;
    cout<<"Original Values : "<<endl;
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    float c = function(&a,&b,2);

    cout<<"After Function Values : "<<endl;
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    cout<<"c : "<<c<<endl;
    return 0;
}