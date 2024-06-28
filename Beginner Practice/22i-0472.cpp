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

        else if (index == 0)
        {
            newNode->next = head;
            head = newNode;
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

    // ! Reverse ting
    Node *reverse_recursive_util(Node *node, Node *prev)
    {
        if (node->next == NULL)
        {
            head = node;
            node->next = prev;
            return NULL;
        }

        reverse_recursive_util(node->next, node);

        node->next = prev;
        return node;
    }

    void reverse_recursive()
    {
        reverse_recursive_util(head, NULL);
    }

    // ! Palindrome ting
    int check_palindrome_util2(Node *node, int n)
    {
        if (n == size - 1)
        {
            return node->data;
        }

        return check_palindrome_util2(node->next, n + 1);
    }

    bool check_palindrome_util1(Node *node, int n)
    {
        if (n > size / 2)
            return true;

        if (node->data == check_palindrome_util2(node, n))
        {
            return check_palindrome_util1(node->next, n + 2);
        }
        return false;
    }

    bool check_palindrome()
    {
        return check_palindrome_util1(head, 0);
    }

    bool check_palindrome2()
    {
        Node *temp = head;

        // Create a copy of the original linked list
        LinkedList originalList;
        while (temp != nullptr)
        {
            originalList.insert_end(temp->data);
            temp = temp->next;
        }

        // Reverse the copy
        originalList.reverse_recursive();

        // Compare the original and reversed lists
        temp = head;
        Node *temp2 = originalList.head;

        while (temp != nullptr && temp2 != nullptr)
        {
            if (temp->data != temp2->data)
            {
                cout << "Not a palindrome" << endl;
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        cout << "Palindrome" << endl;
        return true;
    }

    bool check_palindrome3_util(Node *right, Node *&left)
    {
        if (!right)
            return true;

        check_palindrome3_util(right->next, left);

        if (right->data != left->data)
        {
            return false;
        }

        left = left->next;

        return true;
    }

    bool check_palindrome3()
    {
        Node *left = head;
        return check_palindrome3_util(head, left);
    }

    // ! Rearrange, odd first, even last
    Node *rearrange_list_util(Node *node, Node *prev, bool flag)
    {
        if (node->next == NULL && flag && node->data % 2 == 0)
        {
            prev->next = NULL;
            cout << prev->data << endl;
            return node;
        }
        else if (node == NULL)
            return NULL;

        else if (!flag && node->data % 2 != 0 && node->next->data % 2 == 0)
        {
            Node *temp = node->next;
            node->next = rearrange_list_util(node->next, node, false);
            node->next->next = temp;
            rearrange_list_util(node->next, node, false);
        }
        else if (flag && node->data % 2 != 0)
        {
            prev->next = node->next;
            return node;
        }
        else if (node->data % 2 == 0)
        {
            return rearrange_list_util(node->next, node, true);
        }
        else
            return rearrange_list_util(node->next, node, false);
    }

    /*
        Node *rearrange_list_util2(Node *node, Node *prev, Node *lo, bool flag)
        {
            if (node == NULL)
                return NULL;

            else if (lo == NULL && node->data % 2 == 0)
            {
                if (node->next->data % 2 != 0)
                {
                    Node *temp = node->next;
                    node->next = node->next->next;
                    temp->next = head;
                    head = temp;
                    lo = temp;
                    rearrange_list_util2(node->next, node, lo, true);
                }
                else
                    rearrange_list_util2(node->next, prev, lo, true);
            }
            else if (lo == NULL && prev == NULL && node->data % 2 != 0)
            {
            }

            else if (prev == NULL && node->data % 2 != 0)
            {
                lo = node;
            }
            else if (node->data % 2 == 0)
            {
                rearrange_list_util2(node->next, node, lo, true);
            }
            else if (node->data % 2 != 0 && flag)
            {
                Node *temp = node;
                prev->next = node->next;
                node->next = lo->next;
                lo->next = node;
                lo = node;
                rearrange_list_util2(prev->next, prev, lo, false);
            }
            else if (node->data % 2 != 0)
            {
                lo = node;
            }
            rearrange_list_util2(node->next, node, lo, false);
        }
    */

    Node *rearrange_list_util2(Node *node, Node *prev, Node *lo, bool flag)
    {
        if (node == nullptr)
            return nullptr;

        if (lo == nullptr && node->data % 2 == 0)
        {
            if (node->next && node->next->data % 2 != 0)
            {
                Node *temp = node->next;
                node->next = temp->next;
                temp->next = head;
                head = temp;
                lo = temp;
                rearrange_list_util2(node->next, node, lo, true);
            }
        }
        else if (lo == nullptr && prev == nullptr && node->data % 2 != 0)
        {
            lo = node;
        }
        else if (prev == nullptr && node->data % 2 != 0)
        {
            lo = node;
        }
        else if (node->data % 2 == 0)
        {
            rearrange_list_util2(node->next, node, lo, true);
        }
        else if (node->data % 2 != 0 && flag)
        {
            Node *temp = node;
            prev->next = node->next;
            node->next = lo->next;
            lo->next = node;
            lo = node;
            rearrange_list_util2(prev->next, prev, lo, true);
        }
        else if (node->data % 2 != 0)
        {
            lo = node;
        }
        return rearrange_list_util2(node->next, node, lo, false);
    }

    void rearrange_list()
    {
        rearrange_list_util2(head, NULL, NULL, false);
    }
};

int main()
{
    LinkedList l1;
    l1.insert_end(2);
    l1.insert_end(2);
    l1.insert_end(1);
    l1.insert_end(7);
    l1.insert_end(1);
    l1.insert_end(2);
    l1.insert_end(2);
    l1.display();
    // l1.insert_after_index(3, 5);

    // l1.reverse_recursive();

    // l1.display();

    // cout << l1.check_palindrome2() << endl;

    l1.rearrange_list();
    l1.display();

    return 0;
}
