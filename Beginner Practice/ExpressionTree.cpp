#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

void inOrder(Node *node)
{
    if (!node)
        return;

    inOrder(node->left);
    cout << node->data;
    inOrder(node->right);
}

queue<Node *> q;

void levelOrder(Node *node)
{
    q.push(node);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << front->data << " ";
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
}

int applyOp(int op1, char op, int op2)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
    return -1;
}

int evaluate(Node *node)
{
    if (!node->left && !node->right)
        return node->data - 48;

    char operand = node->data;
    int operator1 = evaluate(node->left);
    int operator2 = evaluate(node->right);

    return applyOp((operator1), operand, (operator2));
}

int main()
{
    // string str = "ab+cde+**";
    string str = "12+345+**";
    stack<Node *> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (!isOperator(str[i]))
        {
            Node *nn = new Node(str[i]);
            s.push(nn);
        }
        else
        {
            Node *op = new Node(str[i]);
            op->right = s.top();
            s.pop();
            op->left = s.top();
            s.pop();
            s.push(op);
        }
    }

    inOrder(s.top());
    cout << endl;

    cout << evaluate(s.top()) << endl;

    return 0;
}
