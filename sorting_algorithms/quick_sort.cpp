#include <iostream>

using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s;
    int j = e;
    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[e]);
    return i;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivot = partition(arr, s, e);
    quickSort(arr, s, pivot - 1);
    quickSort(arr, pivot + 1, e);
}

int main()
{

    int arr[] = {7, 5, 4, 3, 2, 1, 0};
    int e = (sizeof(arr) / sizeof(arr[0])) -1;
    int s = 0;

    quickSort(arr, s, e);

    for(int i = 0; i <= e; i++){
        cout << arr[i] << " ";
    }

    return 0;
}