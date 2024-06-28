#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList : public Node
{
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    Node *GetNewNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        return newNode;
    }

    // ! Insertion

    void insert_start(int data)
    {
        Node *newNode = GetNewNode(data);

        if (head == NULL)
            head = newNode;

        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insert_end(int data)
    {
        Node *newNode = GetNewNode(data);

        if (head == NULL)
            head = newNode;

        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
        size++;
    }

    void insert_after_index(int data, int index)
    {
        Node *newNode = GetNewNode(data);

        if (head == NULL)
            head = newNode;

        else if (index > size)
        {
            cout << "Index Out of Range!" << endl;
        }

        else
        {
            Node *temp = head;

            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void insert_after_value(int data, int val)
    {
        Node *newNode = GetNewNode(data);

        if (head == NULL)
            head = newNode;

        else
        {
            Node *temp = head;

            while (temp->data != val)
            {
                if (temp->next == NULL)
                {
                    cout << "Value Not Found!\n";
                    return;
                }

                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    // ! Deletion

    void delete_start()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;

            delete temp;
        }
        size--;
    }

    void delete_end()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;

            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            delete temp;
        }
        size--;
    }

    void delete_index(int index)
    {
        if (head == NULL)
        {
            return;
        }
        else if (index == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else if (index > size)
        {
            cout << "Index out of Range!" << endl;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;

            for (int i = 1; i < index; i++)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            delete temp;
        }
        size--;
    }

    void delete_value(int val)
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;

            while (temp->data != val)
            {
                if (temp->next == NULL)
                {
                    cout << "Value not Found!" << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
        size--;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int get_size()
    {
        return size;
    }

    int get_middle_value()
    {
        Node *temp = head;
        for (int i = 0; i < (size / 2); i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void rearrange_list_util(Node *node, Node *prev, Node *latest, bool &flag)
    {
        if (!node)
            return;

        if (node->data % 2 == 0)
        {
            flag = true;
            prev = node;
            node = node->next;
        }
        else if (node->data % 2 != 0 && flag)
        {
            prev->next = node->next;

            if (latest)
            {
                node->next = latest->next;
                latest->next = node;
                latest = node;
                node = prev->next;
            }
            else
            {
                node->next = head;
                head = node;
                latest = node;
                node = prev->next;
            }
        }
        else
        {
            latest = node;
        }

        rearrange_list_util(node, prev, latest, flag);
    }

    void rearrange_list()
    {
        bool flag = false;
        rearrange_list_util(head, NULL, NULL, flag);
    }
};

int main()
{
    LinkedList l1;
    // l1.insert_end(3);
    l1.insert_end(2);
    l1.insert_end(2);
    l1.insert_end(3);
    l1.insert_end(1);
    l1.insert_end(3);
    l1.insert_end(4);
    l1.insert_end(5);
    l1.insert_end(6);
    l1.display();

    l1.rearrange_list();
    l1.display();

    return 0;
}
