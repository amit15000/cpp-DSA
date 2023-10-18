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

void power_set(int *arr, int size, int *pset)
{
}

int main()
{

    int arr[] = {1, 2, 3};
    int pset[] = {};

    int size = sizeof(arr) / sizeof(int);

    power_set(arr, 0, size - 1, );

    return 0;
}