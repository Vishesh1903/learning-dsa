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
Node *takeInput2()
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

            temp = n;
            temp->next = head;
            head = temp;
        }
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
        cout << temp->data << endl;
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

int main()
{
    Node *head = takeInput2();
    print(head);
    int length = findLength(head);
    cout << "Length: " << length << endl;
    return 0;
}