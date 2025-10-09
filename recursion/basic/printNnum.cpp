#include <iostream>
#include <vector>
using namespace std;

void printNnum(int n)
{
    if(n < 0){
        cout << "N should be greater than 0" << endl;
        return;
    }
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printNnum(n - 1);

}
int main()
{

    int n;

    cout << "Enter the value of n: " << endl;
    cin >> n;
    printNnum(n);

    return 0;
}