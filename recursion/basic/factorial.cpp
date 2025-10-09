#include <iostream>

using namespace std;

int factorial(int n){
    if( n < 0){
        return -1;
    }
    if(n == 0 || n == 1){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}


int main (){
    int n;

    cout << "Enter the value of n: " << endl;
    cin >> n;

    int ans = factorial(n);

    cout << "Factorial of " << n << " is: " << ans << endl;

    return 0;
}