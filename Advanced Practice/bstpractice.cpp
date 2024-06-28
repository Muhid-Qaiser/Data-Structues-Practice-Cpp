#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node()
    {
        left = NULL;
        right = NULL;
        data = -1;
    }
    Node(int data) : data(data), right(nullptr), left(nullptr){};
};

struct SubtreeInfo
{
    bool isBst;
    int size;
    int min, max;

    SubtreeInfo(bool isBst, int size, int min, int max) : isBst(isBst), size(size), min(min), max(max) {}
};

struct Pair
{
    int hd;
    Node *node;

    Pair(int hd, Node *node) : hd(hd), node(node) {}
};

class BST
{
    Node *root;

    Node *insert_util(Node *node, int data)
    {
        if (!node)
        {
            return new Node(data);
        }

        if (node->data > data)
        {
            node->left = insert_util(node->left, data);
        }
        else
        {
            node->right = insert_util(node->right, data);
        }

        return node;
    }

    void inOrder(Node *node)
    {
        if (!node)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    Node *findMin(Node *node)
    {
        if (!node->left)
            return node;

        return findMin(node->left);
    }

    Node *deleteNode_util(Node *node, int data)
    {
        if (!node)
            return NULL;

        if (node->data > data)
            node->left = deleteNode_util(node->left, data);
        else if (node->data < data)
            node->right = deleteNode_util(node->right, data);
        else
        {
            if (node->left && node->right)
            {
                Node *newNode = findMin(node->right);
                node->data = newNode->data;
                node->right = deleteNode_util(node->right, node->data);
            }
            else if (!node->right && !node->left)
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

    int getHeight_util(Node *node)
    {
        if (!node)
            // return -1;
            return 0;

        return max(getHeight_util(node->left), getHeight_util(node->right)) + 1;
    }

    bool isPerfect_util(Node *node, int depth, int level)
    {
        if (!node)
            return true;

        if (!node->left && !node->right)
            return depth == level;

        if (!node->right || !node->left)
            return false;

        return isPerfect_util(node->left, depth, level + 1) && isPerfect_util(node->right, depth, level + 1);
    }

    int getDiameter_util(Node *node, int &res)
    {
        if (!node)
            return 0;

        int left = getDiameter_util(node->left, res);
        int right = getDiameter_util(node->right, res);

        res = max(res, left + right);

        return max(left, right) + 1;
    }

    bool isBST_util(Node *node, int min, int max)
    {
        if (!node)
            return true;

        return (node->data <= max && node->data >= min && isBST_util(node->left, min, node->data) && isBST_util(node->right, node->data, max));
    }

    bool isBST_util(Node *node, int &prev)
    {
        if (!node)
            return true;

        if (!isBST_util(node->left, prev))
            return false;

        if (prev > node->data)
            return false;

        prev = node->data;

        return isBST_util(node->right, prev);
    }

    Node *mirror_util(Node *node)
    {
        if (!node)
            return NULL;

        Node *node2 = new Node(node->data);
        if (node->right)
            node2->left = mirror_util(node->right);
        if (node->left)
            node2->right = mirror_util(node->left);

        return node2;
    }

    bool isBalanced_util(Node *node)
    {
        if (!node)
            return true;

        int left = getHeight_util(node->left);
        int right = getHeight_util(node->right);

        if (abs(left - right) > 1)
            return false;

        return isBalanced_util(node->left) && isBalanced_util(node->right);
    }

    SubtreeInfo largestBst_util(Node *node, int &maxsize, Node *&largest)
    {
        if (!node)
            return {true, 0, INT_MAX, INT_MIN};

        SubtreeInfo left = largestBst_util(node->left, maxsize, largest);
        SubtreeInfo right = largestBst_util(node->right, maxsize, largest);

        if (left.isBst && right.isBst && node->data <= right.min && node->data >= left.max)
        {
            int totalsize = (left.size + right.size) + 1;
            if (maxsize < totalsize)
            {
                maxsize = totalsize;
                largest = node;
            }

            return {true, maxsize, min(node->data, left.min), max(node->data, right.max)};
        }
        else
        {
            return {false, 0, 0, 0};
        }
    }

    bool isIdentical(Node *node1, Node *node2)
    {
        if (!node2 && !node1)
            return true;
        else if (!node2 || !node1)
            return false;

        return node1->data == node2->data && isIdentical(node1->left, node2->left) && isIdentical(node2->right, node1->right);
    }

    bool isUnique(Node *root, Node *node)
    {
        if (!node)
            return true;

        else if (isIdentical(root, node))
            return false;
        else
            return isUnique(root, node->left) || isUnique(root, node->right);
    }

    int countSubTrees(Node *node)
    {
        if (!node)
            return 0;
        int count = 0;
        if (isUnique(node, node->left))
            count++;
        if (isUnique(node, node->right))
            count++;

        return count + countSubTrees(node->left) + countSubTrees(node->right);
    }

    void getHD(Node *node, int hd, int &minhd, int &maxhd)
    {
        if (!node)
            return;

        minhd = min(minhd, hd);
        maxhd = max(maxhd, hd);

        getHD(node->left, hd - 1, minhd, maxhd);
        getHD(node->right, hd + 1, minhd, maxhd);
    }

    void verticalTraversal_util(Node *node)
    {
        int minhd = 0, maxhd = 0, size = 0;

        getHD(node, 0, minhd, maxhd);

        size = maxhd - minhd + 1;

        vector<vector<int>> verticalOrder(size);
        queue<Pair> q;

        q.push(Pair(-minhd, node));

        while (!q.empty())
        {
            Pair curr = q.front();
            q.pop();

            verticalOrder[curr.hd].push_back(curr.node->data);

            if (curr.node->left)
                q.push(Pair(curr.hd - 1, curr.node->left));
            if (curr.node->right)
                q.push(Pair(curr.hd + 1, curr.node->right));
        }

        for (vector level : verticalOrder)
        {
            for (int i : level)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    void spiralTraversal_util(Node *node)
    {
        bool lr = true;
        stack<Node *> s1, s2;

        s1.push(node);

        while (!s1.empty())
        {
            Node *curr = s1.top();
            s1.pop();

            cout << curr->data << " ";

            if (lr)
            {
                if (curr->right)
                    s2.push(curr->right);
                if (curr->left)
                    s2.push(curr->left);
            }
            else
            {
                if (curr->left)
                    s2.push(curr->left);
                if (curr->right)
                    s2.push(curr->right);
            }

            if (s1.empty())
            {
                lr = !lr;
                swap(s2, s1);
            }
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insert_util(root, data);
    }

    void display()
    {
        inOrder(root);
        cout << endl;
    }

    void deleteNode(int data)
    {
        root = deleteNode_util(root, data);
    }

    int getHeight()
    {
        return getHeight_util(root);
    }

    bool isPerfect()
    {
        int depth = 0;
        Node *temp = root;

        while (temp->left)
        {
            temp = temp->left;
            depth++;
        }

        return isPerfect_util(root, depth, 0);
    }

    int getDiameter()
    {
        int ans = 0;
        getDiameter_util(root, ans);
        return ans;
    }

    bool isBST()
    {
        // return isBST_util(root, INT_MIN, INT_MAX);
        int prev = INT_MIN;
        return isBST_util(root, prev);
    }

    bool isomorphic_util(Node *node, Node *root2)
    {
        if (!node && !root2)
            return true;

        else if (!node || !root2)
            return false;

        else if (node->data != root2->data)
            return false;

        bool case1 = false, case2 = false;

        case1 = isomorphic_util(node->left, root2->left) && isomorphic_util(node->right, root2->right);
        case2 = isomorphic_util(node->left, root2->right) && isomorphic_util(node->right, root2->left);

        return case1 || case2;
    }

    void mirror()
    {
        root = mirror_util(root);
    }

    bool isBalanced()
    {
        return isBalanced_util(root);
    }

    Node *largestBST()
    {
        int maxsize = 0;
        Node *largestBST = NULL;
        largestBst_util(root, maxsize, largestBST);
        return largestBST;
    }

    int getcountSubTrees()
    {
        return countSubTrees(root);
    }

    void verticalTraversal()
    {
        verticalTraversal_util(root);
    }

    void spiralTraversal()
    {
        spiralTraversal_util(root);
        cout << endl;
    }
};

void BstQs()
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

    // cout << b.getcountSubTrees() << endl;
    b.spiralTraversal();
    // b.display();
}

// ! BinaryTree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next; // Pointer to the next node on the same level

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), next(nullptr) {}
};

TreeNode *connectSameLevel(TreeNode *node)
{
    if (!node)
        return NULL;

    queue<TreeNode *> q;
    q.push(node);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (i < size - 1)
            {
                curr->next = q.front();
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

void displaySameLevel(TreeNode *node)
{
    TreeNode *temp = node;
    while (temp)
    {
        TreeNode *temp2 = temp;
        while (temp2)
        {
            cout << temp2->val << " ";
            temp2 = temp2->next;
        }
        temp = temp->left;
        cout << endl;
    }
}

void binaryTreeQs()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    connectSameLevel(root);
    displaySameLevel(root);
}

// ! BST to Doubly

void convertBSTToDoublyLinkedList_util(Node *node, Node *&head, Node *&prev)
{
    if (!node)
        return;

    convertBSTToDoublyLinkedList_util(node->left, head, prev);

    if (!prev)
    {
        head = node;
    }
    else
    {
        prev->right = node;
        node->left = prev;
    }

    prev = node;
    convertBSTToDoublyLinkedList_util(node->right, head, prev);
}

Node *convertBSTToDoublyLinkedList(Node *node)
{
    Node *head = NULL, *prev = NULL;
    convertBSTToDoublyLinkedList_util(node, head, prev);
    return head;
}

void bst_doublyQs()
{
    // Create a sample BST
    Node *root = new Node();
    root->data = 4;
    root->left = new Node();
    root->left->data = 2;
    root->left->left = new Node();
    root->left->left->data = 1;
    root->left->right = new Node();
    root->left->right->data = 3;
    root->right = new Node();
    root->right->data = 5;

    // Convert BST to doubly linked list
    Node *head = convertBSTToDoublyLinkedList(root);

    // Print the doubly linked list
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    // BstQs();
    // binaryTreeQs();
    bst_doublyQs();

    return 0;
}