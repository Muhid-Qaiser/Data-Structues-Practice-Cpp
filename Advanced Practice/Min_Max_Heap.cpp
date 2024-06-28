#include <iostream>
using namespace std;

class MinHeap
{
    int *array;
    int size;
    int capacity;

    int parent(int index)
    {
        return (index / 2);
    }

    int left(int index)
    {
        return (2 * index);
    }

    int right(int index)
    {
        return (2 * index) + 1;
    }

    void heapifyup(int index)
    {
        while (index > 1 && array[index] < array[parent(index)])
        {
            swap(array[index], array[parent(index)]);
            index = parent(index);
        }
    }

    void heapifydown(int index)
    {
        int smallest = index, l = left(index), r = right(index);

        if (l < size && array[l] < array[smallest])
        {
            smallest = l;
        }
        if (r < size && array[r] < array[smallest])
        {
            smallest = r;
        }

        if (smallest != index)
        {
            swap(array[smallest], array[index]);
            heapifydown(smallest);
        }
    }

public:
    MinHeap(int s)
    {
        capacity = s;
        size = 1;
        array = new int[size];
    }

    void insert(int data)
    {
        if (size == capacity + 1)
        {
            cout << "FUll\n";
            return;
        }
        else
        {
            array[size++] = data;
            heapifyup(size - 1);
        }
    }

    int extractMin()
    {
        if (size == 1)
        {
            cout << "Empty\n";
            return -1;
        }
        else
        {
            int ans = array[1];
            size--;
            array[1] = array[size];
            heapifydown(1);
            return ans;
        }
    }

    void display()
    {
        for (int i = 1; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap m1(10);
    m1.insert(10);
    m1.insert(3);
    m1.insert(14);
    m1.insert(1);
    m1.display();

    cout << m1.extractMin() << endl;
    m1.display();

    return 0;
}