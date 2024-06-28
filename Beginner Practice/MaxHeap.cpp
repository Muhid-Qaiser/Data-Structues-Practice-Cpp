#include <iostream>

class MaxHeap
{
private:
    int *heap;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i)
    {
        while (i > 0 && heap[i] > heap[parent(i)])
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[maxIndex])
            maxIndex = left;
        if (right < size && heap[right] > heap[maxIndex])
            maxIndex = right;

        if (i != maxIndex)
        {
            std::swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
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

    int extractMax()
    {
        if (size == 0)
        {
            std::cout << "Heap is empty." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }

        int max = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return max;
    }

    ~MaxHeap()
    {
        delete[] heap;
    }
};

int main()
{
    MaxHeap maxHeap(10);

    maxHeap.insert(4);
    maxHeap.insert(9);
    maxHeap.insert(2);
    maxHeap.insert(7);
    maxHeap.insert(5);

    while (maxHeap.extractMax() != -1)
    {
        std::cout << maxHeap.extractMax() << " ";
    }

    return 0;
}
