#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *SortedMerge(Node *a, Node *b);
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef);

void MergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// write the int main() function to check the code
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
    MergeSort(&head);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}