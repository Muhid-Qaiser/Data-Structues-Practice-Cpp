#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data)
    {
        next = NULL;
        prev = NULL;
    }
};

class ReverseLinkedList
{
    Node *head;

public:
    ReverseLinkedList()
    {
        head = NULL;
    }

    // ! Insertion
    void insertStart(int data)
    {
        if (head == NULL)
        {
            Node *nn = new Node(data);
            head = nn;
            nn->next = nn;
            nn->prev = nn;
        }
        else
        {
            Node *nn = new Node(data);
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;
            head = nn;
        }
    }

    void insertEnd(int data)
    {
        if (head == NULL)
        {
            Node *nn = new Node(data);
            head = nn;
            nn->next = nn;
            nn->prev = nn;
        }
        else
        {
            Node *nn = new Node(data);
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;
        }
    }

    void insertLocation(int data, int pos, int count = 1, Node *node = NULL)
    {
        if (node == NULL && count == 1)
        {
            node = head;
        }
        else if (node == head)
        {
            cout << "Position Node FOund\n";
            return;
        }

        if (head == NULL)
        {
            cout << "List Empty" << endl;
        }
        else if (pos < 1 || (count > 1 && node == NULL))
        {
            cout << "INvalid ENtry" << endl;
        }
        else if (pos == 1)
        {
            insertStart(data);
        }
        else if (count == pos - 1)
        {
            Node *nn = new Node(data);
            nn->next = node->next;
            nn->prev = node;
            node->next->prev = nn;
            node->next = nn;
        }
        else
            insertLocation(data, pos, count + 1, node->next);
    }

    void insertAfterValue(int data, int val, Node *node = NULL, bool flag = true)
    {
        if (node == NULL && flag)
        {
            node = head;
        }
        else if (node == NULL)
        {
            cout << "Position Node Not Found" << endl;
            return;
        }

        if (head == NULL)
        {
            cout << "Empty List!" << endl;
        }
        else if (node->data == val)
        {
            Node *nn = new Node(data);
            nn->next = node->next;
            node->next = nn;
        }
        else
            insertAfterValue(data, val, node->next, false);
    }

    // ! Deletion
    void deleteStart()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }
        else if (head->next == head)
        {
            head->next = NULL;
            head->prev = NULL;
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }
        else if (head->next == head)
        {
            head->next = NULL;
            head->prev = NULL;
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head->prev;
            head->prev->prev->next = head;
            head->prev = head->prev->prev;

            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    void deleteLocation(int pos, int count = 1, Node *node = NULL)
    {
        if (node == NULL && count == 1)
        {
            node = head;
        }
        else if (node->next == head)
        {
            cout << "Position Not Found!" << endl;
            return;
        }

        if (head == NULL)
        {
            cout << "Empty List!" << endl;
        }
        else if (pos < 1 || (count > 1 && node == NULL))
        {
            cout << "Invalid Position!" << endl;
        }
        else if (pos == 1)
        {
            deleteStart();
        }
        else if (count == pos - 1)
        {
            Node *temp = node->next;

            node->next->next->prev = node;
            node->next = node->next->next;

            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        else
            deleteLocation(pos, count + 1, node->next);
    }

    void deleteValue(int val, Node *node = NULL, bool flag = true)
    {
        if (node == NULL && flag)
        {
            node = head;
        }
        else if (node->next == NULL)
        {
            cout << "Value Not Found" << endl;
            return;
        }

        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }
        else if (head->data == val)
        {
            deleteStart();
        }
        else if (node->next->data == val)
        {
            Node *temp = node->next;
            node->next = node->next->next;

            temp->next = NULL;
            delete temp;
        }
        else
            deleteValue(val, node->next, false);
    }

    // Recursive function to display the linked list
    void displayRecursive(Node *current)
    {
        if (current == head->prev)
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
        if (head == NULL)
            cout << "Empty List" << endl;

        else
        {
            displayRecursive(head);
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
    // l1.display();

    l1.insertEnd(4);
    // l1.display();

    l1.insertLocation(5, 5);
    l1.display();

    // l1.insertAfterValue(5, 2);
    // l1.display();

    l1.deleteStart();
    l1.display();

    l1.deleteEnd();
    l1.display();

    l1.deleteLocation(2);
    l1.display();

    // l1.deleteValue(3);
    // l1.display();

    return 0;
}