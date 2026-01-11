#include <iostream>

using namespace std;

template <typename T>

class Stack {

  T *data;
  int next_index;
  int capacity;

public:
  Stack() : data(new T[5]), next_index(0), capacity(5) {};
  Stack(int cap) : data(new int[cap]), next_index(0), capacity(cap) {};
  Stack(const Stack &s)
      : data(new T[s.capacity]), next_index(s.next_index),
        capacity(s.capacity) {
    for (int i = 0; i < s.next_index; i++) {
      data[i] = s.data[i];
    }
  }
  Stack &operator=(const Stack &s) {
    if (this == &s) {
      return *this;
    }
    delete[] data;
    data = new T[s.capacity];
    for (int i = 0; i < s.next_index; i++) {
      data[i] = s.data[i];
    }
    next_index = s.next_index;
    capacity = s.capacity;
    return *this;
  }

  void push(int element) {
    if (next_index == capacity) {
      int *new_data = new T[2 * capacity];
      for (int i = 0; i < capacity; i++) {
        new_data[i] = data[i];
      }
      delete[] data;
      data = new_data;
      capacity *= 2;
    }
    data[next_index] = element;
    next_index++;
  }

  void pop() {
    if (next_index == 0) {
      cout << "Stack is empty" << endl;
      return;
    }
    next_index--;
  }
  int top() {
    if (next_index == 0) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return data[next_index - 1];
  }
  int size() { return next_index; }
  bool isEmpty() { return next_index == 0; }
  void print() {
    for (int i = 0; i < next_index; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

  ~Stack() { delete[] data; }
};

int main() {
  Stack<int> s;
  Stack<int> s2(10);
  s2 = s;
  s2.push(10);
  s2.push(20);
  s2.push(30);
  s2.push(40);
  s2.push(50);
  s2.push(60);
  s2.push(70);
  s2.push(80);
  s2.push(90);
  s2.push(100);
  s2.push(110);
  s2.push(120);
  s2.push(130);
  s2.push(140);
  s2.push(150);
  s2.push(160);
  s2.push(170);
  s2.push(180);

  s = s2;
  s.push(100);
  s.push(200);
  s.push(300);
  s.push(400);
  s.push(500);
  s.push(600);
  s.push(700);
  s.push(800);
  s.push(900);
  s.push(1000);

  s.print();
  s2.print();
  s.pop();
  s2.pop();
  return 0;
}