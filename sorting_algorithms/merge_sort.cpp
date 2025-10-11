#include <iostream>

using namespace std;
void merge(int arr[], int s, int e, int mid){
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i <= mid && j <=e){
        if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
            k++;
        }else if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
            temp[k] = arr[i];
            i++;
            k++;
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i = s; i <= e; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + ((e - s) / 2);
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 2, 1, 4, 6};
    int s = 0;
    int e = (sizeof(arr) / sizeof(arr[0])) - 1;
    mergeSort(arr, s, e);
    for(int i = 0; i <= e; i++){
        cout << arr[i] << " ";
    }
    return 0;
}