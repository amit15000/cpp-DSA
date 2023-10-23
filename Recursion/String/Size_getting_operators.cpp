#include <bits/stdc++.h>
using namespace std;

int main()
{

    char arr[] = "amit";
    char st[] = {'a', 'm', 'i', 't'};
    string str = "amit";
    // int n = sizeof(str) / sizeof(str[0]);
    cout << sizeof(st) << endl;  // actual size in bytes--- used when elements are separated by comma.
    cout << strlen(arr) << endl; // used when array elements are not separated by comma
    cout << str.size() << endl;  // member function of string.

    // int l = 0, h = n - 1;
    // cout << "Before " << str << endl;

    // while (l < h)
    // {
    //     swap(str[l++], str[h--]);
    // }
    // cout << "After " << str << endl;

    return 0;
}