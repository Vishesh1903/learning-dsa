#include <iostream>
#include <vector>
using namespace std;

int multiply(int num1, int num2)
{
    if (num2 == 0)
    {
        return 0;
    }
    return num1 + multiply(num1, num2-1);
}

int main()
{
    int num1 = 4;
    int num2 = 5;
    int ans = multiply(num1, num2);

    cout << "Product of " << num1 << " and " << num2 << " is: " << ans << endl;


    return 0;
}