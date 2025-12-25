#include <iostream>
#include <cmath>

using namespace std;

double pow(int num, int n){
    if(n == 0 || num == 1){
        return 1;
    }
    return num * pow(num, n - 1);
}

int main(){

    int n;
    double num;

    cout << "Enter the number and power to calculate" << endl;
    cin >> num >> n;

    if(n < 0){
        num = 1/num;
        n = abs(n);
    }

    double result = pow(num, n);

    cout << "The power of " << n << " of number " << num << " is " << endl;
    cout << result;
    return 0;
}