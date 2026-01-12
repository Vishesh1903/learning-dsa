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
        return 0;
    }
    bool empty(){
        return front_index == 0;
    }

    T front(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front_index];
    }

    void push(T element){
        if( == capacity){
            cout << "Queue is full" << endl;
            return;
        }
        queue[next_index] = element;
        if(front_index == -1){
            front_index++;
        }
        next_index = (next_index + 1) % capacity;
        q_size++;
    }

    void pop(){
        if(empty()){
            front_index = -1;
            cout << "Queue is empty" << endl;
            return;
        }
        front_index = (front_index + 1) % capacity;
        q_size--;
    }

    void print(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front_index;
        while(i != next_index){
            cout << queue[i] << endl;
            i = (i + 1) % capacity;
        }
    }
};

int main(){
    Queue<int> q(3);

    return 0;
}