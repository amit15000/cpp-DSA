#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    printArr(arr, n);

    // Rotate Array

    int brr[100];
    for (int j = 1; j < n; j++)
    {

        for (int i = 0; i < n; i++)
        {
            brr[(n + i + j) % n] = arr[i];
        }
        printArr(brr, n);
    }
}