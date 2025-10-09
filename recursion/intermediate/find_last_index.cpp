#include <iostream>

using namespace std;

int findLastIndex(int arr[], int n, int key, int index){
    if(index < 0){
        return -1;
    }
    if(arr[index] == key){
        return index;
    }else{
        return findLastIndex(arr, n, key, index - 1);
    }
}

int findLastIndexV2(int arr[], int n, int key, int index){
    if(index == n){
        return -1;
    }
    if(arr[index] == key){
       int last_index = findLastIndexV2(arr, n, key, index + 1);
       if(last_index == -1){
        return index;
       }else{
        return last_index;
       }
    }
    else{
        return findLastIndexV2(arr, n, key, index + 1);
    }
}

int main(){
    int arr[] = {1, 2, 2, 4, 5, 5, 5, 6, 5, 2, 82};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the key you want to search: " << endl;
    cin >> key;

    int index = findLastIndexV2(arr, size, key, 0);
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