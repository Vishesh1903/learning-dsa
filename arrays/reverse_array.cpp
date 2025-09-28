#include <iostream>

using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Reversed array: ";

    int low = 0;
    int high = (sizeof(arr) / sizeof(arr[0])) - 1;

    while(low <= high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    for (auto i = 0; i < sizeof(arr)/ sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}