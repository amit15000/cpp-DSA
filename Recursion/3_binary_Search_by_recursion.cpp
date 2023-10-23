#include <bits/stdc++.h>
using namespace std;

bool binary_Search(int *arr, int l, int h, int key)
{

    if (l > h)
        return -1;
    int m = h - (h - l) / 2;

    if (arr[m] > key)
        return binary_Search(arr, l, m - 1, key);
    else if (arr[m] < key)
        return binary_Search(arr, m + 1, h, key);
    else
        return 1;
}
int main()
{

    int arr[] = {4, 2, 11, 19, 20};
    int key = 12;
    int size = sizeof(arr) / sizeof(int);
    bool ans = binary_Search(arr, 0, size - 1, key);

    if (ans)
        cout << "Element is present" << endl;
    else
        cout << "Element is not present" << endl;

    return 0;
}