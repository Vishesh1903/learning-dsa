#include <iostream>

using namespace std;

int countOccurrences(int arr[], int n, int key)
{
    if(n == 0){
        return 0;
    }
    if (arr[0] == key)
    {
        return 1 + countOccurrences(arr + 1, n - 1, key);
    }
    else
    {
        return countOccurrences(arr + 1, n - 1, key);
    }
}

int countOccurrencesV2(int arr[], int n, int key, int index = 0)
{
    if(index == n){
        return 0;
    }
    if(arr[index] == key){
        return 1 + countOccurrencesV2(arr, n, key, index + 1);
    }else{
        return countOccurrencesV2(arr, n, key, index + 1);
    }
}

int countOccurrencesV3(int arr[], int n , int key){
    if(n == 0){
        return 0;
    }
    if(arr[n - 1] == key){
        return 1 + countOccurrencesV3(arr, n - 1, key);
    }else{
        return countOccurrencesV3(arr, n - 1, key);   
    }
}

int main()
{

    int arr[] = {5, 6, 5, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key you want to count occurrences for: " << endl;
    cin >> key;
    int occurrences = countOccurrencesV3(arr, size, key);

    cout << "Occurrences of " << key << " in the array: " << occurrences << endl;
    return 0;
}