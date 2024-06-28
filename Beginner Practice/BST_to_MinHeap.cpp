#include <iostream>
#include <vector>

void heapify(std::vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] < arr[smallest])
    {
        smallest = left_child;
    }

    if (right_child < n && arr[right_child] < arr[smallest])
    {
        smallest = right_child;
    }

    if (smallest != i)
    {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void arrayToMinHeap(std::vector<int> &arr)
{
    int n = arr.size();

    // Build a min heap
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    std::vector<int> input = {5, 3, 8, 2, 4, 6, 10};

    std::cout << "Input array: ";
    for (int num : input)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arrayToMinHeap(input);

    std::cout << "Min Heap array: ";
    for (int num : input)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
