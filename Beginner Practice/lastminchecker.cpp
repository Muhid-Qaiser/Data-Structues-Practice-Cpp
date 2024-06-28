
#include <iostream>
#include <vector>

using namespace std;

// Iterative Solution
vector<int> replaceWithProduct(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, 1);
    int left = 1, right = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] *= left;
        left *= arr[i];
        result[n - 1 - i] *= right;
        right *= arr[n - 1 - i];
    }
    return result;
}

// Recursive Solution
void replaceWithProductRecursive(vector<int> &arr, vector<int> &result, int i, int left, int right)
{
    if (i == arr.size())
    {
        return;
    }
    result[i] = left;
    left *= arr[i];
    replaceWithProductRecursive(arr, result, i + 1, left, right);
    result[arr.size() - 1 - i] *= right;
    right *= arr[arr.size() - 1 - i];
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> result = replaceWithProduct(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    result = vector<int>(arr.size(), 1);
    replaceWithProductRecursive(arr, result, 0, 1, 1);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
