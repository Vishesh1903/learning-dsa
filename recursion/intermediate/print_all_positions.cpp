#include <iostream>

using namespace std;

void printAllPositions(int arr[], int n, int key, int index)
{
    if (index == n){
        return;
    }
    if (arr[index] == key){
        cout << index << " ";
        printAllPositions(arr, n, key, index + 1);
    }else{
        printAllPositions(arr, n, key, index + 1);
    }
}

void printAllPositionsV2(int arr[], int n, int key, int index)
{
    if (index < 0){
        return;
    }
    if (arr[index] == key){
        printAllPositionsV2(arr, n, key, index - 1);
        cout << index << " ";
    }else{
        printAllPositionsV2(arr, n, key, index - 1);
    }
}

int main()
{
    int arr[] = {5, 6, 5, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key you want to search: " << endl;
    cin >> key;
    printAllPositions(arr, size, key, 0);
    cout << endl;
    printAllPositionsV2(arr, size, key, size - 1);
    return 0;
}