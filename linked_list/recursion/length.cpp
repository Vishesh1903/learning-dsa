#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int x): data(x), next(NULL){}
};

int findLength(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1 + findLength(head->next);
}

int main(){

    Node *n1 = new Node(5);
    Node *n2 = new Node(10);
    Node *n3 = new Node(15);
    Node *n4 = new Node(20);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    int length = findLength(n1);

    cout << "Length of Linked list is: " << length << endl;
    return 0;
}