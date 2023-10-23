#include <bits/stdc++.h>
using namespace std;

void update(int ***pt3)
{
    ***pt3 = ***pt3 + 1;
    // cout << pt3 << endl;
}
int main()
{

    int a = 5;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;

    cout << a << endl;
    cout << *ptr1 << endl;
    cout << **ptr2 << endl;
    cout << ***ptr3 << endl;

    // int a = 5;
    // int *pt1 = &a;
    // int **pt2 = &pt1;
    // int ***pt3 = &pt2;

    // // before

    // cout << *pt1 << endl;
    // cout << **pt2 << endl;
    // cout << ***pt3 << endl;
    // update(pt3); // pass by value
    // cout << *pt1 << endl;
    // cout << **pt2 << endl;
    // cout << ***pt3 << endl;

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