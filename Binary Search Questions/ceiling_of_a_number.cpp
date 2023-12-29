#include <iostream>
using namespace std;

int ceiling_of_number(int arr[], int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    if (start <= end)
    {

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            ceiling_of_number(arr, mid + 1, end, target);
        }
        else
        {
            ceiling_of_number(arr, 0, mid - 1, target);
        }
    }
    return mid;
}
int main()
{
    int arr[] = {2, 4, 6, 10, 15, 23, 56};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 15;

    int ans = ceiling_of_number(arr, 0, size - 1, target);
    cout << arr[ans] << endl;
    return 0;
}