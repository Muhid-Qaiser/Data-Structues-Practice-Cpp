
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

int tree[MAX_SIZE];

bool isPerfect(int size)
{
    int depth = log2(size + 1);            // calculate the depth of the tree
    int expectedNodes = pow(2, depth) - 1; // calculate the expected number of nodes
    return size == expectedNodes;          // check if the actual number of nodes matches the expected number
}

int main()
{
    // Example usage
    int size = 3;
    tree[0] = 1;
    tree[1] = 2;
    tree[2] = 3;
    // tree[3] = 4;
    // tree[4] = 5;
    // tree[5] = 6;
    // tree[6] = 7;

    if (isPerfect(size))
    {
        cout << "The binary tree is perfect." << endl;
    }
    else
    {
        cout << "The binary tree is not perfect." << endl;
    }

    return 0;
}
