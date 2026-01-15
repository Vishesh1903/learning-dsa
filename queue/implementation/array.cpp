#include <iostream>

using namespace std;

template <typename T>
class Queue{
    int front_index;
    int capacity;
    int next_index;
    T* queue;

    public:
    Queue(): front_index(-1), next_index(0), capacity(5), queue(new T[5]){}
    Queue(int capacity): front_index(-1), next_index(0), capacity(capacity), queue(new T[capacity]){};
    int size(){
       if(front_index == -1) return 0;
        return (next_index - front_index + capacity) % capacity;
    }
    bool empty(){
        return front_index == -1;
    }

    T front(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front_index];
    }

    void push(T element){
        if(size() == capacity){
        cout << "Queue is full" << endl;
        return;
    }
        if(front_index == -1){
            front_index = 0;
        }
        queue[next_index] = element;
        next_index = (next_index + 1) % capacity;
    }

    void pop(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return;
        }
        front_index = (front_index + 1) % capacity;
        if(front_index == next_index){
            front_index =  -1;
            next_index = 0;
        }
    }

    void print(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return;
        }
        int temp = front_index;
        do{
            cout << queue[temp] << " ";
            temp = (temp + 1)%capacity;
        }while(temp != next_index);
        cout << endl;
    }
};

int main(){
    Queue<int> q(4);
    q.push(5);
    q.print();
    q.push(1);
    q.print();
    q.push(2);
    q.print();
    q.push(6);
    q.print();
    q.push(67);
    q.print();
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.front() << endl;
    cout << q.front() << endl;

    return 0;
}