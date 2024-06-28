#include <iostream>
using namespace std;

class TwoStacksInOneArray
{
private:
    int max_size;
    int *array;
    int top1; // Top of the first stack
    int top2; // Top of the second stack

public:
    TwoStacksInOneArray(int size)
    {
        max_size = size;
        array = new int[max_size];
        top1 = -1;
        top2 = max_size;
    }

    ~TwoStacksInOneArray()
    {
        delete[] array;
    }

    // Push an element onto the first stack (Stack 1)
    void push1(int value)
    {
        if (top1 < top2 - 1)
        {
            array[++top1] = value;
        }
        else
        {
            std::cout << "Stack 1 is full. Cannot push." << std::endl;
        }
    }

    // Push an element onto the second stack (Stack 2)
    void push2(int value)
    {
        if (top1 < top2 - 1)
        {
            array[--top2] = value;
        }
        else
        {
            std::cout << "Stack 2 is full. Cannot push." << std::endl;
        }
    }

    // Pop an element from the first stack (Stack 1)
    int pop1()
    {
        if (top1 >= 0)
        {
            return array[top1--];
        }
        else
        {
            std::cout << "Stack 1 is empty. Cannot pop." << std::endl;
            return -1; // Return a default value for an empty stack
        }
    }

    // Pop an element from the second stack (Stack 2)
    int pop2()
    {
        if (top2 < max_size)
        {
            return array[top2++];
        }
        else
        {
            std::cout << "Stack 2 is empty. Cannot pop." << std::endl;
            return -1; // Return a default value for an empty stack
        }
    }

    void display()
    {
        for (int i = 0; i < max_size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

class TwoStackOneArray
{
    int max_size;
    int *array;
    int top1;
    int top2;

public:
    TwoStackOneArray(int m) : top1(-1), top2(m), array(), max_size(m)
    {
        array = new int[m];

        for (int i = 0; i < m; i++)
        {
            array[i] = 0;
        }
    }

    void push1(int data)
    {
        if (top1 + 1 < top2)
            array[++top1] = data;
        else
            cout << "Cant push1\n";
    }
    void push2(int data)
    {
        if (top2 - 1 > top1)
            array[--top2] = data;
        else
            cout << "Cant push2\n";
    }
    int pop1()
    {
        int val = array[top1];
        top1--;
        return val;
    }
    int pop2()
    {
        int val = array[top2];
        top2++;
        return val;
    }
    int Top1()
    {
        return array[top1];
    }
    int Top2()
    {
        return array[top2];
    }
    void display()
    {
        for (int i = 0; i < max_size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    TwoStackOneArray ts(10);

    ts.push1(1);
    ts.push1(2);
    ts.push1(3);

    ts.push2(10);
    ts.push2(9);
    ts.push2(8);

    ts.display();

    cout << ts.pop1() << " " << ts.pop2() << endl;

    //
    // TwoStacksInOneArray ts(10);
    // ts.push1(1);
    // ts.push1(2);
    // ts.push1(3);
    // ts.push2(10);
    // ts.push2(9);
    // ts.push2(8);
    // std::cout << "Pop from Stack 1: " << ts.pop1() << std::endl;
    // std::cout << "Pop from Stack 2: " << ts.pop2() << std::endl;
    // ts.display();

    return 0;
}
