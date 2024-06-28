#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int data)
    {
        if (!head)
            head = new Node(data);
        else
        {
            Node *nn = new Node(data);

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

    void rearrange_list()
    {
        Node *curr = head, *prev = NULL, *latest = NULL;
        bool even_preceeds = false;

        while (curr)
        {
            if (curr->data % 2 == 1)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                if (latest)
                {
                    curr->next = latest->next;
                    latest->next = curr;
                    latest = curr;
                }
                else
                {
                    if (prev)
                        curr->next = head;
                    head = curr;
                    latest = curr;
                }
            }

            prev = curr;
            curr = curr->next;
        }
    }

    void search_promote(int key)
    {
        Node *curr = head, *prev = NULL, *latest = NULL;
        bool even_preceeds = false;

        while (curr)
        {
            if (curr->data == key)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                if (latest)
                {
                    curr->next = latest->next;
                    latest->next = curr;
                    latest = curr;
                }
                else
                {
                    if (prev)
                        curr->next = head;
                    head = curr;
                    latest = curr;
                }
            }

            prev = curr;
            curr = curr->next;
        }
    }
};

int main()
{
    LinkedList l1;
    l1.insert(6);
    l1.insert(5);
    l1.insert(3);
    l1.insert(3);
    l1.insert(1);
    l1.insert(4);
    l1.insert(2);
    l1.insert(2);
    l1.display();

    // l1.rearrange_list();
    l1.search_promote(3);
    l1.display();

    return 0;
}