#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sortKSortedArray(vector<int>& v, int k){
    priority_queue<int> q;
    int n = v.size();
    int start = 0;
    int i = k;

    for(int i = 0; i < k; i++){
        q.push(v[i]);
    }
    while(i < n){
        int top = q.top();
        q.pop();
        v[start] = top;
        q.push(v[i]);
        i++;
        start++;
    }
    while(!q.empty()){
        v[start] = q.top();
        q.pop();
        start++;
    }
}

int main(){

    vector<int> v = {12, 15, 7, 4, 9};
    int k = 2;
    sortKSortedArray(v, k);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    return 0;
}