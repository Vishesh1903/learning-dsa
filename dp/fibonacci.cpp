#include <iostream>


using namespace std;

int fib1(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

long long fib(long long arr[], int n, int i = 2){
    if(i == n){
        return arr[i - 1] + arr[i - 2];
    }
    arr[i] = arr[i - 1] + arr[i - 2];
    return fib(arr, n, i + 1);
}

int main(){
    constexpr long long n = 50;
    long long arr[n + 1] = { 0, 1 };
    cout << fib(arr, n , 2) << endl;
    return 0;
}