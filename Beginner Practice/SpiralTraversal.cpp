#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d)
    {
        left = NULL;
        right = NULL;
    }
};

class LinkedListNode
{
public:
    Node *data;
    LinkedListNode *right;

    LinkedListNode(Node *d)
    {
        data = d;
        right = NULL;
    }
};

class LinkedList
{
    LinkedListNode *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertStart(Node *n)
    {
        LinkedListNode *node = new LinkedListNode(n);

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->right = head;
            head = node;
        }
    }

    Node *deleteStart()
    {
        if (!head)
            return NULL;

        Node *temp = head->data;
        head = head->right;

        return temp;
    }

    bool empty() const
    {
        return (head == NULL);
    }

    void display()
    {
        LinkedListNode *temp = head;

        if (!head)
        {
            cout << "empty!";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data->data << " ";
            temp = temp->right;
        }
        cout << endl;
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

        cout << node->data << " ";
        inOrder_util(node->left);
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

    void SpiralTraversal()
    {
        if (!root)
            return;

        LinkedList l1, l2;
        Node *n = NULL;
        bool lr = true;

        l1.insertStart(root);

        while (!l1.empty())
        {
            n = NULL;
            n = l1.deleteStart();
            cout << n->data << " ";

            if (lr)
            {
                if (n->right)
                {
                    // cout << "in: " << n->right->data << endl;
                    l2.insertStart(n->right);
                }
                if (n->left)
                {
                    // cout << "ke: " << n->left->data << endl;
                    l2.insertStart(n->left);
                }
            }
            else
            {
                if (n->left)
                    l2.insertStart(n->left);
                if (n->right)
                    l2.insertStart(n->right);
            }

            if (l1.empty())
            {
                lr = !lr;
                swap(l1, l2);
            }
        }
    }
};

int main()
{
    BTrees b;

    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(1);
    b.insert(7);
    b.insert(11);
    b.insert(17);
    // b.inOrder();
    b.SpiralTraversal();
    return 0;
}