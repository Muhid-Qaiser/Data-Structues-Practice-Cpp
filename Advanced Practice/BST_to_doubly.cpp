#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;

    BstNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class Bst
{
    BstNode *root;

    BstNode *insert_util(BstNode *node, int data)
    {
        if (!node)
        {
            return new BstNode(data);
        }

        if (data <= node->data)
        {
            node->left = insert_util(node->left, data);
        }
        else
        {
            node->right = insert_util(node->right, data);
        }
        return node;
    }

    void inOrder_util(BstNode *node)
    {
        if (!node)
            return;

        inOrder_util(node->left);
        cout << node->data << " ";
        inOrder_util(node->right);
    }

    void Bst_to_doubly_util(BstNode *node, Node *&curr)
    {
        if (!node)
            return;

        Bst_to_doubly_util(node->left, curr);

        Node *nn = new Node(node->data);
        curr->next = nn;
        nn->prev = curr;
        curr = nn;

        Bst_to_doubly_util(node->right, curr);
    }

public:
    Bst()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insert_util(root, data);
    }

    void inOrder()
    {
        inOrder_util(root);
        cout << endl;
    }

    void displayDoubly(Node *head)
    {
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    Node *Bst_to_doubly()
    {
        Node *dummy = new Node(0);
        Node *curr = dummy;

        Bst_to_doubly_util(root, curr);

        Node *res = dummy->next;
        delete dummy;
        res->prev = NULL;

        return res;
    }
};

int main()
{
    Bst b;
    b.insert(4);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.insert(5);
    b.inOrder();

    Node *n = b.Bst_to_doubly();
    b.displayDoubly(n);

    return 0;
}