#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Structure to store information about a subtree
struct SubtreeInfo
{
    bool isBST;
    int size;
    int minValue;
    int maxValue;

    SubtreeInfo(bool isBST, int size, int minValue, int maxValue)
        : isBST(isBST), size(size), minValue(minValue), maxValue(maxValue) {}
};

SubtreeInfo findLargestBST(TreeNode *root, int &maxSize, TreeNode *&largestBSTRoot)
{
    if (!root)
    {
        return {true, 0, INT_MAX, INT_MIN};
    }

    // Recursively find information about left and right subtrees
    SubtreeInfo leftInfo = findLargestBST(root->left, maxSize, largestBSTRoot);
    SubtreeInfo rightInfo = findLargestBST(root->right, maxSize, largestBSTRoot);

    // Check if the current subtree is a BST
    if (leftInfo.isBST && rightInfo.isBST &&
        root->val > leftInfo.maxValue && root->val < rightInfo.minValue)
    {
        int totalSize = leftInfo.size + rightInfo.size + 1;

        // Update information if the current subtree is the largest BST found so far
        if (totalSize > maxSize)
        {
            maxSize = totalSize;
            largestBSTRoot = root;
        }

        return {true, totalSize, min(root->val, leftInfo.minValue), max(root->val, rightInfo.maxValue)};
    }
    else
    {
        // If the current subtree is not a BST, return invalid information
        return {false, 0, 0, 0};
    }
}

TreeNode *findLargestBST(TreeNode *root)
{
    int maxSize = 0;
    TreeNode *largestBSTRoot = nullptr;

    findLargestBST(root, maxSize, largestBSTRoot);

    return largestBSTRoot;
}

// Helper function to print the in-order traversal of a tree
void inOrderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main()
{
    // Construct a sample binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    // Find the largest BST within the binary tree
    TreeNode *largestBST = findLargestBST(root);

    // Print the in-order traversal of the largest BST
    cout << "In-order traversal of the largest BST: ";
    inOrderTraversal(largestBST);
    cout << endl;

    // Clean up memory (In a complete program, you would likely need to free the memory for the tree)
    return 0;
}
