#include <iostream>

using namespace std;


int sumOfArr(int arr[], int size){
    if(size == 0){
        return 0;
    }
    return arr[0] + sumOfArr(arr + 1, size - 1);
    
}

int main(){
    int arr[8] = { 0, 1, 3, 4, 5, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = sumOfArr(arr, size);

    cout << result << endl;

    return 0;
}