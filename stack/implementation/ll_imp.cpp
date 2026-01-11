#include <iostream>

using namespace std;

template <typename T>
class Node {
  public:
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};
template <typename S>
class Stack {
  Node<S> *head;
  int length;

public:
  Stack() : head(nullptr), length(0) {}

  void push(int element) {
    Node<S> *node = new Node<S>(element);
    if(head == nullptr){
      head = node;
    } else {
      node->next = head;
      head = node;
    }
    length++;
  }

  void pop() {
    if(head == nullptr){
      cout << "Stack is empty" << endl;
      return;
    }
    Node<S> *temp = head;
    head = head->next;
    delete temp;
    length--;
  }
  int top() {
    if(head == nullptr){
      cout << "Stack is empty" << endl;
      return -1;
    }
    return head->data;
  }

  int size() {
    return length;
  }
  bool isEmpty() { return length == 0; }
  void print() {
    Node<S> *temp = head;
    while(temp != nullptr){
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  Stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.pop();
  cout << s.top() << endl;
  cout << s.size() << endl;
  cout << s.isEmpty() << endl;
  s.print();

  return 0;
}

