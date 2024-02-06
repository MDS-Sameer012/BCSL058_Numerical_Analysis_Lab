// Dec 2018 , S4 ,Q2
// Write a program in C or C++ to calculate the value of ex by using its
// series expansion, given below : 20
// e^x = 1+x+ (x^2/2!) + (x^3/3!) + ...
// Note : Evaluate e^x only upto first three terms.
// Also find the value of e^x by using the inbuilt function and compare it
// with the result produced by your program.

#include <iostream>
#include <cmath>
// #include <iomanip> //if we want to use setprecision method then we add this

using namespace std;

long factorial(int n)
{
    long factorial = 1.0;
    while (n > 1)
    {
        factorial = factorial * n;
        n--;
    }
    return factorial;
}

double calculateExp(double x, int terms)
{
    double result = 0;
    for (int i = 0; i <= terms; i++)
    {
        result = result + (pow(x, i) / factorial(i));
    }
    return result;
}

int main(int argc, char const *argv[])
{
    double x;
    int terms = 3;

    cout << "Enter Value of x : ";
    cin >> x;

    // result by inbuilt function
    double resultByInbuiltFunction = exp(x);

    // result by defined function
    double resultByDefinedFuction = calculateExp(x, terms);

    printf("Value of e(%.1lf) by built in function is : %lf\n", x, resultByInbuiltFunction);
    printf("Value of e(%.1lf) by built in function is : %lf\n", x, resultByDefinedFuction);
    printf("Difference (builtIn Value - Calculated Value) in value of e(%.1lf) : %lf\n", x, resultByInbuiltFunction - resultByDefinedFuction);
    return 0;
}
