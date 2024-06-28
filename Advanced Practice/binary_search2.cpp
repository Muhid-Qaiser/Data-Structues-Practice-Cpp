#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to find the length of the linked list
int getLinkedListLength(Node *head)
{
    int length = 0;
    Node *current = head;
    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

// Function to find the node at a given index in the linked list
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
Node *binarySearchLinkedList(Node *head, int target)
{
    int length = getLinkedListLength(head);
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        // int mid = left + (right - left) / 2;
        int mid = (right + left) / 2;

        Node *midNode = getNodeAtIndex(head, mid);
        if (midNode->data == target)
        {
            return midNode;
        }
        else if (midNode->data < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return nullptr; // Node not found
}

int main()
{
    // Create a sample linked list
    Node *head = new Node{1, nullptr};
    Node *second = new Node{2, nullptr};
    Node *third = new Node{3, nullptr};
    Node *fourth = new Node{4, nullptr};
    Node *fifth = new Node{5, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Perform binary search on the linked list
    int target = 4;
    Node *node = binarySearchLinkedList(head, target);

    if (node != nullptr)
    {
        std::cout << "Node found with data: " << node->data << std::endl;
    }
    else
    {
        std::cout << "Node not found" << std::endl;
    }

    // Clean up the memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
