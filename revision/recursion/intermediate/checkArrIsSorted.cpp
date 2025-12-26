#include <iostream>

using namespace std;


bool checkArrIsSorted(int arr[], int size, int i = 1){
    if(size == 0 || size == 1){
        return true;
    }
    if(i == size){
        return true;
    }
    if(arr[i - 1] > arr[i]){
        return false;
    }
    return checkArrIsSorted(arr, size, i+1);
    
}

bool checkArrIsSorted2(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[size - 1] < arr[size - 2]){
        return false;
    }
    return checkArrIsSorted2(arr, size - 1);
    
}
bool checkArrIsSorted3(int arr[], int size, int i = 0){
    if(size == 0 || size == 1 || i == size - 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return checkArrIsSorted3(arr+1, size, i + 1);
    
}
bool checkArrIsSorted4(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return checkArrIsSorted2(arr+1, size - 1);
    
}

int main(){
    int arr[8] = {0,1,3,4,4,5,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    bool result = checkArrIsSorted3(arr, size);

    if(result){
        cout << "Array is sorted!" << endl;
    }else{
       cout << "Array is not sorted!" << endl; 
    }
    return 0;
}