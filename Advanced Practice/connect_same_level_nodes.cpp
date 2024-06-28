#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next; // Pointer to the next node on the same level

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectNodesAtSameLevel(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    queue<TreeNode *> levelQueue;
    levelQueue.push(root);

    while (!levelQueue.empty())
    {
        int levelSize = levelQueue.size();

        // Connect nodes at the same level
        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = levelQueue.front();
            levelQueue.pop();

            if (i < levelSize - 1)
            {
                node->next = levelQueue.front();
            }

            if (node->left)
            {
                levelQueue.push(node->left);
            }
            if (node->right)
            {
                levelQueue.push(node->right);
            }
        }
    }
}

// Helper function to print connected nodes at the same level
void printConnectedNodes(TreeNode *root)
{
    while (root)
    {
        TreeNode *current = root;
        while (current)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
        root = root->left; // Move to the next level
    }
}

int main()
{
    // Construct a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    // Connect nodes at the same level
    connectNodesAtSameLevel(root);

    // Print connected nodes at the same level
    cout << "Connected Nodes at the Same Level:" << endl;
    printConnectedNodes(root);

    // Clean up memory (In a complete program, you would likely need to free the memory for the tree)
    return 0;
}
