#include <iostream>

using namespace std;

int sumOfArray(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

int sumOfArrayV2(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[0] + sumOfArrayV2(arr + 1, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = sumOfArrayV2(arr, size);
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}