#include <iostream>

using namespace std;

bool checkIfKeyExists(int arr[], int n, int key){
    if(n == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    return checkIfKeyExists(arr + 1, n - 1, key);
}
bool checkIfKeyExistsV2(int arr[], int n, int key){
    if(n == 0){
        return false;
    }
    if(arr[n-1] == key){
        return true;
    }
    return checkIfKeyExists(arr, n - 1, key);
}

int main(){
    int arr[] = {12, 3, 4, 5, 56, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the key you want to search: " << endl;
    cin >> key;

    bool is_key_present = checkIfKeyExistsV2(arr, size, key);
    if(is_key_present){
        cout << "Key is present" << endl;
    }else{
        cout << "Key is not present" << endl;
    }

    return 0;
}