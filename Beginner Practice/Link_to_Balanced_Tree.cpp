
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return new TreeNode(head->val);
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
    void displayTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        // In-order traversal: left, root, right
        displayTree(root->left);
        cout << root->val << " ";
        displayTree(root->right);
    }
};

int main()
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    Solution sol;
    TreeNode *root = sol.sortedListToBST(head);
    sol.displayTree(root);
    return 0;
}
