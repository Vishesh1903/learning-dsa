#include <iostream>

using namespace std;

void printArray(int arr[][2], int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int a[][2] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    printArray(a, 3, 2);
    return 0;
}