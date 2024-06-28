#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to generate instructions for a postfix expression
void generateInstructions(string postfix)
{
    stack<string> tempVariables;
    int tempCount = 1;

    for (char c : postfix)
    {
        if (isalpha(c))
        {
            // If the character is a single-letter operand
            cout << "LD " << c << endl;
            tempVariables.push("AUX" + to_string(tempCount));
            cout << "ST " << tempVariables.top() << endl;
            tempCount++;
        }
        else if (isOperator(c))
        {
            // If the character is an operator
            string operand2 = tempVariables.top();
            tempVariables.pop();
            string operand1 = tempVariables.top();
            tempVariables.pop();

            // Generate the appropriate instruction based on the operator
            switch (c)
            {
            case '+':
                cout << "LD " << operand1 << endl;
                cout << "AD " << operand2 << endl;
                break;
            case '-':
                cout << "LD " << operand1 << endl;
                cout << "SB " << operand2 << endl;
                break;
            case '*':
                cout << "LD " << operand1 << endl;
                cout << "ML " << operand2 << endl;
                break;
            case '/':
                cout << "LD " << operand1 << endl;
                cout << "DV " << operand2 << endl;
                break;
            }

            // Store the result in a temporary variable
            tempVariables.push("AUX" + to_string(tempCount));
            cout << "ST " << tempVariables.top() << endl;
            tempCount++;
        }
    }
}

int main()
{
    string postfixExpression;

    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    generateInstructions(postfixExpression);

    return 0;
}
