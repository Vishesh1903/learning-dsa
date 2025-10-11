#include <iostream>

using namespace std;

int towerOfHanoi(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }
    return towerOfHanoi(n - 1) + 1 + towerOfHanoi(n - 1);
}

void printTowerOfHanoiV2(int n, int s, int d, int h)
{
    if (n == 0)
    {
        return;
    }
    printTowerOfHanoiV2(n - 1, s, h, d);
    cout << s << "->" << d << endl;
    printTowerOfHanoiV2(n - 1, h, d, s);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int moves = towerOfHanoi(n);

    printTowerOfHanoiV2(n, 1, 3, 2);

    cout << moves << endl;
    return 0;
}