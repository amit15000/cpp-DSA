#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    int x;
    int *y;
    // int z;

    const int z;
    // default constructor can't initialize( or set ) it's value .
    // but ' Initialization List' can set it's value.

    // old way of constructor call
    // ABC(int _x, int *_y, int _z)
    // {

    //     x = _x;
    //     y = _y;
    //     z = _z;      //if z is const---- error here.
    //     cout << "default constructor called" << endl;
    // }

    // new way of writing the constructor---->>> Initialization List

    //<-----------------Initialization List-------------------------------->
    // ABC(int _x, int *_y, int _z) : x(_x), y(_y), z(_z){};
    ABC(int _x, int *_y, int _z) : x(_x), y(_y), z(_z)
    {
        cout << "Initialization list called" << endl;
    };
};
void print(const ABC &a)
{
    cout << a.x << " " << *(a.y) << " " << a.z << endl;
}

int main()
{
    ABC a(10, new int(11), 12);
    print(a);

    return 0;
}