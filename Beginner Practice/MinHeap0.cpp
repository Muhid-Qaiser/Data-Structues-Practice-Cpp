#include <iostream>
using namespace std;

class MinHeap
{
private:
    int *heap;
    int capacity;
    int size;

    int parent(int i) { return (i) / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void heapifyUp(int i)
    {
        while (i > 1 && heap[i] < heap[parent(i)])
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] < heap[minIndex])
            minIndex = left;
        if (right < size && heap[right] < heap[minIndex])
            minIndex = right;

        if (i != minIndex)
        {
            std::swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->size = 1;
        this->heap = new int[capacity];
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            std::cout << "Heap is full, cannot insert." << std::endl;
            return;
        }

        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    int extractMin()
    {
        if (size == 1)
        {
            std::cout << "Heap is empty." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }

        int min = heap[1];
        heap[1] = heap[size - 1];
        size--;
        heapifyDown(1);

        return min;
    }

    ~MinHeap()
    {
        delete[] heap;
    }

    void display()
    {
        for (int i = 1; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap minHeap(10);

    minHeap.insert(5);
    minHeap.insert(4);
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(2);

    minHeap.display();

    // while (minHeap.extractMin() != -1)
    {
        std::cout << minHeap.extractMin() << " ";
        std::cout << minHeap.extractMin() << " ";
        std::cout << minHeap.extractMin() << " ";
        std::cout << minHeap.extractMin() << " ";
        std::cout << minHeap.extractMin() << " ";
    }

    return 0;
}
