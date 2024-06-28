#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d, Node *l = NULL, Node *r = NULL) : data(d), left(l), right(r) {}
};

class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void Enqueue(int data)
    {
        Node *nn = new Node(data);

        if (!head)
        {
            head = nn;
            tail = nn;
            nn->left = nn;
            nn->right = nn;
        }
        else
        {
            nn->right = head;
            head->left = nn;
            tail->right = nn;
            nn->left = tail;
            tail = nn;
        }
        size++;
    }

    void Dequeue()
    {
        if (!head)
            cout << "empty!\n";

        else if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->right;
            tail->right = head;
            head->left = tail;
            temp->right = NULL;
            temp->left = NULL;
            delete temp;
        }
        size--;
    }

    void display()
    {
        Node *temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->right;
        } while (temp != head);
        cout << endl;
    }

    bool isEmpty()
    {
        return head && tail;
    }

    int top()
    {
        return head->data;
    }

    int getSize()
    {
        return size;
    }
};

void Scheduler()
{
    Queue q;
    q.Enqueue(7);
    q.Enqueue(6);
    q.Enqueue(5);

    int total = q.getSize(), count = 0;

    q.display();

    while (q.isEmpty())
    {
        int n = q.top();
        q.Dequeue();

        if ((n - 3) >= 0)
        {
            n -= 3;
            cout << "3 instructions removed from p" << count << endl;
        }
        else if ((n - 2) >= 0)
        {
            n -= 2;
            cout << "2 instructions removed from p" << count << endl;
        }
        else if ((n - 1) >= 0)
        {
            n -= 1;
            cout << "1 instructions removed from p" << count << endl;
        }

        if (n == 0)
        {
            cout << "p" << count << " has finished!\n";
            count = (count + 1) % total;
            total--;
            continue;
        }
        else
        {
            q.Enqueue(n);
        }
        count = (count + 1) % total;
    }
}

int main()
{
    Scheduler();

    return 0;
}