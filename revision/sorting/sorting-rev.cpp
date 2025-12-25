#include <iostream>
#include <string>

using namespace std;

void selectionSort(int* arr, int size){
  for(int i = 0;i < size - 1; i++){
    int min = i;
    for (int j = i + 1; j < size; j++){
      if (arr[j] < arr[min]){
        min = j;
      }
    }
    if(arr[min] < arr[i]){
      swap(arr[i], arr[min]);
    }
  }
}

void bubbleSort(int* arr, int size){
  for(int i = 0; i < size - 1; i++){
    int flag = 0;
    for(int j = 0; j < size - i - 1; j++){
      if(arr[j] > arr[j + 1]){
        swap(arr[j], arr[j + 1]);
        flag = 1;
      }
    }
    if(flag == 0){
      cout << "Array sorted in " << i + 1 << (i == 0 ? " pass." : " passes.") << endl;
      break;
    }
  }
}
void insertionSort(int* arr, int size){
  for(int i = 1; i < size; i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void sortMethods(int* arr, int size, int method) {
  switch(method){
    case 1:
      selectionSort(arr, size);
      break;
    case 2:
      bubbleSort(arr, size);
      break;
    case 3:
      insertionSort(arr, size);
      break;
    default:
      cout << "Invalid sorting method" << endl; 
      break;
  }

}

int main() {
  int n;
  cout << "Enter number of elements: " << endl;
  cin >> n;
  int* arr = new int[n];
  cout << "Enter elements: " << endl;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int method;
  cout << "Enter sorting method (selection(1)/bubble(2)/insertion(3)): ";
  cin >> method;
  sortMethods(arr, n, method);
  cout << "Sorted array: ";
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}