
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

bool isDifferenceTreeUtil(Node *node, int &sum)
{
    if (node == NULL)
    {
        sum = 0;
        return true;
    }

    int leftSum = 0, rightSum = 0;
    bool left = isDifferenceTreeUtil(node->left, leftSum);
    bool right = isDifferenceTreeUtil(node->right, rightSum);

    sum = leftSum + rightSum + node->key;

    return (abs(leftSum - rightSum) == node->key && left && right);
}

bool isDifferenceTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int sum = 0;
    return isDifferenceTreeUtil(root, sum);
}

int main()
{
    Node *root = newNode(9);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);

    if (isDifferenceTree(root))
    {
        cout << "The tree is a difference tree" << endl;
    }
    else
    {
        cout << "The tree is not a difference tree" << endl;
    }

    return 0;
}
