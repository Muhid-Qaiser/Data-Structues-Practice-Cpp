#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a new node at the end of a linked list
void insertNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        ListNode *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// Function to rearrange the linked list
ListNode *rearrangeList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *oddHead = nullptr;  // Head of the list for odd values
    ListNode *evenHead = nullptr; // Head of the list for even values
    ListNode *current = head;

    while (current)
    {
        if (current->val % 2 == 1)
        { // Odd value
            insertNode(oddHead, current->val);
        }
        else
        { // Even value
            insertNode(evenHead, current->val);
        }
        current = current->next;
    }

    // Merge the odd list before the even list
    if (!oddHead)
    {
        return evenHead;
    }

    current = oddHead;
    while (current->next)
    {
        current = current->next;
    }
    current->next = evenHead;

    return oddHead;
}

int main()
{
    // Create a sample linked list
    ListNode *head = nullptr;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);

    std::cout << "Original Linked List: ";
    printList(head);

    head = rearrangeList(head);

    std::cout << "Rearranged Linked List: ";
    printList(head);

    return 0;
}
