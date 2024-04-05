#include <iostream>
using namespace std;

int fibonacci(int n)
{
    int arr[100];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    return arr[n];
}

int main()
{
    string s = "Amit";
    string t = "Sumit";

    // cout << fibonacci(5) << endl;
}