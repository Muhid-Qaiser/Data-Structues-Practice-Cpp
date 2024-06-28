#include <iostream>
using namespace std;

struct TreeNode
{
    char value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

bool areIsomorphic(TreeNode *root1, TreeNode *root2)
{
    // Base case: If both nodes are NULL, they are isomorphic.
    if (!root1 && !root2)
    {
        return true;
    }

    // If one node is NULL and the other is not, they are not isomorphic.
    if (!root1 || !root2)
    {
        return false;
    }

    // Check if the current nodes have the same value.
    if (root1->value != root2->value)
    {
        return false;
    }

    // Case 1: Check if children are isomorphic without swapping.
    bool isCase1 = areIsomorphic(root1->left, root2->left) && areIsomorphic(root1->right, root2->right);

    // Case 2: Check if children are isomorphic with swapped left and right children.
    bool isCase2 = areIsomorphic(root1->left, root2->right) && areIsomorphic(root1->right, root2->left);

    // Return true if any of the cases is true.
    return isCase1 || isCase2;
}

// implement a function to print the tree
void printTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    std::cout << root->value << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    // Create tree nodes and build the trees.
    TreeNode *root1 = new TreeNode('A');
    root1->left = new TreeNode('B');
    root1->right = new TreeNode('C');
    root1->left->left = new TreeNode('D');
    root1->left->right = new TreeNode('E');
    root1->right->left = new TreeNode('F');
    root1->right->right = new TreeNode('G');

    TreeNode *root2 = new TreeNode('A');
    root2->left = new TreeNode('C');
    root2->right = new TreeNode('B');
    root2->left->left = new TreeNode('G');
    root2->left->right = new TreeNode('F');
    root2->right->left = new TreeNode('E');
    root2->right->right = new TreeNode('D');

    bool result = areIsomorphic(root1, root2);

    if (result)
    {
        std::cout << "The trees are isomorphic." << std::endl;
    }
    else
    {
        std::cout << "The trees are not isomorphic." << std::endl;
    }

    // Clean up memory (assuming you're done with the trees).
    // TODO: Implement a function to delete the tree nodes and free memory.
    delete root1;
    delete root2;

    return 0;
}
