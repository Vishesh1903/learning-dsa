#include <iostream>
#include <queue>

using namespace std;

void reverse(queue<int>& q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

int main(){
    queue<int> q;
    q.push(19);
    q.push(20);
    q.push(21);
    q.push(22);
    q.push(24);
    reverse(q);
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}