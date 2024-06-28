#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    // Test case 1: Balanced binary tree
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    std::cout << "Test case 1: " << (isBalanced(root1) ? "Balanced" : "Not balanced") << std::endl;

    // Test case 2: Unbalanced binary tree
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    std::cout << "Test case 2: " << (isBalanced(root2) ? "Balanced" : "Not balanced") << std::endl;

    return 0;
}
