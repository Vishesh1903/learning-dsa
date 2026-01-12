#include <iostream>

using namespace std;

template <typename T>
class Queue; 
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T el): data(el), next(nullptr){}
    friend class Queue<T>;
};

template <typename T>
class Queue{
    Node<T>* front_node;
    Node<T>* rear_node;
    int q_size;
    public:
    Queue(): q_size(0), front_node(nullptr), rear_node(nullptr){}
    int size(){
        return q_size;
    }
    int empty(){
        return q_size == 0;
    }
    void push(T el){
        Node<T>* new_node = new Node<T>(el);
        if(!front_node){
            front_node = new_node;
            rear_node = new_node;
        }else{
            rear_node->next = new_node;
            rear_node = new_node;
        }
        q_size++;
    }
    void pop(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        Node<T>* temp = front_node;
        front_node = front_node -> next;
        q_size--;
        delete temp;
    }
    T front(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front_node -> data;
    }
    
};


int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    q.pop();
    cout << q.size() << endl;;
    q.push(3);
    q.push(4);
    cout << q.size() << endl;;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    return 0;
}