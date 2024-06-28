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

    void move_to_next(int val)
    {
        if (head->data == val)
            return;

        else
        {
            Node *node = head, *temp = NULL;

            while (node->next->data != val)
            {
                if (!node->next->next)
                {
                    cout << "Node Not Found!\n";
                    return;
                }
                node = node->next;
            }

            Node *nextNode = node->next->next;
            node->next->next = head;
            head = node->next;
            node->next = nextNode;
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

    l.move_to_next(3);
    l.display();

    return 0;
}