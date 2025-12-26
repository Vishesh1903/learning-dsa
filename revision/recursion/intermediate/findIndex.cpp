#include <iostream>

using namespace std;


int findFirstIndex(int arr[], int size, int key, int i = 0){
    if(i == size){
        return -1;
    }
    if(arr[0] == key){
        return i;
    }
    return findFirstIndex(arr + 1, size, key, i + 1);
    
}
int findFirstIndex2(int arr[], int size, int key){
    if(size == 0){
        return -1;
    }
    if(arr[size - 1] == key){
        int index = findFirstIndex2(arr, size - 1, key);
        if(index == - 1){
            return size - 1;
        }else {
            return index;
        }
    }
    return findFirstIndex2(arr, size - 1, key);
    
}
int findLastIndex(int arr[], int size, int key){
    if(size == 0){
        return -1;
    }
    if(arr[size - 1] == key){
        return size - 1;
    }
    return findLastIndex(arr, size - 1, key);
    
}
int findLastIndex2(int arr[], int size, int key, int i = 0){
    if(i == size){
        return -1;
    }
    if(arr[i] == key){
        int index = findLastIndex2(arr, size, key, i + 1);
        if(index == - 1){
            return i;
        }else {
            return index;
        }
    }
    return findLastIndex2(arr, size, key, i + 1);
    
}

int main(){
    int arr[15] = { 0, 1, 3, 4, 5, 7, 4, 8, 9, 4, 5, 6, 7, 8, 4 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 4;

    cout << "First Index of " << key << " is " << findFirstIndex(arr, size, key) << endl;
    cout << "First Index of " << key << " is " << findFirstIndex2(arr, size, key) << endl;
    cout << "Last Index of " << key << " is " << findLastIndex(arr, size, key) << endl;
    cout << "Last Index of " << key << " is " << findLastIndex2(arr, size, key) << endl;


    return 0;
}