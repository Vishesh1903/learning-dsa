#include <iostream>
#include <utility>

using namespace std;

void selectionSort(int arr[], int size){
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

void bubbleSort(int arr[], int size){
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
void insertionSort(int arr[], int size){
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
void mergeArr(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];
    while(i <= mid && j <=high){
      if (arr[k] <= arr[j]) {
        arr[k] = arr[j]; 
        i++;
        k++;
      } else if (arr[i] >= arr[j]) {
        arr[k] = arr[j];
        k++;
        j++;
      }
    }
    if (i <= low) {
      while (i <= low) {
        arr[k] = arr[i];
        i++;
        k++;
      }
    }
    if (j <= high) {
      while (j <= high) {
        arr[k] = arr[j];
        j++;
        k++;
      }
    }
    for (int z = 0; z < k; z++) {
      arr[z] = temp[z];
    }
}
void mergeArrInplace(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    while(i <= mid && j <= high){
      if (arr[i] <= arr[j]) {
        i++;
      } else {
        int temp = arr[j];
        int index = j;
        while (index != i) {
          arr[index] = arr[index - 1];
          index--;
        }
        arr[i] = temp;
        i++;
        mid++;
        j++;
      }
    }
}

void mergeSort(int arr[], int low, int high){
  if(low >= high){
    return;
  }
  int mid = low + (high - low)/2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  mergeArrInplace(arr, low, mid, high);
}

int findPartition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low;
  int j = high;

  while (i < j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] >= pivot) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

void quickSort(int arr[], int low, int high) {
  if (low >= high) {
    return;
  }
  int p = findPartition(arr, low, high);
  quickSort(arr, low, p - 1 );
  quickSort(arr, p + 1, high);

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
    case 4:
      mergeSort(arr, 0, size - 1);
      break;
    case 5:
      quickSort(arr, 0, size - 1);
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
  cout
      << "Enter sorting method (selection(1)/bubble(2)/insertion(3)/merge(4)/quick(5)): ";
  cin >> method;
  sortMethods(arr, n, method);
  cout << "Sorted array: ";
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}