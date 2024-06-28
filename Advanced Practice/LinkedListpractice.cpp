#include <iostream>
using namespace std;

// ! Singly Linked

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr){};
};

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insert_start(int data)
    {
        if (!head)
        {
            head = new Node(data);
        }
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

    void rotate(int n)
    {
        Node *tail = head, *temp = NULL;

        while (n)
        {
            while (tail->next->next)
                tail = tail->next;

            temp = tail;
            tail = tail->next;
            tail->next = head;
            head = tail;
            temp->next = NULL;
            n--;
        }
    }

    void reverse(int m, int n)
    {
        int size = 0;
        Node *curr = head, *prev = head, *lastReversed = NULL;

        while (curr)
        {
            size++;
            curr = curr->next;
        }

        for (int i = 0; i < m && prev; i++)
        {
            lastReversed = prev;
            prev = prev->next;
        }

        curr = prev->next;

        for (int i = m; i < n && curr; i++)
        {
            Node *nextNode = curr->next;
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

    Node *getNode(int index)
    {
        Node *temp = head;

        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    bool binarySearch(int key)
    {
        int left = 0, right = 0, size = 0, middle = 0;
        Node *temp = head, *node = NULL;

        while (temp)
        {
            size++;
            temp = temp->next;
        }

        right = size - 1;

        for (int i = 0; i < size; i++)
        {
            middle = (left + right) / 2;

            node = getNode(middle);

            if (node->data == key)
                return true;

            else if (node->data < key)
            {
                right = middle + 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return false;
    }
};

void singlyQs()
{
    SinglyLinkedList l1;

    l1.insert_start(5);
    l1.insert_start(4);
    l1.insert_start(3);
    l1.insert_start(2);
    l1.insert_start(1);
    l1.display();
    // l1.rotate(6);
    // l1.reverse(1, 3);
    cout << l1.binarySearch(0) << endl;
    l1.display();
}

// ! Circular Doubly Linked

struct DoublyNode
{
    int data;
    DoublyNode *next;
    DoublyNode *prev;

    DoublyNode(int data) : data(data), next(nullptr), prev(nullptr){};
};

class CircularDoublyLinkedList
{
    DoublyNode *head;

public:
    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    void insert_start(int data)
    {
        if (!head)
        {
            head = new DoublyNode(data);
            head->next = head;
            head->prev = head;
        }
        else
        {
            DoublyNode *nn = new DoublyNode(data);
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;
            head = nn;
        }
    }

    void display()
    {
        DoublyNode *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    DoublyNode *getHead()
    {
        return head;
    }
};

void findIntersection(CircularDoublyLinkedList d1, CircularDoublyLinkedList d2)
{
    DoublyNode *temp1 = d1.getHead(), *temp2 = d2.getHead();

    do
    {
        do
        {
            if (temp2->data == temp1->data)
                cout << temp1->data << " ";

            temp2 = temp2->next;
        } while (temp2 != d2.getHead());

        temp1 = temp1->next;
    } while (temp1 != d1.getHead());
}

void doublyQs()
{
    CircularDoublyLinkedList d1, d2;

    d1.insert_start(5);
    d1.insert_start(4);
    d1.insert_start(3);
    d1.insert_start(2);
    d1.insert_start(1);

    d2.insert_start(5);
    d2.insert_start(4);
    d2.insert_start(2);

    findIntersection(d1, d2);
}

// ! Circular Singly Linked

class CircularSinglyLinkedList
{
    Node *tail;

public:
    CircularSinglyLinkedList()
    {
        tail = nullptr;
    }

    void insert_start(int data)
    {
        if (!tail)
        {
            tail = new Node(data);
            tail->next = tail;
        }
        else
        {
            Node *nn = new Node(data);
            nn->next = tail->next;
            tail->next = nn;
        }
    }

    void display()
    {
        Node *temp = tail->next;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);

        cout
            << endl;
    }

    Node *getHead()
    {
        return tail;
    }

    void split(int n)
    {
        int size = 0;
        Node *temp = tail->next;

        do
        {
            temp = temp->next;
            size++;
        } while (temp != tail->next);

        int segments = size / n, remainder = size % n;

        for (int i = 0; i < n; i++)
        {
            int curr_seg = segments + ((i < remainder) ? 1 : 0);

            for (int j = 0; j < curr_seg; j++)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

void circularsinglyQs()
{
    CircularSinglyLinkedList l1;

    l1.insert_start(5);
    l1.insert_start(4);
    l1.insert_start(3);
    l1.insert_start(2);
    l1.insert_start(1);
    l1.display();

    l1.split(3);
}

int main()
{
    singlyQs();
    // doublyQs();
    // circularsinglyQs();

    return 0;
}