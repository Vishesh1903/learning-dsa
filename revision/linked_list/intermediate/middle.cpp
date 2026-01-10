#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next;
  
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
  
    ~Node() {
      cout << "Node destroyed" << endl;
      delete next;
    }
};

Node* middleOfLL(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main(){

  Node *a = new Node(10);

  Node *b = new Node(20);

  Node *c = new Node(30);
  Node *d = new Node(40);
//   Node *e = new Node(50);

  a->next = b;
  b->next = c;
  c->next = d;
//   d->next = e;
  Node* middle = middleOfLL(a);
  cout << middle -> data << endl;

    return 0;
}