#include <iostream>

using namespace std;

int getNthTermInFibonacciSequence(int n)
{
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    return getNthTermInFibonacciSequence(n - 1) + getNthTermInFibonacciSequence(n - 2);
}

int main()
{

    int n;

    cout << "Enter the value of n: " << endl;
    cin >> n;

    int ans = getNthTermInFibonacciSequence(n);
    cout << "The term at " << n << "th position in Fibonacci sequence is: " << ans << endl;
    return 0;
}