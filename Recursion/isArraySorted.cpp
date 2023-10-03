#include <bits/stdc++.h>
using namespace std;

bool isArraySorted(int arr[], int size)
{
    if (size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
    {
        return isArraySorted(arr + 1, size - 1);
    }
}

int main()
{

    int arr[] = {4, 2, 11, 19, 20};
    int size = sizeof(arr) / sizeof(int);
    bool ans = isArraySorted(arr, size);

    if (ans)
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;
    return 0;
}