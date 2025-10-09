#include <iostream>
#include <vector>
using namespace std;

long calculatePower(int n, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return n * calculatePower(n, pow - 1);
}
int main()
{

    int n;

    cout << "Enter the value of n: " << endl;
    cin >> n;
    long ans = calculatePower(2, n);
    cout << "2^" << n << " is: " << ans << endl;

    return 0;
}