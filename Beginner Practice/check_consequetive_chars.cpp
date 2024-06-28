#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class LinkedList : public Node
{
public:
    Node *head;
    int size;

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

    void insert_start(char data)
    {
        if (head == NULL)
        {
            head = GetNewNode(data);
            return;
        }
        Node *nn = GetNewNode(data);
        nn->next = head;
        head = nn;
    }

    // ! Insertion
    void insert_after(Node *ptr, char data)
    {
        if (ptr != NULL)
        {
            Node *newNode = GetNewNode(data);
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }

    // ! Deletion
    void delete_after(Node *ptr)
    {
        if (ptr != NULL)
        {
            Node *newNode = ptr->next;
            ptr->next = newNode->next;
            newNode->next = NULL;
            delete newNode;
        }
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

    // ! check consequetive chars
    void eq_occ2(char c, int num)
    {
        Node *prev = NULL;
        Node *curr = head;

        int count = 0;

        while (curr != NULL)
        {
            if (curr->data == c)
            {
                count++;
                if (count > num)
                {
                    Node *temp = curr;
                    prev->next = curr->next;
                    curr = curr->next;
                    delete temp;
                    continue; // Skip the rest of the loop for this iteration
                }
            }
            else
            {
                count = 0;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    void eq_occ(char c, int num)
    {
        int count = 0;
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            if (curr->data == c && count < num)
            {
                if (curr->next->data != c && count < num - 1)
                {
                    insert_after(curr, c);
                }
                count++;
            }
            else if (curr->data == c && count >= num)
            {
                delete_after(prev);
                curr = prev->next;
                continue;
            }
            else
            {
                count = 0;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // ! Reverse ting
    void reverse_recursive_util(Node *node, Node *prev)
    {
        if (node->next == NULL)
        {
            head = node;
            node->next = prev;
            return;
        }

        reverse_recursive_util(node->next, node);

        node->next = prev;
    }

    void reverse_recursive()
    {
        reverse_recursive_util(head, NULL);
    }

    // ! Palindrome ting
    int check_palindrome_util2(Node *node, int n)
    {
        if (n == size - 1)
            return node->data;

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

    // ! Rearrange, odd first, even last
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
    l1.insert_start('a');
    l1.insert_start('c');
    l1.insert_start('c');
    l1.insert_start('a');
    l1.insert_start('c');
    l1.insert_start('c');
    l1.insert_start('c');
    l1.insert_start('a');
    l1.insert_start('c');
    // l1.insert_start('c');
    // l1.insert_start('c');
    // l1.insert_start('c');
    l1.display();
    l1.eq_occ('c', 2);
    l1.display();

    return 0;
}
