
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

class BinaryTree
{
private:
    int tree[MAX_SIZE];
    int size;

public:
    BinaryTree()
    {
        size = 0;
        for (int i = 0; i < MAX_SIZE; i++)
        {
            tree[i] = -1;
        }
    }

    void insert(int value)
    {
        if (size == MAX_SIZE)
        {
            cout << "Error: Tree is full" << endl;
            return;
        }

        tree[size] = value;
        size++;
    }

    bool search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (tree[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    bool isFull()
    {
        return size == MAX_SIZE;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void deleteNode(int value)
    {
        int index = -1;
        for (int i = 0; i < size; i++)
        {
            if (tree[i] == value)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Error: Value not found in tree" << endl;
            return;
        }

        // Replace the node with the last node in the tree
        tree[index] = tree[size - 1];
        tree[size - 1] = -1;
        size--;
    }

    void print()
    {
        int height = ceil(log2(size + 1));
        int index = 0;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < pow(2, i); j++)
            {
                if (index >= size)
                {
                    break;
                }

                cout << tree[index] << " ";
                index++;
            }
            cout << endl;
        }
    }

    int left(int index)
    {
        return ((2 * index) + 1);
    }

    int right(int index)
    {
        return ((2 * index) + 2);
    }
};

int main()
{
    BinaryTree b;

    b.insert(10);
    b.insert(5);
    b.insert(14);
    b.insert(11);
    b.insert(17);
    b.insert(1);
    b.insert(7);
    // b.printTree();
    b.print();
}
