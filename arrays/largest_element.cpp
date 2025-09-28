#include <iostream>
using namespace std;

int main(){
    int largest = INT_MIN;

    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5;i++){
        if(arr[i] > largest){
            largest = i;
        }
    }

    cout<< "Largest element in the array whose index is " << largest << " is: " << arr[largest] << endl;

    return 0;
}