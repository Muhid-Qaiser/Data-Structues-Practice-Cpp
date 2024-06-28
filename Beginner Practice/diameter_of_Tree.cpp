#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int diameter(Node *root, int &ans)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_height = diameter(root->left, ans);
    int right_height = diameter(root->right, ans);
    ans = max(ans, left_height + right_height);
    return max(left_height, right_height) + 1;
}

int diameterOfBinaryTree(Node *root)
{
    int ans = 0;
    diameter(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(5);

    int result = diameterOfBinaryTree(root);
    std::cout << "Diameter of the binary tree: " << result << std::endl;

    return 0;
}
