#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

int search(Node *head, int key, int index = 0)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == key)
    {
        return index;
    }
    return search(head->next, key, index + 1);
};

void searchIter(Node* head, int key){
    Node *temp = head;
    int index = 0;
    int ans = -1;
    while (head != NULL)
    {
        if (head->data == key)
        {
            ans = index;
            break;
        }
        head = head->next;
        index++;
    }
    if (ans == -1)
    {
        cout << "Key not found" << endl;
    }
    else
    {
        cout << "Key found at index: " << ans << endl;
    }
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

    int index = search(n1, 20, 0);
    if (index == -1)
    {
        cout << "Key not found" << endl;
    }
    else
    {
        cout << "Key found at index: " << index << endl;
    }
    searchIter(n1, 9);
    return 0;
}