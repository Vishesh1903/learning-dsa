#include <iostream>
#include <vector>
using namespace std;

int countNoOfDigits(int n)
{
    if(n == 0){
        return 0;
    }
    return 1 + countNoOfDigits(n / 10);
}

int main()
{
    int num = 44345;
    int ans = countNoOfDigits(num);

    cout << "Number of digits in " <<num <<  " is: " << ans << endl;


    return 0;
}