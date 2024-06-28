#include <iostream>

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

// Function to check if two trees are identical
bool areIdentical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

// Function to check if a tree is unique
bool isUnique(Node *root, Node *node)
{
    if (root == nullptr)
        return false;
    if (areIdentical(root, node))
        return true;
    return isUnique(root->left, node) || isUnique(root->right, node);
}

// Function to count the number of unique subtrees
int countUniqueSubtrees(Node *root)
{
    if (root == nullptr)
        return 0;
    int count = 0;
    if (!isUnique(root->left, root))
        count++;
    if (!isUnique(root->right, root))
        count++;
    return count + countUniqueSubtrees(root->left) + countUniqueSubtrees(root->right);
}

int main()
{
    // Create the binary tree
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(2);
    // root->right->right = createNode(4);

    // Count the number of unique subtrees
    int uniqueSubtrees = countUniqueSubtrees(root);
    std::cout << "Number of unique subtrees: " << uniqueSubtrees << std::endl;

    return 0;
}
