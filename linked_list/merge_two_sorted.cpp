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
Node *m2LL(Node *l1, Node *l2)
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
        tail->next = l1;
    if (l2)
        tail->next = l2;

    return head;
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
    // ---------- Test Case 1 ----------
    int arr1_1[] = {1, 3, 5, 7};
    int arr1_2[] = {2, 4, 6, 8};
    Node *list1A = createList(arr1_1, 4);
    Node *list1B = createList(arr1_2, 4);

    // ---------- Test Case 2 ----------
    int arr2_1[] = {1, 2, 3};
    int arr2_2[] = {4, 5, 6, 7, 8};
    Node *list2A = createList(arr2_1, 3);
    Node *list2B = createList(arr2_2, 5);

    // ---------- Test Case 3 ----------
    int arr3_1[] = {1, 3, 5, 7};
    int arr3_2[] = {1, 3, 4, 5};
    Node *list3A = createList(arr3_1, 4);
    Node *list3B = createList(arr3_2, 4);

    // ---------- Test Case 4 ----------
    int arr4_1[] = {-10, -3, 0, 5};
    int arr4_2[] = {-5, -2, 2, 10};
    Node *list4A = createList(arr4_1, 4);
    Node *list4B = createList(arr4_2, 4);

    // ---------- Test Case 5 ----------
    int arr5_2[] = {1, 2, 3};
    Node *list5A = NULL;
    Node *list5B = createList(arr5_2, 3);

    // ---------- Run & Print Merged Results ----------
    cout << "===== Test Case 1 =====\n";
    cout << "List 1: ";
    printList(list1A);
    cout << "List 2: ";
    printList(list1B);
    cout << "Merged: ";
    printList(m2LL(list1A, list1B));
    cout << endl;

    cout << "===== Test Case 2 =====\n";
    cout << "List 1: ";
    printList(list2A);
    cout << "List 2: ";
    printList(list2B);
    cout << "Merged: ";
    printList(m2LL(list2A, list2B));
    cout << endl;

    cout << "===== Test Case 3 =====\n";
    cout << "List 1: ";
    printList(list3A);
    cout << "List 2: ";
    printList(list3B);
    cout << "Merged: ";
    printList(m2LL(list3A, list3B));
    cout << endl;

    cout << "===== Test Case 4 =====\n";
    cout << "List 1: ";
    printList(list4A);
    cout << "List 2: ";
    printList(list4B);
    cout << "Merged: ";
    printList(m2LL(list4A, list4B));
    cout << endl;

    cout << "===== Test Case 5 =====\n";
    cout << "List 1: ";
    printList(list5A);
    cout << "List 2: ";
    printList(list5B);
    cout << "Merged: ";
    printList(m2LL(list5A, list5B));
    cout << endl;

    return 0;
}
