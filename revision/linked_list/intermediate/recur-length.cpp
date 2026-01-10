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

int recursiveLength(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    temp = temp -> next;
    return 1 + recursiveLength(temp);
}

bool searchInLL(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }else{
            temp = temp -> next;
        }
    }
    return false;
}

bool recursiveSearchInLL(Node* head, int key){
    if(head == NULL){
        return false;
    }
    if(head -> data == key){
        return true;
    }
    Node* temp = head;
    temp = temp -> next;
    return recursiveSearchInLL(temp, key);
}

int main(){
  Node *a = new Node(10);

  Node *b = new Node(20);

  Node *c = new Node(30);
  Node *d = new Node(40);

  a->next = b;
  b->next = c;
  c->next = d;

  int length = recursiveLength(a);
  int key = 10;
  int key2 = 90;

  cout << "Is " << key << " present" << endl;
  cout << searchInLL(a, key) << endl;
  cout << "Is " << key2 << " present" << endl;
  cout << recursiveSearchInLL(a, key2) << endl;

  cout << "Length is " << length << endl;

  delete a;

  return 0;
}