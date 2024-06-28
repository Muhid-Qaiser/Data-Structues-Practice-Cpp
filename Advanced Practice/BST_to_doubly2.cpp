#include <iostream>
using namespace std;

// Structure for a node in the BST
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to convert BST to a doubly linked list
void convertBSTToDoublyLinkedList(Node *root, Node **head, Node **prev)
{
    if (root == nullptr)
    {
        return;
    }

    // Recursively convert left subtree
    convertBSTToDoublyLinkedList(root->left, head, prev);

    // Convert current node
    if (*prev == nullptr)
    {
        // If previous node is null, it means this is the first node (head)
        *head = root;
    }
    else
    {
        // Otherwise, update the right pointer of the previous node
        (*prev)->right = root;
        root->left = *prev;
    }

    // Update the previous node
    *prev = root;

    // Recursively convert right subtree
    convertBSTToDoublyLinkedList(root->right, head, prev);
}

// Function to convert BST to a doubly linked list
Node *convertBSTToDoublyLinkedList(Node *root)
{
    Node *head = nullptr; // Head of the doubly linked list
    Node *prev = nullptr; // Previous node

    convertBSTToDoublyLinkedList(root, &head, &prev);

    return head;
}

// Main function with test cases
int main()
{
    // Create a sample BST
    Node *root = new Node();
    root->data = 4;
    root->left = new Node();
    root->left->data = 2;
    root->left->left = new Node();
    root->left->left->data = 1;
    root->left->right = new Node();
    root->left->right->data = 3;
    root->right = new Node();
    root->right->data = 5;

    // Convert BST to doubly linked list
    Node *head = convertBSTToDoublyLinkedList(root);

    // Print the doubly linked list
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->right;
    }

    return 0;
}
