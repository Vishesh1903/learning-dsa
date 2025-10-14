#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};
Node *takeInput1()
{
    Node *head = NULL;
    Node *temp = NULL;
    int i = 0;
    while (true)
    {
        int data;
        cout << "Enter the value of " << i << " th Node" << endl;
        cin >> data;
        if (data == -1)
        {
            break;
        }
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            temp = head;
        }
        else
        {

            temp->next = n;
            temp = temp->next;
        }
        // Node n(data); // This will create Node statically, so it will call destructor after the closing of the scope and memory will not be available for us
        i++;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        length++;
    }
}
int findLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void printIthNode(Node *head, int position)
{
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (count == position)
        {
            cout << temp->data << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << -1 << endl;
}

Node *insertAtIthPosition(Node *head, int data, int position)
{
    Node *temp = head;
    int count = 0;
    if (position < 0)
    {
        return head;
    }
    else if (position == 0)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        cout << head->data << endl;
        return head;
    }
    else
    {
        while (temp != NULL && count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
        {
            Node *n = new Node(data);
            n->next = temp->next;
            temp->next = n;
            return head;
        }
        return head;
    }
}

Node *deleteAtIthPosition(Node *head, int position)
{
    Node *temp = head;
    int count = 0;
    if (position < 0)
    {
        return head;
    }
    else if (position == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    else
    {
        while (temp != NULL && count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL && temp->next != NULL)
        {
            Node *deleted_node = temp->next;
            temp->next = temp->next->next;
            delete deleted_node;
            return head;
        }
        return head;
    }
}

int main()
{
    Node *head = takeInput1();
    cout << endl;
    print(head);
    int length = findLength(head);
    cout << "Length: " << length << endl;

    cout << endl;

    // printIthNode(head, 4);
    head = insertAtIthPosition(head, 78, 0);
    print(head);
    cout << endl;
    head = deleteAtIthPosition(head, 0);
    print(head);
    return 0;
}