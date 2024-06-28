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

void balancedParenthesis()
{
    string str = "{([][])}";
    Stack s;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '[' || str[i] == '(' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else if ((str[i] == '}' && s.Top() == '{') || (str[i] == ']' && s.Top() == '[') || (str[i] == ')' && s.Top() == '('))
        {
            s.pop();
        }
    }
    cout << s.isEmpty();
}

int main()
{

    balancedParenthesis();
    return 0;
}