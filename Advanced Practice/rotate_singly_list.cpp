#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *n = NULL) : data(data), next(n) {}
};

class SinglyList
{
    Node *head;

public:
    SinglyList()
    {
        head = NULL;
    }

    void insertStart(int data)
    {
        Node *nn = new Node(data);

        if (!head)
        {
            head = nn;
        }
        else
        {
            nn->next = head;
            head = nn;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rotate(int n)
    {
        Node *tail = NULL, *temp = NULL;

        for (int i = 0; i < n; i++)
        {
            tail = head;
            while (tail->next->next)
            {
                tail = tail->next;
            }
            temp = tail;
            tail = tail->next;
            temp->next = NULL;
            tail->next = head;
            head = tail;
        }
    }
};

int main()
{
    SinglyList l;
    l.insertStart(5);
    l.insertStart(4);
    l.insertStart(3);
    l.insertStart(2);
    l.insertStart(1);
    l.display();

    l.rotate(3);
    l.display();

    return 0;
}