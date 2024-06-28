#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};

class BTrees
{
    Node *root;

public:
    BTrees()
    {
        root = NULL;
    }

    Node *insert_util(Node *node, int data)
    {
        if (!node)
        {
            return new Node(data);
        }

        if (data < node->data)
        {
            node->left = insert_util(node->left, data);
        }
        else
        {
            node->right = insert_util(node->right, data);
        }

        return node;
    }

    void insert(int data)
    {
        if (!root)
        {
            root = new Node(data);
        }
        else
            insert_util(root, data);
    }

    void inOrder_util(Node *node)
    {
        if (!node)
            return;

        inOrder_util(node->left);
        cout << node->data << " ";
        inOrder_util(node->right);
    }

    void inOrder()
    {
        if (!root)
        {
            cout << "Empty!\n";
        }
        else
        {
            inOrder_util(root);
            cout << endl;
        }
    }

    Node *findMin(Node *node)
    {
        if (!node->left)
        {
            return node;
        }

        return findMin(node->left);
    }

    Node *delete_util(Node *node, int data, Node *prev = NULL)
    {
        if (data < node->data)
        {
            node->left = delete_util(node->left, data, node);
        }
        else if (data > node->data)
        {
            node->right = delete_util(node->right, data, node);
        }
        else
        {
            if (node->left && node->right)
            {
                Node *nn = findMin(node->right);
                node->data = nn->data;
                node->right = delete_util(node->right, node->data, node);
            }

            else if (!node->left && !node->right)
            {
                delete node;
                node = NULL;
            }
            else if (node->left)
            {
                Node *temp = node;
                node = node->left;
                delete temp;
            }
            else if (node->right)
            {
                Node *temp = node;
                node = node->right;
                delete temp;
            }
        }

        return node;
    }

    void deleteNode(int data)
    {
        if (root)
            root = delete_util(root, data);
        else
            cout << "Empty\n";
    }

    int getRoot() const
    {
        return root->data;
    }

    int getHeight_util(Node *node)
    {
        if (!node)
            return -1;

        return max(getHeight_util(node->left), getHeight_util(node->right)) + 1;
    }

    int getHeight()
    {
        if (root)
            return getHeight_util(root);
        else
        {
            cout << "Empty\n";
            return -1;
        }
    }

    bool isBst_util(Node *node, int min, int max)
    {
        if (!node)
            return true;

        if (node->data >= min && node->data <= max && isBst_util(node->left, min, node->data) && isBst_util(node->right, node->data, max))
            return true;
        return false;
    }

    bool isBst()
    {
        if (root)
            return isBst_util(root, INT_MIN, INT_MAX);
        else
        {
            cout << "Empty\n";
            return true;
        }
    }

    bool isBstInOrder_util(Node *node, int &prev)
    {
        if (!node)
        {
            return true;
        }

        if (!isBstInOrder_util(node->left, prev))
            return false;

        if (node->data < prev)
            return false;

        prev = node->data;

        return isBstInOrder_util(node->right, prev);
    }

    bool isBstInOrder()
    {
        if (root)
        {
            int min = INT_MIN;
            return isBstInOrder_util(root, min);
        }
        else
        {
            cout << "Empty\n";
            return true;
        }
    }
};

int main()
{
    BTrees b;

    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.insert(17);
    b.insert(1);
    // b.insert(0);
    b.insert(4);
    b.insert(6);
    b.insert(8);
    b.insert(11);
    b.inOrder();

    b.deleteNode(10);
    b.inOrder();

    cout << b.getHeight() << endl;
    cout << b.isBst() << endl;

    return 0;
}