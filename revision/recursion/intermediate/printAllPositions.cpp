#include <iostream>

using namespace std;


void printAllPositions(int arr[], int size, int key, int i = 0){
    if(i == size){
        return;
    }
    if(arr[0] == key){
        cout << i << " ";
    }
    printAllPositions(arr + 1, size, key, i + 1);
    
}
void printAllPositions2(int arr[], int size, int key){
    if(size == 0){
        return;
    }
    printAllPositions2(arr, size - 1, key);
    if(arr[size - 1] == key){
        cout << size - 1 << " ";
    }
}

int main(){
    int arr[15] = { 0, 1, 3, 4, 5, 7, 4, 8, 9, 4, 5, 6, 7, 8, 4 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 4;

    printAllPositions(arr, size, key);
    cout << endl;
    printAllPositions2(arr, size, key);


    return 0;
}