#include <iostream>


using namespace std;

void reverse(char arr[], int size){
    int low = 0;
    int high = size - 2; // -2 to ignore null character
    while (low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

int main(){
    int size;
    cin >> size;
    cin.ignore(); // to ignore the newline character after size input otherwise getline will not work
    char arr[size];

    cout << "Size of char array: " << sizeof(arr) << " bytes" << endl;
    cin.getline(arr, size);
    cout <<"Size of char array after input: " << sizeof(arr) << " bytes" << endl;
    reverse(arr, size);
    cout <<arr<<endl;
    return 0;
}