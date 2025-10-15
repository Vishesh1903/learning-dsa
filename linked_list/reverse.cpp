#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

Node* reverse(Node* head){
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;

    while(curr!= NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(Node* head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *n1 = new Node(5);
    Node *n2 = new Node(10);
    Node *n3 = new Node(15);
    Node *n4 = new Node(20);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    print(n1);
    Node* temp = reverse(n1);
    print(temp);

    return 0;
}