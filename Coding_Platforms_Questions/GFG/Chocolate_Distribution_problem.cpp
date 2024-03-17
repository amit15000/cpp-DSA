// C++ program to solve chocolate distribution
// problem
#include <bits/stdc++.h>
using namespace std;

// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
    
}

int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
