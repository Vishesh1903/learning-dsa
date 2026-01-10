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

void print(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    if (temp != head) {
      cout << " -> ";
    }
    cout << temp->data;
    temp = temp->next;
  }
  cout << endl;
}

Node *takeInput2() {
  Node *head = NULL;
  Node *tail = NULL;
  int count = 1;
  bool extend = true;
  while (extend) {
    int data;
    cout << "Enter the data for " << count << " node" << endl;
    cin >> data;
    if (data == -1) {
      extend = false;
      break;
    } else if (head == NULL) {
      Node *n = new Node(data);
      head = n;
      tail = n;
      count++;
    } else {
      Node *n = new Node(data);
      tail = head;
      head = n;
      head->next = tail;
      count++;
    }
  };
  return head;
}

Node *insertAtIthPosition(Node *head, int data, int position) {
  Node *temp = head;
  if (position < 0) {
    return head;
  } else if (position == 0) {
    Node *n = new Node(data);
    n->next = head;
    head = n;
    return head;
  } else {
    int count = 0;
    while (count < position - 1 && temp != NULL) {
      temp = temp->next;
      count++;
    }
    if (temp != NULL && count == position - 1) {
      Node *n = new Node(data);
      n->next = temp->next;
      temp->next = n;
    } else {
      cout << "Invalid position" << endl;
    }
    return head;
  }
}

Node *deleteAtIthPosition(Node *head, int position) {
  Node *temp = head;
  if (position < 0) {
    return head;
  } else if (position == 0) {
    head = head->next;
    delete temp;
    return head;
  } else {
    int count = 0;
    while (count < position - 1) {
      temp = temp->next;
      count++;
    }
    if (temp != NULL && temp->next != NULL) {
      Node *deletedNode = temp->next;
      temp->next = temp->next->next;
      deletedNode->next = NULL;
      delete deletedNode;
    } else {
      cout << "Invalid position" << endl;
    }
    return head;
  }
}
int main() {
//   Node *a = new Node(10);

//   Node *b = new Node(20);

//   Node *c = new Node(30);
//   Node *d = new Node(40);

//   a->next = b;
//   b->next = c;
//   c->next = d;
//   print(a);

  Node *head = takeInput2();
  print(head);
  head = insertAtIthPosition(head, 50, 3);
  print(head);
  head = deleteAtIthPosition(head, 0);
  print(head);
  head && delete head;

  return 0;
}