#include <iostream>

// Definition of a singly linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindromeRecursive(ListNode *&left, ListNode *right)
{
    if (right == nullptr)
    {
        return true;
    }

    bool isPal = isPalindromeRecursive(left, right->next);

    if (!isPal || left->val != right->val)
    {
        return false;
    }

    left = left->next;
    return true;
}

bool isPalindrome(ListNode *head)
{
    return isPalindromeRecursive(head, head);
}

int main()
{
    // Create a linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head))
    {
        std::cout << "The linked list is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Clean up memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
