#include <iostream>
using namespace std;

// Define the Node structure
struct Node
{
    int data;
    Node *next;
};

void bubbleSort(Node *start)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// write int main to test code
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    printList(head);
    bubbleSort(head);
    printList(head);
    return 0;
}
