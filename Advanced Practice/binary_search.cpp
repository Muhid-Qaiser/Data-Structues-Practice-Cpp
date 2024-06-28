#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Function to insert a new node at the beginning of the linked list
void insert(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

Node *getNodeAtIndex(Node *head, int index)
{
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current;
}

// Function to perform binary search on the linked list
Node *binarySearch(Node *head, int key)
{
    Node *low = head;
    Node *high = nullptr;

    // Find the length of the linked list
    int length = 0;
    while (low != nullptr)
    {
        length++;
        high = low;
        low = low->next;
    }

    // Perform binary search
    while (length > 0)
    {
        int mid = length / 2;
        Node *midNode = head;
        // mid = (length % 2 == 0) ? mid - 1 : mid;

        // for (int i = 0; i < mid; i++)
        // {
        //     midNode = midNode->next;
        // }

        midNode = getNodeAtIndex(head, mid);

        if (midNode->data == key)
        {
            return midNode;
        }
        else if (midNode->data < key)
        {
            head = midNode->next;
            length = length - mid - 1;
        }
        else
        {
            head = midNode;
            length = mid;
        }
    }

    return nullptr;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a linked list
    Node *head = nullptr;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    // Print the linked list
    std::cout << "Linked List: ";
    printList(head);

    // Perform binary search on the linked list
    int key = 40;
    Node *result = binarySearch(head, key);

    // Check if the node is found
    if (result != nullptr)
    {
        std::cout << "Node with value " << key << " found!" << std::endl;
    }
    else
    {
        std::cout << "Node with value " << key << " not found!" << std::endl;
    }

    return 0;
}
