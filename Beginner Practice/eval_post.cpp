#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data)
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
    int pop()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return -1;
        }

        Node *temp = head;
        char data = temp->data;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return data;
    }
    int Top()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return -1;
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

void evaluate_postfix()
{
    Stack s;
    string str = "23+5*";

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i] - 48);
        }
        else if (isOperator(str[i]))
        {
            int num2 = s.pop();
            int num1 = s.pop();

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
    evaluate_postfix();
    return 0;
}