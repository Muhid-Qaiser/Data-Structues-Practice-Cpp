#include <iostream>
#include <queue>
#include <stack>
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

    Node *insert_util(Node *node, int data)
    {
        if (!node)
            return new Node(data);

        else if (data <= node->data)
            node->left = insert_util(node->left, data);

        else if (data > node->data)
            node->right = insert_util(node->right, data);

        return node;
    }

    void preOrder_util(Node *node)
    {
        if (!node)
            return;

        preOrder_util(node->left);
        cout << node->data << " ";
        preOrder_util(node->right);
    }

    Node *delete_util(Node *node, int data)
    {
        if (!node)
            return NULL;

        // * Search the node
        else if (data < node->data)
            node->left = delete_util(node->left, data);

        else if (data > node->data)
            node->right = delete_util(node->right, data);

        // * Delete the node
        else
        {
            if (!node->right)
            {
                Node *temp = node;

                node = node->left;

                temp->left = NULL;
                temp->right = NULL;
                delete temp;
            }
            else if (!node->left)
            {
                Node *temp = node;

                node = node->right;

                temp->left = NULL;
                temp->right = NULL;
                delete temp;
            }
            else
            {
                Node *temp = node->right;

                while (temp->left)
                    temp = temp->left;

                temp->left = node->left;
                temp = node;
                node = node->right;

                temp->left = NULL;
                temp->right = NULL;
                delete temp;
            }
        }

        return node;
    }

    void levelOrder_util(Node *node)
    {
        queue<Node *> q;

        q.push(node);

        while (!q.empty())
        {
            Node *nn = q.front();
            q.pop();

            cout << nn->data << " ";

            if (nn->left)
                q.push(nn->left);
            if (nn->right)
                q.push(nn->right);
        }
    }

    void getAncestors(Node *node, int num1, stack<int> &s)
    {
        if (node)
        {
            if (num1 < node->data)
            {
                s.push(node->data);
                getAncestors(node->left, num1, s);
            }
            else if (num1 > node->data)
            {
                s.push(node->data);
                getAncestors(node->right, num1, s);
            }
        }
    }

    void sameAncestor(int val, stack<int> s)
    {
        while (!s.empty())
        {
            if (val == s.top())
                cout << val << " ";
            s.pop();
        }
    }

public:
    BTrees()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insert_util(root, data);
    }

    void preOrder()
    {
        preOrder_util(root);
        cout << endl;
    }

    void deleteNode(int data)
    {
        root = delete_util(root, data);
    }

    void levelOrder()
    {
        levelOrder_util(root);
    }

    void findAncestor(int num1, int num2)
    {
        stack<int> s1, s2;

        getAncestors(root, num1, s1);
        getAncestors(root, num2, s2);

        while (!s1.empty())
        {
            sameAncestor(s1.top(), s2);
            s1.pop();
        }
    }
};

int main()
{
    // BTrees b;

    // b.insert(10);
    // b.insert(15);
    // b.insert(5);
    // b.insert(13);
    // b.insert(17);
    // b.insert(3);
    // b.insert(7);
    // b.insert(11);
    // b.insert(14);
    // b.preOrder();

    // b.findAncestor(11, 14);

    string str = "abbacaac";

    stack<char> s1, s2;

    for (char &c : str)
        s1.push(c);

    s2.push(s1.top());
    s1.pop();

    while (!s1.empty())
    {
        if (s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        if (s1.top() == s2.top())
        {
            s1.pop();
            s2.pop();
        }
        else
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}