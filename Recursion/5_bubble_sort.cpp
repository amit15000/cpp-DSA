#include <bits/stdc++.h>
using namespace std;

// void bubble_sort(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]);
//         }
//     }
// }

// way 2
void bubble_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {

        bool swapped = false;

        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            // already sorted
            break;
        }
    }
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

    int arr[] = {10, -2, 18, 11, 16};

    int size = sizeof(arr) / sizeof(int);

    print_array(arr, size);
    bubble_sort(arr, size);
    print_array(arr, size);
    return 0;
}