#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *n = NULL) : data(data), next(n), prev(n) {}
};

class DoublyLinked
{
    Node *head;

public:
    DoublyLinked()
    {
        head = NULL;
    }

    void insertStart(int data)
    {
        Node *nn = new Node(data);

        if (!head)
        {
            head = nn;
            nn->next = nn;
            nn->prev = nn;
        }
        else
        {
            head->prev->next = nn;
            nn->prev = head->prev;
            head->prev = nn;
            nn->next = head;
            head = nn;
        }
    }

    void display()
    {
        Node *temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void findIntersection(Node *head2)
    {
        if (!head || !head2)
            return;

        Node *temp1 = head, *temp2 = head2;

        do
        {
            do
            {
                if (temp1->data == temp2->data)
                {
                    cout << temp1->data << " ";
                }
                temp2 = temp2->next;
            } while (temp2 != head2);

            temp1 = temp1->next;
        } while (temp1 != head);
    }

    Node *getHead()
    {
        return head;
    }
};

int main()
{
    DoublyLinked d1, d2;

    d1.insertStart(5);
    d1.insertStart(4);
    d1.insertStart(3);
    d1.insertStart(2);
    d1.insertStart(1);
    d1.display();

    d2.insertStart(7);
    d2.insertStart(2);
    d2.insertStart(6);
    d2.insertStart(5);
    d2.insertStart(4);
    d2.insertStart(3);
    d2.display();

    d1.findIntersection(d2.getHead());

    return 0;
}