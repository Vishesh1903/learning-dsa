#include <iostream>

using namespace std;


bool checkIfPresent(int arr[], int size, int key){
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    return checkIfPresent(arr + 1, size - 1, key);
    
}

int main(){
    int arr[8] = { 0, 1, 3, 4, 5, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 1;
    bool result = checkIfPresent(arr, size, key);

    cout << result << endl;

    return 0;
}