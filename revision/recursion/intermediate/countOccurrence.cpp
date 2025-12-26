#include <iostream>

using namespace std;


int countOccurrence(int arr[], int size, int key, int i = 0){
    if(i == size){
        return 0;
    }
    if(arr[0] == key){
        return 1 + countOccurrence(arr + 1, size, key, i + 1);
    }
    return countOccurrence(arr + 1, size, key, i + 1);
    
}
int countOccurrence2(int arr[], int size, int key){
    if(size == 0){
        return 0;
    }
    if(arr[size - 1] == key){
        return 1 + countOccurrence2(arr, size - 1, key);
    }
    return countOccurrence2(arr, size - 1, key);
}

int main(){
    int arr[15] = { 0, 1, 3, 4, 5, 7, 4, 8, 9, 4, 5, 6, 7, 8, 4 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 4;

    cout << countOccurrence(arr, size, key);
    cout << endl;
    cout << countOccurrence2(arr, size, key);


    return 0;
}