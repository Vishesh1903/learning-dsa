#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

int main()
{
    Node a(200);
    Node b(400);
    Node c(500);

    a.next = &b;
    b.next = &c;
    Node *head = &a;
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}