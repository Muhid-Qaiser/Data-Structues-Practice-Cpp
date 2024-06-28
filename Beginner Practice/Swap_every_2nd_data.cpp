#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d, Node *l = NULL, Node *r = NULL) : data(d), left(l), right(r) {}
};

class LinkedList
{
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    void insert(int data)
    {
        Node *nn = new Node(data);

        if (!head)
        {
            head = nn;
        }
        else
        {
            nn->right = head;
            head = nn;
        }
        size++;
    }

    void display()
    {
        display(head);
        cout << endl;
    }

    void display(Node *node)
    {
        if (!node)
            return;

        cout << node->data << " ";
        display(node->right);
    }

    int getSize() const
    {
        return size;
    }

    Node *getHead() const
    {
        return head;
    }
};

void swap2nd()
{
    LinkedList l1;
    l1.insert(5);
    l1.insert(6);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.display();

    LinkedList l2;
    l2.insert(1);
    l2.insert(9);
    l2.insert(15);
    l2.insert(20);
    l2.insert(6);
    l2.display();

    // Node *temp = (l1.getSize() > l2.getSize()) ? l1.getHead() : l2.getHead();

    Node *temp1 = l1.getHead(), *temp2 = l2.getHead();
    int count = 1;

    // while (temp1->right && temp2->right)
    while (temp1 && temp2)
    {
        if (count % 2 == 0)
        {
            int k = temp1->data;
            temp1->data = temp2->data;
            temp2->data = k;
        }
        count++;
        temp1 = temp1->right;
        temp2 = temp2->right;
    }

    cout << "\nswapped: \n";
    l1.display();
    l2.display();
}

int main()
{
    swap2nd();

    return 0;
}