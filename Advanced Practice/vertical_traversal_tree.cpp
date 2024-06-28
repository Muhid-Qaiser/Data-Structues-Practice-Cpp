#include <iostream>
#include <queue>

// Structure for a binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to perform vertical traversal of a binary tree
void verticalTraversal(Node *root)
{
    if (!root)
        return;

    // Create an empty queue for level order traversal
    std::queue<Node *> q;
    std::queue<int> hdQueue;

    // Enqueue root
    q.push(root);
    hdQueue.push(0);

    while (!q.empty())
    {
        // Dequeue a node and its horizontal distance
        Node *node = q.front();
        int hd = hdQueue.front();
        q.pop();
        hdQueue.pop();

        // Print the node
        std::cout << node->data << " ";

        // Enqueue left child with updated horizontal distance
        if (node->left)
        {
            q.push(node->left);
            hdQueue.push(hd - 1);
        }

        // Enqueue right child with updated horizontal distance
        if (node->right)
        {
            q.push(node->right);
            hdQueue.push(hd + 1);
        }
    }
}

int main()
{
    // Create a binary tree
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(13);
    root->right->right = createNode(17);

    std::cout << "Vertical Traversal: ";
    verticalTraversal(root);

    return 0;
}
