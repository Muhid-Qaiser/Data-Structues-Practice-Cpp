#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int d) : data(d)
    {
        prev = NULL;
        next = NULL;
    }
};

class DoublyCircularList
{
    Node *head;
    int size;

public:
    DoublyCircularList() : size(0)
    {
        head = NULL;
    }

    // ! Insertion
    void insert_start(int data)
    {
        Node *nn = new Node(data);

        if (head == NULL)
        {
            nn->prev = nn;
            nn->next = nn;
            head = nn;
        }
        else
        {
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;
            head = nn;
        }
        size++;
    }

    void insert_end(int data)
    {
        Node *nn = new Node(data);

        if (head == NULL)
        {
            nn->prev = nn;
            nn->next = nn;
            head = nn;
        }
        else
        {
            nn->next = head;
            nn->prev = head->prev;

            head->prev->next = nn;
            head->prev = nn;
        }
        size++;
    }

    void insert_location(int data, int pos)
    {
        Node *nn = new Node(data);

        if (head == NULL)
        {
            nn->prev = nn;
            nn->next = nn;
            head = nn;
        }
        else if (size < pos)
        {
            cout << "Out of bounds" << endl;
        }
        else if (pos == 1)
        {
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;

            head = nn;
        }
        else
        {
            Node *temp = head;

            for (int i = 2; i < pos; i++)
            {
                if (temp->next == head)
                    break;

                temp = temp->next;
            }

            nn->next = temp->next;
            nn->prev = temp;

            temp->next->prev = nn;
            temp->next = nn;
        }
        size++;
    }

    // ! Deletion
    void delete_start()
    {
        if (head == NULL)
        {
            cout << "List Empty" << endl;
        }
        else
        {
            Node *temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            delete temp;
        }
        size--;
    }

    void delete_end()
    {
        if (head == NULL)
        {
            cout << "List Empty" << endl;
        }
        else
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *temp = head;
                Node *temp2 = NULL;

                while (temp->next != head->prev)
                {
                    temp = temp->next;
                }

                temp2 = temp->next;
                temp->next = head;
                head->prev = temp;

                delete temp2;
            }
        }
        size--;
    }

    void delete_location(int pos)
    {

        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }
        else if (size < pos)
        {
            cout << "Out of bounds" << endl;
        }
        else if (pos == 1)
        {
            delete_start();
        }
        else
        {
            Node *temp = head;
            Node *temp2 = NULL;

            for (int i = 2; i < pos; i++)
            {
                if (temp->next == head)
                    break;

                temp = temp->next;
            }

            temp2 = temp->next;
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
            delete temp2;
        }
        size--;
    }

    void display_straight()
    {
        Node *temp = head;

        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << endl;
    }

    void display_reverse()
    {
        Node *temp = head;

        while (temp->prev != head)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << temp->data << " ";
        cout << endl;
    }

    Node *get_head()
    {
        return head;
    }

    void partition(int x)
    {
        Node *latest = NULL;
        Node *prev = head->prev;
        Node *curr = head;
        bool flag = true;

        do
        {
            if (curr->data < x && !latest)
            {
                if (!flag)
                {
                    prev->next = curr->next;
                    curr->next->prev = prev;
                    curr->next = head;
                    curr->prev = head->prev;
                    head->prev->next = curr;
                    head->prev = curr;

                    latest = curr;
                    head = curr;

                    prev = curr;
                    curr = curr->next;
                    flag = true;
                    continue;
                }
                else
                {
                    latest = curr;
                    head = curr;
                    prev = curr;
                    curr = curr->next;
                    flag = true;
                    continue;
                }
            }

            else if (curr->data < x)
            {
                if (!flag)
                {

                    prev->next = curr->next;
                    curr->next->prev = prev;
                    curr->next = latest->next;
                    curr->prev = latest;
                    latest->next = curr;
                }
                else
                {
                    latest = curr;
                    prev = curr;
                    curr = curr->next;
                    flag = true;
                    continue;
                }
            }
            prev = curr;
            curr = curr->next;
            flag = false;

        } while (curr != head);
    }
};

int main()
{
    DoublyCircularList l1;

    l1.insert_start(11);
    l1.insert_start(1);
    l1.insert_start(3);
    l1.insert_start(2);
    l1.insert_start(10);

    l1.display_straight();
    l1.partition(3);
    l1.display_straight();

    return 0;
}