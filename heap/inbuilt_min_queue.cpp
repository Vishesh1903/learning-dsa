#include<iostream>
#include<queue>

int main(){
    priority_queue<int> pq; //normal max queue declaration
    priority_queue<int, vector<int>, greater<int>> q; // min queue declaration

    pq.push(100);
    pq.push(10);
    pq.push(15);
    pq.push(1700);
    pq.push(20);
    pq.push(1);

    cout << "Size: " << pq.size() << endl; // size to get size
    cout << "Top Element: " << pq.top() << endl; // to get the top element

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.top();
    }
}