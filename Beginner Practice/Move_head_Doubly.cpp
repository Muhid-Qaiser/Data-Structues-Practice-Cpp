#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d, Node *l = NULL, Node *r = NULL) : data(d), left(l), right(r) {}
};

class DoublyLinkedlist
{
    Node *head;

public:
    DoublyLinkedlist()
    {
        head = NULL;
    }

    void insert(int data)
    {
        Node *node = new Node(data);

        if (!head)
            head = node;

        else
        {
            Node *temp = head;

            while (temp->right)
            {
                temp = temp->right;
            }

            temp->right = node;
            node->left = temp;
        }
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

    void moveHead(int pos)
    {
        Node *temp1 = head, *temp2 = head;
        int i = 0;

        while (temp1->right)
        {
            if (pos == i)
            {
                head = temp1;
                temp1->left->right = NULL;
                temp1->left = NULL;
            }
            temp1 = temp1->right;
            i++;
        }
        temp2->left = temp1;
        temp1->right = temp2;
    }
};

int main()
{
    DoublyLinkedlist d;
    d.insert(1);
    d.insert(2);
    d.insert(3);
    d.insert(4);
    d.insert(5);
    d.insert(6);
    d.insert(8);
    d.display();
    d.moveHead(3);
    d.display();

    return 0;
}