#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

// Helper to create linked list from array
Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Merge two sorted linked lists
Node *merge2LL(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node *head = NULL;
    if (l1->data < l2->data)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }

    Node *tail = head;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1)
    {

        tail->next = l1;
    }
    if (l2)
    {

        tail->next = l2;
    }

    return head;
}
// Merge two sorted linked lists
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    Node* l1 = mergeSort(head);
    Node* l2 = mergeSort(temp);
    return merge2LL(l1, l2);
}

// Helper to print a linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // int arr_unsorted[] = {5, 1, 8, 3, 2, 7};
    int arr_unsorted[] = {6, 5, 4, 3, 2, 1};
    Node *unsortedList = createList(arr_unsorted, 6);

    cout << "Unsorted List: ";
    printList(unsortedList);

    cout << "Sorted List: ";
    printList(mergeSort(unsortedList));

    return 0;
}
