// C++ program for implementation of Heap Sort
#include <iostream>
#include <cmath>
using namespace std;


class heap{
    public: 
    int* arr;
    int capacity;
    int count;
    int heap_type;
    heap(int* array, int capacity){
        capacity = capacity;
        arr = new int [capacity];
        for (int i=0; i<capacity; i++){
            arr[i] = array[i];
        }
        count = 0;
    }

    void heapify(int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}

 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
 
// main function to do heap sort
void heapSort(int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

/* Function to delete item in max heap */

int deleteMax(){
    int data = arr[0];
    arr[0] = arr[count];
    count--;
    heapify(count, 0);
    return data;
}

/* Function to insert item in max heap */
int insert(int data){
    int i = count;
    count++;
    while(i > 0 && data > arr[i/2 -1]){
        arr[i] = arr[i/2-1];
        i = i/2-1;
    }
    arr[i] = data;
}

};


 
 
// Driver program
int main()
{
    int arr[] = { 60 ,20 ,40 ,70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap a(arr, n);
  //heapify algorithm
  // the loop must go reverse you will get after analyzing manually
  // (i=n/2 -1) because other nodes/ ele's are leaf nodes
  // (i=n/2 -1) for 0 based indexing
  // (i=n/2)  for 1 based indexing
     for(int i=n/2 -1;i>=0;i--){
       a.heapify(n,i);
   }
   
  cout << "After heapifying array is \n";
    a.printArray(n);
   
   
    a.heapSort(n);
 
    cout << "Sorted array is \n";
    a.printArray(n);
     
  return 0;
}