#include <bits/stdc++.h>
using namespace std;

int customCmp(int a, int b)
{
    return a > b;
}

int main()
{
    int arr[5] = {7, 9, 5, 10, 3};
    sort(begin(arr), end(arr), customCmp);

    for (auto n : arr)
    {
        cout << n << " ";
    }
    return 0;
}