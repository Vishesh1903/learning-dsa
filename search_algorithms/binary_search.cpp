#include <iostream>

using namespace std;

int binarSearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high){
        int mid = low + ((high-low) / 2);
        if (arr[mid] == key){
            return mid;
        }else if (arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the key you want to search: " << endl;
    cin >> key;

    int index = binarSearch(arr, size, key);
    if (index == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index: " << index << endl;
    }

    return 0;

}