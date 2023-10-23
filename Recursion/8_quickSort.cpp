#include <bits/stdc++.h>
using namespace std;
void print_array(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
            cnt++;
    }

    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]);

    int i, j;
    i = s;
    j = e;

    while (i<pivotIndex & j> pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
            i++;

        while (arr[j] > arr[pivotIndex])
            j--;

        swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quick_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quick_sort(arr, s, p - 1);

    quick_sort(arr, p + 1, e);
}

int main()
{

    int arr[] = {6, -1, 3, 12, 5, 23, 42, 1, -12};

    int size = sizeof(arr) / sizeof(int);

    print_array(arr, size);
    quick_sort(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}