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

    void reverse()
    {
        Node *nextNode = NULL, *prev = NULL, *curr = NULL;

        curr = head;

        while (curr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    void reverse_N(int m, int n)
    {
        if (m < 0 || n <= 0 || m >= n)
        {
            cout << "Invalid range\n";
            return;
        }

        Node *nextNode = NULL, *prev = NULL, *curr = NULL, *lastReversed = NULL;
        int size = 0;

        curr = head;

        while (curr)
        {
            curr = curr->next;
            size++;
        }

        curr = head;
        prev = head;

        // Move to the node before the sub-list
        for (int i = 0; i < m && prev; i++)
        {
            lastReversed = prev;
            prev = prev->next;
        }

        if (!prev)
            return;

        curr = prev->next;

        for (int i = m; i < n && curr; i++)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        if (lastReversed)
        {
            lastReversed->next->next = curr;
            lastReversed->next = prev;
        }
        else
        {
            head->next = curr;
            head = prev;
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

    l.reverse_N(1, 3);
    l.display();

    return 0;
}
