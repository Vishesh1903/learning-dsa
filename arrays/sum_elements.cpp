#include <iostream>

using namespace std;

int main(){

    int arr[5] = {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Size of the array: " << size << endl;

    int sum = 0;

    for (int i = 0; i < 5; i++){
        sum += arr[i];
    }

    cout << "Sum of array elements: " << sum << endl;

    return 0;
}