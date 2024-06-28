
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *mirrorTree(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    stack<Node *> s;
    s.push(root);
    Node *newRoot = new Node{root->data, nullptr, nullptr};
    Node *curr = newRoot;
    while (!s.empty())
    {
        Node *node = s.top();
        s.pop();
        if (node->right != nullptr)
        {
            curr->left = new Node{node->right->data, nullptr, nullptr};
            s.push(node->right);
        }
        if (node->left != nullptr)
        {
            curr->right = new Node{node->left->data, nullptr, nullptr};
            s.push(node->left);
        }
        if (!s.empty())
        {
            curr = curr->right;
        }
    }
    return newRoot;
}

class BST
{
    Node *root;

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            node = new Node;
            node->data = data;
            node->left = node->right = NULL;
        }
        else if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    bool search(Node *node, int data)
    {
        if (node == NULL)
            return false;
        else if (node->data == data)
            return true;
        else if (data <= node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    void display_util(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        display_util(root->left);
        display_util(root->right);
    }

    Node *getMirrorBst_util(Node *node1)
    {
        if (!node1)
            return NULL;

        Node *node2 = new Node{node1->data, NULL, NULL};
        node2->right = getMirrorBst_util(node1->left);
        node2->left = getMirrorBst_util(node1->right);

        return node2;
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    bool search(int data)
    {
        return search(root, data);
    }

    void display(Node *node = NULL)
    {
        Node *temp;

        if (node)
            temp = node;
        else
            temp = root;

        display_util(temp);
    }

    Node *getRoot()
    {
        return root;
    }

    Node *getMirrorBst()
    {
        Node *temp = root;
        return getMirrorBst_util(temp);
    }
};

Node *constructMirrorTree(Node *root)
{
    if (!root)
        return NULL;

    // Swap left and right children
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively construct mirror trees for left and right subtrees
    constructMirrorTree(root->left);
    constructMirrorTree(root->right);
    return root;
}

int main()
{
    BST b;

    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(1);
    b.insert(7);
    b.insert(11);
    b.insert(17);
    b.display();

    Node *mirror = b.getMirrorBst();
    cout << endl;
    cout << endl;
    b.display(mirror);

    Node *m2 = NULL;
    m2 = constructMirrorTree(mirror);
    cout << endl;
    cout << endl;
    b.display(m2);

    // b.getMirrorBst();
}