#include <iostream>
using namespace std;

int stepsToReachN(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n < 0)
    {
        return 0;
    }
    return stepsToReachN(n - 1) + stepsToReachN(n - 2) + stepsToReachN(n - 3);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int ways = stepsToReachN(n);

    cout << ways << endl;
    return 0;
}