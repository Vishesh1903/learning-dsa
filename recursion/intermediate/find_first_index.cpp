#include <iostream>

using namespace std;

int findFirstIndex(int arr[], int n, int key, int index = 0)
{

    if (index == n)
    {
        return -1;
    }
    if (arr[index] == key)
    {
        return index;
    }
    else
    {
        return findFirstIndex(arr, n, key, index + 1);
    }
}

int main()
{
    int arr[] = {1, 2, 2, 4, 5, 5, 5, 6, 5, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the key you want to search: " << endl;
    cin >> key;

    int index = findFirstIndex(arr, size, key, 0);
    if (index == -1)
    {
        cout << "Key not found" << endl;
    }
    else
    {
        cout << "Key first found at index: " << index << endl;
    }
    return 0;
}