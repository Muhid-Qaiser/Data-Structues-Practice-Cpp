#include <iostream>

struct Node
{
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

// Function to insert a node at a given index in a singly linked list.
Node *InsertNode(Node *head, int val, int index)
{
    if (index < 0)
    {
        // Negative index, do nothing.
        return head;
    }

    if (index == 0)
    {
        // Insert at the beginning of the list.
        Node *newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    if (head == nullptr)
    {
        // Empty list, and index is not zero, do nothing.
        return head;
    }

    // Recursively call InsertNode for the rest of the list.
    head->next = InsertNode(head->next, val, index - 1);
    return head;
}

// Function to print the linked list.
void PrintList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{
    Node *head = nullptr;

    // Insert some nodes at different indexes.
    head = InsertNode(head, 10, 0);  // Insert 10 at index 0
    head = InsertNode(head, 20, 1);  // Insert 20 at index 1
    head = InsertNode(head, 30, 0);  // Insert 30 at index 0
    head = InsertNode(head, 40, 2);  // Insert 40 at index 2
    head = InsertNode(head, 50, -1); // Insert 50 at an invalid negative index

    // Print the linked list.
    PrintList(head);

    return 0;
}
