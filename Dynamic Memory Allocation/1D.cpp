#include <bits/stdc++.h>
using namespace std;

int main()
{

    // int *ptr = new int;
    // char *ctr = new char;
    // *ptr = 4;
    // // heap mein ek int bana --that is being pointed by the ptr
    // cout << *ptr << endl;
    // cout << sizeof(*ptr) << endl;

    // cout << sizeof(ptr) << endl;

    // cout << sizeof(ctr) << endl;

    int *arr = new int[5];
    int num = 1;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = num++;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "Size of the pointer : " << sizeof(arr) << endl;
    return 0;
}