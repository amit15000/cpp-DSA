#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a = 5;
    int *pt1 = &a;
    int **pt2 = &pt1;
    int ***pt3 = &pt2;

    // value of a
    // cout << a << endl;
    // cout << *pt1 << endl;
    // cout << **pt2 << endl;
    // cout << **pt3 << endl;

    // // printing addresses and values.
    // cout << a << endl;    // should come a
    // cout << &a << endl;   // should come address of a
    // cout << *pt1 << endl; // should come a
    // cout << pt1 << endl;  // should come address of a
    // cout << *pt2 << endl; // should come address of a
    // cout << pt2 << endl;  // should come address of pt1
    // cout << *pt3 << endl; // should come address of pt1
    // cout << pt3 << endl;  // should come address of pt2

    return 0;
}