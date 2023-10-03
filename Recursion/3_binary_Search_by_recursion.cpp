#include <bits/stdc++.h>
using namespace std;

bool binary_Search(int *arr, int l, int h, int key)
{

    m = h - (h - l) / 2;

    while (l <= h)
    {

        if (arr[m] > key)
            h = m - 1;
        else if (arr[m] < key)
            l = m + 1;
        else
            return 1;

        m = h - (h - l) / 2;
    }
    return 0;
}
int main()
{

    int arr[] = {4, 2, 11, 19, 20};
    int key = 2;
    int size = sizeof(arr) / sizeof(int);
    bool ans = binary_Search(arr, 0, size - 1, key);

    if (ans)
        cout << "Element is present" << endl;
    else
        cout << "Element is not present" << endl;

    return 0;
}