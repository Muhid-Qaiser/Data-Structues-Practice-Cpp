#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int CountNode;

    Node(int d, int c = 1, Node *l = NULL, Node *r = NULL) : data(d), CountNode(c), left(l), right(r){};
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insertNode(int data)
    {
        Node *newNode = new Node(data);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;

            if (data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }

            parent->CountNode++;
        }

        if (data < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    void insert(int data)
    {
        Node *nn = new Node(data);
    }

    int countNodes(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + countNodes(node->left) + countNodes(node->right);
        }
    }

    int countNodes(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return node->CountNode;
    }

    bool isPerfect(Node *node, int depth, int level)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return (depth == level + 1);
        }

        if (node->left == nullptr || node->right == nullptr)
        {
            return false;
        }

        return isPerfect(node->left, depth, level + 1) && isPerfect(node->right, depth, level + 1);
    }

    bool isPerfect()
    {
        int depth = 0;
        Node *current = root;

        while (current != nullptr)
        {
            depth++;
            current = current->left;
        }

        return isPerfect(root, depth, 0);
    }
};

int main()
{
    BinaryTree tree;

    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(12);
    tree.insertNode(17);

    if (tree.isPerfect())
    {
        cout << "The binary tree is perfect." << endl;
    }
    else
    {
        cout << "The binary tree is not perfect." << endl;
    }

    return 0;
}
