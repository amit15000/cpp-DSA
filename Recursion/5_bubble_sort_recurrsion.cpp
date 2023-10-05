#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr, int n)
{
    if (n == 0)
        return;

    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    if (swapped == false)
        return;

    bubble_sort(arr, n - 1);

    return;
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    int arr[] = {10, 1, -4, 0, 9, 2, 23, 67};

    int size = sizeof(arr) / sizeof(int);

    print_array(arr, size);
    bubble_sort(arr, size - 1);
    print_array(arr, size);
    return 0;
}