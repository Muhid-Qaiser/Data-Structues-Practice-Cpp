#include <iostream>
using namespace std;

// ! Min Heap

class MyMinHeap
{
private:
    int *heap;
    int size;
    int count;

    int parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return 2 * i + 2; }

public:
    MyMinHeap(int);
    ~MyMinHeap();
    void Insert(int);
    void HeapifyDown(int);
    void HeapifyUp(int);
    void Display();
    int Delete();
};

MyMinHeap::MyMinHeap(int s)
{
    this->count = 0;
    this->size = s;
    this->heap = new int[size];
}

MyMinHeap::~MyMinHeap()
{
    delete[] heap;
}

void MyMinHeap::Insert(int data)
{
    if (count < size)
    {
        heap[count] = data;
        count++;
        HeapifyUp(count - 1);
    }
    else
        cout << "Heap is FULL!" << endl;
}

void MyMinHeap::HeapifyDown(int index)
{
    int minIndex = index;
    int l = LeftChild(index);
    int r = RightChild(index);

    // minIndex = min(l, r);
    if (l < count && heap[minIndex] > heap[l])
        minIndex = l;

    if (r < count && heap[minIndex] > heap[r])
        minIndex = r;

    if (index != minIndex)
    {
        swap(heap[index], heap[minIndex]);
        HeapifyDown(minIndex);
    }
}

void MyMinHeap::HeapifyUp(int index)
{
    // if (index > 0 && index < size && heap[index] < heap[parent(index)])
    // {
    //     swap(heap[index], heap[parent(index)]);
    //     HeapifyUp(parent(index));
    // }

    while (index > 0 && heap[index] < heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void MyMinHeap::Display()
{
    for (int i = 0; i < count; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int MyMinHeap::Delete()
{
    if (count == 0)
    {
        cout << "Empty heap" << endl;
        return -1;
    }
    else
    {
        int x = heap[0];
        heap[0] = heap[count - 1];
        count--;
        HeapifyDown(0);
        return x;
    }
}

void min()
{
    MyMinHeap m(15);

    m.Insert(5);
    m.Insert(4);
    m.Insert(3);
    m.Insert(1);
    m.Insert(2);

    m.Display();

    cout << m.Delete() << endl;
}

// ! Max Heap

class MyMaxHeap
{
    int *heap;
    int count;
    int size;

    int parent(int i) { return (i) / 2; }
    int LeftChild(int i) { return 2 * i; }
    int RightChild(int i) { return 2 * i + 1; }

public:
    MyMaxHeap(int);
    ~MyMaxHeap();
    void Insert(int);
    void HeapifyDown(int);
    void HeapifyUp(int);
    void Display();
    int Delete();
};

MyMaxHeap::MyMaxHeap(int s)
{
    size = s;
    count = 1;
    heap = new int[size];
}

MyMaxHeap::~MyMaxHeap()
{
    delete[] heap;
}

void MyMaxHeap::HeapifyUp(int index)
{
    if (index > 1 && heap[index] > heap[parent(index)])
    {
        swap(heap[index], heap[parent(index)]);
        // HeapifyUp(heap[parent(index)]);
        HeapifyUp(parent(index));
    }
}

void MyMaxHeap::Insert(int data)
{
    if (count < size)
    {
        heap[count] = data;
        count++;
        HeapifyUp(count - 1);
    }
    else
        cout << "Heap is FULL!" << endl;
}

void MyMaxHeap::HeapifyDown(int index)
{
    int minIndex = index;
    int l = LeftChild(index);
    int r = RightChild(index);

    if (l < count && heap[minIndex] < heap[l])
        minIndex = l;

    if (r < count && heap[minIndex] < heap[r])
        minIndex = r;

    if (minIndex != index)
    {
        swap(heap[index], heap[minIndex]);
        HeapifyDown(minIndex);
    }
}

void MyMaxHeap::Display()
{
    for (int i = 1; i < count; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int MyMaxHeap::Delete()
{
    if (count == 1)
    {
        cout << "Empty heap" << endl;
        return -1;
    }
    else
    {
        int x = heap[1];
        heap[1] = heap[count - 1];
        count--;
        HeapifyDown(1);
        return x;
    }
}

void max()
{
    MyMaxHeap m(15);

    m.Insert(3);
    m.Insert(7);
    m.Insert(2);
    m.Insert(4);
    m.Insert(1);
    m.Insert(5);

    m.Display();

    cout << m.Delete() << endl;
    cout << m.Delete() << endl;
    cout << m.Delete() << endl;
    cout << m.Delete() << endl;
}

int main()
{
    // min();
    max();

    return 0;
}
