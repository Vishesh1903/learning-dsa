#include <iostream>
using namespace std;

int largestElement(int arr[], int size) {
  int largest = INT_MIN;

  for (int i = 0; i < size; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

int smallestElement(int arr[], int size) {

  int smallest = INT_MAX;

  for (int i = 0; i < size; i++) {
    if (arr[i] < smallest) {
      smallest = arr[i];
    }
  }
  return smallest;
}

int main() {
  // int arr[5] = {1, 2, 3, 4, 5};
  // int size = sizeof(arr) / sizeof(arr[0]);

  int size;
  cout << "Enter the size of the array: " << endl;
  cin >> size;

  int *arr = new int[size]();

  for (int i = 0; i < size; i++) {
    cout << "Enter the element at index " << i << ": " << endl;
    cin >> arr[i];
  }

  int largest = largestElement(arr, size);
  int smallest = smallestElement(arr, size);

  cout << "Largest element in the array: " << largest << endl;
  cout << "Smallest element in the array: " << smallest << endl;

  return 0;
}