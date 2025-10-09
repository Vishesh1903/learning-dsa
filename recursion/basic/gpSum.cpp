#include <iostream>
#include <vector>
using namespace std;

double GPSum(int k)
{
    if(k == 0){
        return 1;
    }
    return GPSum(k-1) + 1.0/pow(2, k);
}

int main()
{
    int terms = 3;
    double ans = GPSum(terms);

    cout << "Sum of " << terms << " terms" << " in GP is: " << ans << endl;

    return 0;
}