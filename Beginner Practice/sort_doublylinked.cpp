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

    void sort()
    {
        Node *temphead = head;
        Node *temp1 = head->next;
        Node *temp2 = temphead;
        Node *prev = NULL;
        Node *nextnode = NULL;

        temp2->next = temp2;
        temp2->prev = temp2;

        while (temp1 != head)
        {
            prev = temphead->prev;
            temp2 = temphead;

            if (temp1->data <= temp2->data)
            {
                temphead = temp1;
            }
            else
            {
                while (temp1->data > temp2->data && temp2->next != temp2)
                {
                    prev = temp2;
                    temp2 = temp2->next;
                }
            }

            nextnode = temp1->next;
            temp1->prev = prev;
            temp1->next = temp2;
            prev->next = temp1;
            temp2->prev = temp1;
            temp1 = nextnode;
        }
        head = temphead;
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void sort2()
    {
        Node *lptr = NULL, *curr = head;
        bool flag = true;

        while (flag)
        {
            flag = false;
            curr = head;

            while (curr != lptr)
            {
                if (curr->data > curr->next->data)
                {
                    swap(curr->data, curr->next->data);
                    flag = true;
                }
                curr = curr->next;
            }
            lptr = curr;
        }
    }
};

int main()
{
    DoublyCircularList l1;

    l1.insert_start(1);
    l1.insert_start(5);
    l1.insert_start(3);
    l1.insert_start(7);
    l1.insert_start(6);

    l1.display_straight();

    l1.sort();
    l1.display_straight();

    return 0;
}