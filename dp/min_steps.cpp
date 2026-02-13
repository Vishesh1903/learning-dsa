#include <iostream>

using namespace std;

int minStepstoReach1TopDown(int n, int arr[]){ // moving from highest value towards our goal
    if(n == 1){
        return 0;
    }
    if(n == 2 || n == 3){
        return 1;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int x = minStepstoReach1TopDown(n - 1, arr);
    int y,z;
    y = z = INT_MAX;
    if(n % 3 == 0){
        z = minStepstoReach1TopDown(n/3, arr);
    } 
    if(n % 2 == 0){
        y =  minStepstoReach1TopDown(n/2, arr);
    }
    int ans = 1 + min(x, min(y,z));
    arr[n] = ans;
    return arr[n];
}

int minStepstoReach1BottomUp(int n){
    int* dp = new int[n + 1]();
    dp[0]= 0;
    dp[1]= 0;
    dp[2]= 1;
    dp[3]= 1;

    for(int i = 4; i <=n; i++){
        int x = dp[i - 1];
        int y,z;
        y=z=INT_MAX;
        if(i % 2 == 0){
            y = dp[i / 2];
        }
        if(i % 3 == 0){
            z = dp[i /3];
        }
        dp[i] = 1 + min(min(x, y), z);
    }
    return dp[n];
}


int main(){
    constexpr int n = 10;
    int * arr= new int[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    cout << minStepstoReach1TopDown(n, arr) << endl;
    cout << minStepstoReach1BottomUp(n) << endl;

    return 0;
}