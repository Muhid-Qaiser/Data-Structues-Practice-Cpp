#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert a node at the end of the doubly linked list
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Reverse the doubly linked list in-place
    void reverse()
    {
        if (!head || head == tail)
        {
            return;
        }

        Node *current = head;
        Node *temp = nullptr;

        while (current)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Swap head and tail pointers
        temp = head;
        head = tail;
        tail = temp;
    }

    // Add 1 to the doubly linked list representing an integer
    void addOne()
    {
        reverse();

        Node *current = head;
        int carry = 1;

        while (current)
        {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;
            if (!current->next && carry)
            {
                // Add a new node for any remaining carry
                current->next = new Node(carry);
                current->next->prev = current;
            }
            current = current->next;
        }

        reverse();
    }

    // Display the doubly linked list
    void display()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    // Insert elements into the doubly linked list (e.g., representing 321)
    list.insert(1);
    list.insert(2);
    list.insert(3);

    cout << "Original Doubly Linked List:" << endl;
    list.display();

    list.addOne();

    cout << "Doubly Linked List after adding 1:" << endl;
    list.display();

    return 0;
}
