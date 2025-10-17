#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

Node *mergeTwoLists(Node *l1, Node *l2)
{
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    if (l1->data < l2->data)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

void print(Node* head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{

    Node *n1 = new Node(70);
    // Node *n2 = new Node(40);
    // Node *n3 = new Node(60);

    // n1->next = n2;
    // n2->next = n3;

    Node *n4 = new Node(35);
    Node *n5 = new Node(38);
    Node *n6 = new Node(39);
    n4->next = n5;
    n5->next = n6;

    Node *head = mergeTwoLists(n1, n4);
    print(head);

    return 0;
}