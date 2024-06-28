#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int CountNode;

    Node(int d, int c = 1, Node *l = NULL, Node *r = NULL) : data(d), CountNode(c), left(l), right(r){};
};

class Stack
{
    Node *head;
    int size = 0;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *nn = new Node(data);

        if (!head)
            head = nn;

        else
        {
            nn->right = head;
            head = nn;
        }
        size++;
    }

    void pop()
    {
        if (!head)
        {
            cout << "empty!\n";
        }
        else
        {
            Node *temp = head;
            head = head->right;
            temp->right = NULL;
            delete temp;
        }
        size--;
    }

    int top()
    {
        if (head)
            return head->data;

        return -1;
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    // Deep copy constructor
    Stack(const Stack &other) : head(NULL)
    {
        if (other.head)
        {
            head = new Node{other.head->data};
            Node *current = head;
            Node *otherCurrent = other.head->right;
            while (otherCurrent)
            {
                current->right = new Node{otherCurrent->data};
                current = current->right;
                otherCurrent = otherCurrent->right;
            }
        }
    }
};

class BST
{
    Node *head;

    Node *insert_util(Node *node, int data)
    {
        if (!node)
            return new Node(data);

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

    void inOrder_util(Node *node)
    {
        if (!node)
            return;

        inOrder_util(node->left);
        cout << node->data << " ";
        inOrder_util(node->right);
    }

    void preOrder_util(Node *node)
    {
        if (!node)
            return;

        cout << node->data << " ";
        preOrder_util(node->left);
        preOrder_util(node->right);
    }

    bool isPerfect_util(Node *node, int depth, int level)
    {
        if (!node)
            return true;

        if (!node->left && !node->right)
            return (depth == level);

        else if (!node->left || !node->right)
            return false;

        return isPerfect_util(node->left, depth, level + 1) && isPerfect_util(node->right, depth, level + 1);
    }

    int countNodes_util(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + countNodes_util(node->left) + countNodes_util(node->right);
        }
    }

    bool isDifference_util(Node *node, int &sum)
    {
        if (!node)
        {
            sum = 0;
            return true;
        }
        int leftSum = 0, rightSum = 0;
        bool left = isDifference_util(node->left, leftSum);
        bool right = isDifference_util(node->right, rightSum);

        sum = leftSum + rightSum + node->data;

        return (abs(leftSum + rightSum) == sum && left && right);
    }

    int getHeight_util(Node *node)
    {
        if (!node)
            return 0;

        return max(getHeight_util(node->left), getHeight_util(node->right)) + 1;
    }

    bool seqExist_util(Node *node, int seq[], int &index)
    {
        if (!node)
            return true;

        seqExist_util(node->left, seq, index);

        if (seq[index] == node->data)
            index++;

        seqExist_util(node->right, seq, index);
    }

    int getDiameter_util(Node *node, int &ans)
    {
        if (!node)
            return 0;

        int leftHeight = getDiameter_util(node->left, ans);
        int rightHeight = getDiameter_util(node->right, ans);

        ans = max(ans, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

    void getAncestor(Node *node, int data, Stack &s)
    {
        if (node)
        {
            if (data < node->data)
            {
                s.push(node->data);
                getAncestor(node->left, data, s);
            }
            else if (data > node->data)
            {
                s.push(node->data);
                getAncestor(node->right, data, s);
            }
        }
    }

    void sameAncestor(int val, Stack s)
    {
        while (!s.isEmpty())
        {
            if (val == s.top())
                cout << val << " ";
            s.pop();
        }
    }

    Node *deleteNode_util(Node *node, int data)
    {
        if (!node)
            return NULL;

        else if (data < node->data)
        {
            node->left = deleteNode_util(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = deleteNode_util(node->right, data);
        }
        else
        {
            if (node->left && node->right)
            {
                Node *min = node->right;
                while (min->left)
                    min = min->left;

                node->data = min->data;
                node->right = deleteNode_util(node->right, node->data);
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

public:
    BST()
    {
        head = NULL;
    }

    void insert(int data)
    {
        head = insert_util(head, data);
    }

    void inOrder()
    {
        inOrder_util(head);
        cout << endl;
    }

    void preOrder()
    {
        preOrder_util(head);
        cout << endl;
    }

    bool isPerfect()
    {
        int depth = 0;
        Node *temp = head;

        while (temp->left)
        {
            depth++;
            temp = temp->left;
        }

        return isPerfect_util(head, depth, 0);
    }

    int countNodes()
    {
        return countNodes_util(head);
    }

    bool isDiffernce()
    {
        int sum = 0;
        return isDifference_util(head, sum);
    }

    int getHeight()
    {
        return getHeight_util(head) - 1;
    }

    bool seqExist(int seq[], int n)
    {
        int index = 0;
        seqExist_util(head, seq, index);
        // return index == sizeof(seq) / sizeof(seq[0]);
        return index == n;
    }

    int getDiameter()
    {
        int ans = 0;
        getDiameter_util(head, ans);
        return ans;
    }

    void findAncestors(int num1, int num2)
    {
        Stack s1, s2, s3;

        getAncestor(head, num1, s1);
        getAncestor(head, num2, s2);

        while (!s1.isEmpty())
        {
            s3 = s2;
            sameAncestor(s1.top(), s3);
            s1.pop();
        }
    }

    // ! DELETION
    void deleteNode(int data)
    {
        head = deleteNode_util(head, data);
    }
};

int main()
{
    BST t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(1);
    t.insert(7);
    t.insert(17);
    t.insert(11);
    t.inOrder();
    t.preOrder();

    cout << t.isPerfect();
    cout << endl;
    cout << t.countNodes();
    cout << endl;
    cout << t.isDiffernce();
    cout << endl;
    cout << t.getHeight();

    int seq[] = {10, 11, 15, 17};
    cout << endl;
    cout << "sequence: " << t.seqExist(seq, 4);
    cout << endl;
    cout << t.getDiameter();

    cout << endl;
    t.findAncestors(1, 7);

    cout << endl;
    t.deleteNode(7);
    t.inOrder();

    return 0;
}