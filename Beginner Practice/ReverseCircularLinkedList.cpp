#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data)
    {
        next = NULL;
    }
};

class ReverseLinkedList
{
    Node *tail;

public:
    ReverseLinkedList()
    {
        tail = NULL;
    }

    // ! Insertion
    void insertStart(int data)
    {
        if (tail == NULL)
        {
            Node *nn = new Node(data);
            tail = nn;
            nn->next = nn;
        }
        else
        {
            Node *nn = new Node(data);
            nn->next = tail->next;
            tail->next = nn;
        }
    }

    void insertEnd(int data)
    {
        if (tail == NULL)
        {
            Node *nn = new Node(data);
            tail = nn;
            nn->next = nn;
        }
        else
        {
            Node *nn = new Node(data);
            nn->next = tail->next;
            tail->next = nn;
            tail = nn;
        }
    }

    void insertLocation(int data, int pos, int count = 1, Node *node = NULL)
    {
        if (node == NULL && count == 1)
        {
            node = tail->next;
        }
        else if (node == tail->next)
        {
            cout << "Location Not Found" << endl;
            return;
        }

        if (tail == NULL)
        {
            cout << "Empty List" << endl;
        }
        else if (pos < 1 || (count > 1 && node == NULL))
        {
            cout << "Invalid Location" << endl;
        }
        else if (pos == 1)
        {
            insertStart(data);
        }
        else if (count == pos - 1)
        {
            Node *nn = new Node(data);
            nn->next = node->next;
            node->next = nn;

            if (node == tail)
            {
                tail = nn;
            }
        }
        else
            insertLocation(data, pos, count + 1, node->next);
    }

    void insertAfterValue(int data, int val, Node *node = NULL, bool flag = true)
    {
    }

    // ! Deletion
    void deleteStart()
    {
        if (tail == NULL)
        {
            cout << "Empty tail!" << endl;
        }
        else
        {
            Node *temp = tail->next;
            tail->next = tail->next->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteEnd(Node *node = NULL)
    {
        if (node == NULL)
        {
            node = tail->next;
        }

        if (tail == NULL)
        {
            cout << "Empty tail!" << endl;
        }
        else if (tail->next == tail)
        {
            tail->next = NULL;
            delete tail;
            tail = NULL;
        }
        else if (node->next == tail)
        {
            node->next = tail->next;
            tail->next = NULL;
            delete tail;
            tail = node;
        }
        else
            deleteEnd(node->next);
    }

    void deleteLocation(int pos, int count = 1, Node *node = NULL)
    {

        if (tail == NULL)
        {
            cout << "Empty List" << endl;
        }
        else if (node == NULL && count == 1)
        {
            node = tail->next;
        }
        else if (node == tail->next)
        {
            cout << "Location Not Found" << endl;
            return;
        }

        if (pos < 1 || (count > 1 && node == NULL))
        {
            cout << "Invalid Location" << endl;
        }
        else if (pos == 1)
        {
            deleteStart();
        }
        else if (count == pos - 1)
        {
            Node *temp = node->next;
            node->next = temp->next;

            if (temp == tail)
            {
                tail = node;
            }

            temp->next = NULL;
            delete temp;
        }
        else
            deleteLocation(pos, count + 1, node->next);
    }

    void deleteValue(int val, Node *node = NULL, bool flag = true)
    {
    }

    // Recursive function to display the linked list
    void displayRecursive(Node *current)
    {
        if (current == tail)
        {
            cout << current->data << " ";
            return; // Base case, end of the list
        }

        cout << current->data << " ";
        displayRecursive(current->next);
    }

    // Wrapper function to start the recursive display
    void display()
    {
        if (tail == NULL)
            cout << "empty tail" << endl;
        else
        {
            displayRecursive(tail->next);
            cout << endl;
        }
    }
};

int main()
{
    ReverseLinkedList l1;

    l1.insertStart(1);
    l1.insertStart(2);
    l1.insertStart(3);
    l1.display();

    l1.insertEnd(4);
    l1.display();

    l1.insertLocation(5, 4);
    l1.display();

    // l1.deleteStart();
    // l1.display();

    // l1.deleteEnd();
    // l1.display();

    // l1.deleteLocation(8);
    // l1.display();

    // l1.deleteValue(3);
    // l1.display();s

    return 0;
}