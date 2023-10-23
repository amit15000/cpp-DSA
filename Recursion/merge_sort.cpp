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
void merge(int *arr, int s, int e)
{
    int mid = (e + s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayIndex++];

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayIndex++];

    int i = 0, j = 0;
    mainArrayIndex = s;

    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
            arr[mainArrayIndex++] = first[i++];
        else
            arr[mainArrayIndex++] = second[j++];
    }

    while (i < len1)
    {
        arr[mainArrayIndex++] = first[i++];
    }
    while (j < len2)
    {
        arr[mainArrayIndex++] = second[j++];
    }
    delete[] first;
    delete[] second;
}

void merge_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    merge_sort(arr, s, mid);

    merge_sort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{

    int arr[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int size = sizeof(arr) / sizeof(int);

    print_array(arr, size);
    merge_sort(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}