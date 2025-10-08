#include <iostream>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if(!flag){
            cout << "Array is already sorted!";
            break;
        }
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    bubbleSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}