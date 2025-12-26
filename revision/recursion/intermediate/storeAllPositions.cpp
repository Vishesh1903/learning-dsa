#include <iostream>

using namespace std;

int storeAllPositions(int arr[], int size, int key, int ans[],int i = 0, int j = 0){
    if(i == size){
        return 0;
    }
    if(arr[0] == key){
        ans[j] = i;
        return 1 + storeAllPositions(arr + 1, size, key, ans, i + 1, j + 1);
    }
    return storeAllPositions(arr + 1, size, key, ans, i + 1, j);
    
}
int storeAllPositions2(int arr[], int size, int key, int ans[], int& j){
    if(size == 0){
        return 0;
    }
    int count = storeAllPositions2(arr, size - 1, key, ans, j);
    if(arr[size - 1] == key){
        ans[j++] = size - 1;
        return 1 + count;
    }
    return count;
}

int main(){
    int arr[15] = { 0, 1, 3, 4, 5, 7, 4, 8, 9, 4, 5, 6, 7, 8, 4 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int ans[15];
    int count = storeAllPositions(arr, size, key, ans);
    for(int i = 0;i < count;i++){
        cout << ans[i] << " "; 
    }
    cout << endl;
    int j = 0;
    int count2 = storeAllPositions2(arr, size, key, ans, j);
    for(int i = 0;i < count;i++){
        cout << ans[i] << " "; 
    }
    return 0;
}