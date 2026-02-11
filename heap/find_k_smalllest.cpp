#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> findKSmallest(vector<int>& v, int k){
    priority_queue<int> q;
    int n = v.size();
    int start = 0;
    int i = k;
    vector<int> ans;
    for(int i = 0; i < k; i++){
        q.push(v[i]);
    }
    while(i < n){
        int top = q.top();
        if(q.top() > v[i]){
            q.pop();
            q.push(v[i]);
        }
        i++;
    }
    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}

//Alternate Solution
vector<int>& findKSmallest2(vector<int>& v, int k){
    priority_queue<int> q;
    int n = v.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        q.push(v[i]);
        if(q.size() > k){
            q.pop();
        }
    }

    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}

int main(){

    vector<int> v = {12, 15, 7, 4, 9};
    int k = 2;
    vector<int>& ans = findKSmallest2(v, k);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}