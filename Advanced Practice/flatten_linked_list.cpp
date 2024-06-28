#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *down;

    Node(int val) : data(val), next(nullptr), down(nullptr) {}
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";

        if (head->down)
        {
            Node *downPtr = NULL, *below = head->down;
            cout << "(down: ";
            while (below)
            {
                downPtr = below;
                while (downPtr)
                {
                    cout << downPtr->data << " ";
                    downPtr = downPtr->next;
                }
                below = below->down;
            }
            cout << ") ";
        }

        head = head->next;
    }
    cout << endl;
}

void printList2(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *flatten(Node *node)
{
    Node *temp = NULL, *end = NULL, *head = node;

    while (node)
    {
        if (node->down)
        {
            temp = node->next;

            end = node->down;
            while (end->next)
            {
                end = end->next;
            }

            end->next = temp;
            node->next = node->down;
            node->down = NULL;
        }
        node = node->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->down = new Node(5);
    head->next->down->next = new Node(6);

    head->next->down->down = new Node(7);

    cout << "Original Multi-level Linked List:" << endl;
    printList(head);

    head = flatten(head);

    cout << "Flattened Linked List:" << endl;
    printList2(head);

    return 0;
}