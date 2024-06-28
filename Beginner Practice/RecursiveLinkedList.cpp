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
        }
        else
        {
            Node *nn = new Node(data);
            nn->next = head;
            head = nn;
        }
    }

    void insertEnd(int data, Node *node = NULL)
    {
        if (node == NULL)
        {
            node = head;
        }

        if (head == NULL)
        {
            Node *nn = new Node(data);
            head = nn;
        }
        else if (node->next == NULL)
        {
            Node *nn = new Node(data);
            node->next = nn;
        }
        else
            insertEnd(data, node->next);
    }

    void insertLocation2(int data, int pos, int count = 1, Node *node = NULL)
    {
        if (node == NULL && count == 1)
        {
            node = head;
        }
        else if (node == NULL)
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
            Node *nn = new Node(data);
            nn->next = head;
            head = nn;
        }
        else if (count == pos - 1)
        {
            Node *nn = new Node(data);
            nn->next = node->next;
            node->next = nn;
        }
        else
            insertLocation2(data, pos, count + 1, node->next);
    }

    void insertLocation(int data, int pos, Node *current = nullptr, int count = 1)
    {
        if (pos < 1)
        {
            cout << "Invalid Entry" << endl;
            return;
        }

        if (pos == 1 || head == nullptr)
        {
            Node *nn = new Node(data);
            nn->next = head;
            head = nn;
            return;
        }

        if (current == nullptr)
            current = head;

        if (count < pos - 1 && current->next != nullptr)
        {
            insertLocation(data, pos, current->next, count + 1);
        }
        else if (count == pos - 1)
        {
            Node *nn = new Node(data);
            nn->next = current->next;
            current->next = nn;
        }
        else
        {
            cout << "Position Node Not Found" << endl;
        }
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
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteEnd(Node *node = NULL)
    {
        if (node == NULL)
        {
            node = head;
        }

        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            Node *temp = head;
            delete temp;
            head = NULL;
        }
        else if (node->next->next == NULL)
        {
            Node *temp = node->next;
            node->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
            deleteEnd(node->next);
    }

    void deleteLocation(int pos, int count = 1, Node *node = NULL)
    {
        if (node == NULL && count == 1)
        {
            node = head;
        }
        else if (node->next == NULL)
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
            node->next = node->next->next;
            temp->next = NULL;
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
        if (current == nullptr)
        {
            return; // Base case, end of the list
        }

        cout << current->data << " ";
        displayRecursive(current->next);
    }

    // Wrapper function to start the recursive display
    void display()
    {
        displayRecursive(head);
        cout << endl;
    }
};

int main()
{
    ReverseLinkedList l1;

    l1.insertStart(1);
    l1.insertStart(2);
    l1.insertStart(3);
    l1.display();

    l1.insertLocation2(4, 3);
    l1.display();

    // l1.insertAfterValue(5, 2);
    // l1.display();

    // l1.deleteStart();
    // l1.display();

    // l1.deleteEnd();
    // l1.display();

    l1.deleteLocation(0);
    l1.display();

    l1.deleteValue(3);
    l1.display();

    return 0;
}