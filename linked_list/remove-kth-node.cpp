#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int x): data(x), next(NULL){}
};

Node* removeKthNode(Node*head, int position){
    Node *slow = head;
    Node *fast = head;
    Node *temp = NULL;
    while (position--)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        temp = slow->next;
        delete slow;
        return temp;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

void print(Node* head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(10);
    Node* n3 = new Node(15);

    n1->next = n2;
    n2->next = n3;

    Node *head = removeKthNode(n1, 3);
    print(head);

    return 0;
}