#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to merge two sorted doubly linked lists
Node *merge(Node *left, Node *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Node *result = nullptr;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
        result->next->prev = result;
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
        result->next->prev = result;
    }

    return result;
}

// Function to find the point where the list starts decreasing
Node *findDecreasingPoint(Node *head)
{
    while (head && head->next && head->data < head->next->data)
    {
        head = head->next;
    }
    return head;
}

// Function to reverse a doubly linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *nextNode = nullptr;

    while (current)
    {
        nextNode = current->next;
        current->next = prev;
        current->prev = nextNode;
        prev = current;
        current = nextNode;
    }

    return prev;
}

// Function to sort a biotonic doubly linked list
Node *sortBiotonicList(Node *head)
{
    if (!head || !head->next)
        return head;

    // Find the point where the list starts decreasing
    Node *decreasingPoint = findDecreasingPoint(head);

    if (!decreasingPoint)
    {
        // If the list is strictly increasing, it's already sorted
        return head;
    }

    // Split the list into two parts
    Node *left = head;
    Node *right = decreasingPoint->next;
    decreasingPoint->next = nullptr;

    // Reverse the second part
    right = reverse(right);

    // Merge the two sorted parts
    return merge(left, right);
}

// Function to print a doubly linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(5);
    head->next->prev = head;
    head->next->next = new Node(7);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(12);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;

    cout << "Original Biotonic Doubly Linked List:" << endl;
    printList(head);

    head = sortBiotonicList(head);

    cout << "Sorted Biotonic Doubly Linked List:" << endl;
    printList(head);

    return 0;
}
