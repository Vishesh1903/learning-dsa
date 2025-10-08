#include <iostream>

using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) // when i will reach n-1 index it will have nothing to compare 
    {                               //as it is the last index so i will run till n-2 index
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) // finding the minimum value index
            {
                min = j;
            }
        }
        if (arr[i] > arr[min]) // edge case to check if arr[i] < arr[min]
        {                      // this if condition is important 
            swap(arr[i], arr[min]); // as if cond would not be present needless swap will occur
                                    // even if arr[i] < arr[min]
        }
    }
}

int main()
{
    vector<int> arr = {7, 5, 3, 6, 8};
    selectionSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}