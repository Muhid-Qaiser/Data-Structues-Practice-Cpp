#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *n = NULL) : data(data), next(n) {}
};

class CicularList
{
    Node *head;
    Node *tail;

public:
    CicularList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertStart(int data)
    {
        Node *nn = new Node(data);

        if (!head)
        {
            head = nn;
            nn->next = nn;
            tail = nn;
        }
        else
        {

            nn->next = head;
            head = nn;
            tail->next = nn;
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

    void split(int N)
    {
        int count = 0;
        int length = 0;
        Node *temp = head;

        do
        {
            length++;
            temp = temp->next;
        } while (temp != head);

        if (length == 0)
        {
            cout << "Circular linked list is empty." << endl;
            return;
        }

        int segSize = length / N;
        int remainder = length % N;
        temp = head;

        cout << "Splitting the circular linked list into " << N << " segments:" << endl;

        for (int i = 0; i < N; i++)
        {
            int currentSegSize = segSize + (i < remainder ? 1 : 0);

            cout << "Segment " << i + 1 << ": ";
            for (int j = 0; j < currentSegSize; j++)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    CicularList l;
    l.insertStart(5);
    l.insertStart(4);
    l.insertStart(3);
    l.insertStart(2);
    l.insertStart(1);
    l.display();

    l.split(3);

    return 0;
}