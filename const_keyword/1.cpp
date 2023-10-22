#include <bits/stdc++.h>
using namespace std;

int main()
{

    // const int a = 5;
    // a = 10;

    // int *a = new int;
    // *a = 4;
    // cout << *a << endl;

    // Type 1

    // const int *a = new int(4);
    // data constant ( by writing cosnt int)---->> but pointer not constant.
    // cout << *a << endl;
    // // *a = 5; // data constant hai  ---
    // int b = 50;
    // a = &b;
    // cout << *a << endl;

    // Type 2

    // int *const a = new int(5);
    // // data not constant--- pointer constant
    // *a = 10;
    // int b = 12;
    // // a = &b;          //a pointer constant hai ----> can't point to b now;
    // cout << *a << endl;

    // type 3

    // const int *const a = new int[5];
    // constant data, const pointer

    return 0;
}