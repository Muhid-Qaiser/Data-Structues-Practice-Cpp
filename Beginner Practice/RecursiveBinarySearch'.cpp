#include <iostream>
using namespace std;

int fact(int x)
{
    if (x == 0 || x == 1)
        return 1;

    return x * fact(x - 1);
}

int binarysearch(int arr[], int val, int first, int last)
{
    if (first > last)
        return -1;

    int mid = (first + last) / 2;

    if (arr[mid] == val)
        return mid;

    else if (arr[mid] < val)
    {
        binarysearch(arr, val, mid + 1, last);
    }
    else if (arr[mid] > val)
    {
        binarysearch(arr, val, first, mid - 1);
    }
}

int main()
{
    // cout << fact(4);

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[] = {1, 3, 5, 7, 9};

    cout << binarysearch(arr, 6, 0, 4);

    return 0;
}