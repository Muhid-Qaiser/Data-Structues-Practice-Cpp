#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char data) : data(data)
    {
        next = NULL;
    }
};

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }
    void push(char data)
    {
        Node *nn = new Node(data);
        nn->next = head;
        head = nn;
    }
    char pop()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return '\0';
        }

        Node *temp = head;
        char data = temp->data;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return data;
    }
    char Top()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return '\0';
        }

        return head->data;
    }
    void display()
    {
        Node *temp = head;

        cout << "Stack: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};

bool isOperator(char data)
{
    return data == '-' || data == '+' || data == '*' || data == '/' || data == '^' || data == '(' || data == ')';
}

bool precedence(char top, char data)
{
    if ((top == '-' && data == '*') || (top == '-' && data == '/') ||
        (top == '+' && data == '*') || (top == '+' && data == '/') ||
        (top == '*' && data == '^') || (top == '/' && data == '^') ||
        (data == '(') || (data == ')') || (top == '('))
        return true;

    return false;
}

void infix_to_postfix()
{
    Stack s;
    // string str = "((A-(B+C))*D)^(E+F)";
    string str = "(a+b)*c";
    string res;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isOperator(str[i]))
        {
            res += str[i];
        }
        else if (!s.isEmpty() && !precedence(s.Top(), str[i]))
        {
            while (!s.isEmpty() && !precedence(s.Top(), str[i]))
            {
                res += s.pop();
            }
            s.push(str[i]);
        }
        else if (!s.isEmpty() && str[i] == ')')
        {
            while (s.Top() != '(')
            {
                res += s.pop();
            }
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }
    while (!s.isEmpty())
    {
        res += s.pop();
    }

    cout << res << endl;
}

void evaluate_postfix()
{
    Stack s;
    string str = "23+5*";

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i]);
        }
        else if (isOperator(str[i]))
        {
            int num2 = s.pop() - 48;
            int num1 = s.pop() - 48;

            if (str[i] == '+')
                s.push((num1 + num2));
            if (str[i] == '-')
                s.push((num1 - num2));
            if (str[i] == '*')
                s.push((num1 * num2));
            if (str[i] == '/')
                s.push((num1 / num2));
            if (str[i] == '^')
                s.push((num1 ^ num2));
        }
    }
    cout << s.pop() << endl;
}

int main()
{
    // infix_to_postfix();
    evaluate_postfix();
    return 0;
}