#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Helper function to serialize a subtree into a string
string serialize(TreeNode *root, vector<string> &serializedSubtrees)
{
    if (!root)
    {
        return "#";
    }

    string currentSubtree = to_string(root->val) + "," +
                            serialize(root->left, serializedSubtrees) + "," +
                            serialize(root->right, serializedSubtrees);

    // Check for duplicate subtree using manual loop
    bool isDuplicate = false;
    for (const string &subtree : serializedSubtrees)
    {
        if (subtree == currentSubtree)
        {
            isDuplicate = true;
            break;
        }
    }

    // Insert the serialized subtree into the vector if it's not a duplicate
    if (!isDuplicate)
    {
        serializedSubtrees.push_back(currentSubtree);
    }

    return currentSubtree;
}

// Function to find the number of unique subtrees in a binary tree
int countUniqueSubtrees(TreeNode *root)
{
    vector<string> serializedSubtrees;
    serialize(root, serializedSubtrees);

    return serializedSubtrees.size();
}

int main()
{
    // Construct a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Find the number of unique subtrees within the binary tree
    int uniqueSubtreeCount = countUniqueSubtrees(root);

    cout << "Number of unique subtrees: " << uniqueSubtreeCount << endl;

    // Clean up memory (In a complete program, you would likely need to free the memory for the tree)
    return 0;
}
