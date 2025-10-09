#include <iostream>
#include <vector>
using namespace std;

int countZeroes(int num)
{
    if(num == 0){
        return 0;
    }
    if (num%10 == 0)
    {
        return 1 + countZeroes(num/10);
    }else{
        return countZeroes(num/10);
    }
}

int main()
{
    int num = 1200;
    int ans = countZeroes(num);

    cout << "Number of Zeroes in " << num << " is: " << ans << endl;

    return 0;
}