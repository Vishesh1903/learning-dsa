#include <iostream>
#include <vector>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n%10 + sumOfDigits(n / 10);
}

int main()
{
    int num = -123;
    int ans = sumOfDigits(num);

    cout << "Number of digits in " << num << " is: " << ans << endl;

    return 0;
}