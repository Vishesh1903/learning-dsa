#include <iostream>

using namespace std;

//Recursion works on Principle of Mathematical Induction
//First step is to define a base case
//Then we define the recursive case
//Each recursive call should bring us closer to the base case


int factorial(int n){
    //Base Case
    if(n == 0 || n == 1){
        return 1;
    }
    int smallAns = factorial(n-1); // Induction Hypothesis assuming fact(k) works for k < n
    return n * smallAns; // Induction Step to prove fact(n) works
}


int main(){

    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}