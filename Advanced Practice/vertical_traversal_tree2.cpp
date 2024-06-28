#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Pair
{
public:
    TreeNode *node;
    int hd; // horizontal distance

    Pair(int hd, TreeNode *node) : hd(hd), node(node) {}
};

void findMinMaxHD(TreeNode *node, int hd, int &minHD, int &maxHD)
{
    if (node == NULL)
        return;

    minHD = min(minHD, hd);
    maxHD = max(maxHD, hd);

    findMinMaxHD(node->left, hd - 1, minHD, maxHD);
    findMinMaxHD(node->right, hd + 1, minHD, maxHD);
}

void verticalTraversal(TreeNode *root)
{
    int minHD = 0, maxHD = 0;
    findMinMaxHD(root, 0, minHD, maxHD);

    int vectorSize = maxHD - minHD + 1;
    vector<vector<int>> verticalOrder(vectorSize);

    queue<Pair> q;
    q.push(Pair(-minHD, root)); // -minHD is used to shift the horizontal distances to start from 0

    while (!q.empty())
    {
        Pair cur = q.front();
        q.pop();

        TreeNode *node = cur.node;
        int hd = cur.hd;

        verticalOrder[hd].push_back(node->val);

        if (node->left != NULL)
            q.push(Pair(hd - 1, node->left));

        if (node->right != NULL)
            q.push(Pair(hd + 1, node->right));
    }

    for (const auto &level : verticalOrder)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Vertical Traversal:\n";
    verticalTraversal(root);

    return 0;
}
