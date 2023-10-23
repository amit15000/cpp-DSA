#include <bits/stdc++.h>
using namespace std;

bool linear_Search(int *arr, int n, int key)
{

    if (n == 0)
        return false;

    if (arr[0] == key)
        return true;
    else
    {
        linear_Search(arr + 1, n - 1, key);
    }
}
int main()
{

    int arr[] = {4, 2, 11, 19, 20};
    int key = 21;
    int size = sizeof(arr) / sizeof(int);
    bool ans = linear_Search(arr, size, key);

    if (ans)
        cout << "Element is present" << endl;
    else
        cout << "Element is not present" << endl;

    return 0;
}