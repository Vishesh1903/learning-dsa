#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

Node *middleOfLinkedList(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    Node *temp = middleOfLinkedList(n1);
    cout << temp->data << endl;

    return 0;
}