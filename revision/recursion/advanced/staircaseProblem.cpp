#include<iostream>

using namespace std;

int stepsToReachN(int n){
    if(n == 1 || n == 2 || n == 0){
        return n ? n : n + 1;
    }
    return stepsToReachN(n - 3) + stepsToReachN(n - 2) + stepsToReachN(n - 1);
}

int main (){
    int n = 4;

    int steps = stepsToReachN(n);
    cout << steps;
    return 0;
}