#include <iostream>

using namespace std;

bool isArraySorted(int arr[], int n){
    if(n == 1 || n == 0){
        return true;
    }
    if(arr[n-1] > arr[n-2]){
        return isArraySorted(arr, n-1);
    }else{
        return false;
    }
}

bool isArraySortedV2(int arr[], int n){
    if(n == 1 || n == 0){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }else{
        return isArraySortedV2(arr + 1, n - 1);
    }
}

int main(){

    int arr[5] = {1,3,4,5,7};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool is_array_sorted = isArraySorted(arr, 5);

    if(is_array_sorted){
        cout << "Array is sorted" << endl;
    }else{
        cout << "Array is not sorted" << endl;
    }


    return 0;
}