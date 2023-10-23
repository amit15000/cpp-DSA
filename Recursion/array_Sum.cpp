#include <bits/stdc++.h>
using namespace std;

int getSum(int *arr, int size)
{
    // best case
    if (size == 0)
        return 0;

    return arr[0] + getSum(arr + 1, size - 1);
}

int main()
{
    int arr[] = {12, 4, 41, 11};
    int size = sizeof(arr) / sizeof(int);

    int ans = getSum(arr, size);
    cout << "Sum is " << ans << endl;

    return 0;
}