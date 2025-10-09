#include <iostream>
#include <vector>
using namespace std;

int getFibonaccSequence(int n)
{
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    return getFibonaccSequence(n - 1) + getFibonaccSequence(n - 2);
}

void printFibonacciSequence(int n, int i = 1)
{
    if(i > n)
        return;
    cout << getFibonaccSequence(i) << " ";
    printFibonacciSequence(n,i + 1);
}

int main()
{

    int n;

    cout << "Enter the value of n: " << endl;
    cin >> n;
    printFibonacciSequence(n);

    return 0;
}