#include <iostream>
#include <stack>
#include <string>

struct TreeNode
{
    std::string value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const std::string &val) : value(val), left(nullptr), right(nullptr) {}
};

bool isOperator(const std::string &s)
{
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int evaluateExpression(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    if (!isOperator(root->value))
    {
        // If the node is a leaf (an operand), convert it to an integer and return.
        return std::stoi(root->value);
    }

    // Recursively evaluate the left and right subtrees.
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    // Apply the operator at the current node.
    if (root->value == "+")
    {
        return leftValue + rightValue;
    }
    else if (root->value == "-")
    {
        return leftValue - rightValue;
    }
    else if (root->value == "*")
    {
        return leftValue * rightValue;
    }
    else if (root->value == "/")
    {
        return leftValue / rightValue; // Assuming no division by zero.
    }

    return 0; // Invalid operator or other error.
}

int main()
{
    // Create an expression tree for the expression "3 * (4 + 5)".
    TreeNode *root = new TreeNode("*");
    root->left = new TreeNode("3");
    root->right = new TreeNode("+");
    root->right->left = new TreeNode("4");
    root->right->right = new TreeNode("5");

    int result = evaluateExpression(root);

    std::cout << "Result: " << result << std::endl;

    // Clean up memory (assuming you're done with the tree).
    // TODO: Implement functions to delete the tree nodes and free memory.

    return 0;
}
