#include <iostream>

const int MAX_SIZE = 100; // Define the maximum size of the priority queue

class PriorityQueue
{
private:
    int heap[MAX_SIZE];
    int size;

    // Helper function to maintain the max heap property
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[index] <= heap[parentIndex])
            {
                break; // Max heap property is satisfied
            }
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }

    // Helper function to maintain the max heap property
    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() : size(0) {}

    // Insert an element into the priority queue
    void push(int data)
    {
        if (size == MAX_SIZE)
        {
            std::cout << "Priority queue is full. Cannot push." << std::endl;
            return;
        }

        heap[size++] = data;
        heapifyUp(size - 1);
    }

    // Remove and return the element with the highest priority
    int pop()
    {
        if (empty())
        {
            std::cout << "Priority queue is empty." << std::endl;
            return -1; // Return a sentinel value to indicate an empty queue
        }

        int top = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return top;
    }

    // Check if the priority queue is empty
    bool empty() const
    {
        return size == 0;
    }

    // Get the size of the priority queue
    int getSize() const
    {
        return size;
    }

    void display() const
    {
        if (empty())
        {
            std::cout << "Priority queue is empty." << std::endl;
            return;
        }

        std::cout << "Priority queue contents: ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    PriorityQueue maxPriorityQueue;

    maxPriorityQueue.push(30);
    maxPriorityQueue.push(10);
    maxPriorityQueue.push(50);
    maxPriorityQueue.push(20);

    maxPriorityQueue.display();

    std::cout << "Top element: " << maxPriorityQueue.pop() << std::endl;

    if (maxPriorityQueue.empty())
    {
        std::cout << "Priority queue is empty." << std::endl;
    }
    else
    {
        std::cout << "Priority queue is not empty." << std::endl;
    }

    std::cout << "Size of priority queue: " << maxPriorityQueue.getSize() << std::endl;

    return 0;
}
