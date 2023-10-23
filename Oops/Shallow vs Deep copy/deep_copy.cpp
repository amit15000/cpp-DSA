// Deep copy means-- to use the parametrized copy contructor.
#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    int x;
    int *y;

    ABC(int _x, int *_y) : x(_x), y(_y){};
    ABC(ABC &a)
    {
        x = a.x;
        // y = new int(a.(*y)); // its wrong----- a.(2)===> not a member
        y = new int(*(a.y)); // its working beacause ===> a.y===> 00cef230 ===> *(00cef230)==2 -- int(2) in heap;
    };
    void print() const
    {
        printf("X=%d\nY(pointer)=%d\nContent of Y(*y)=%d\n", x, y, *y);
    }

    ~ABC()
    {

        delete y;
        // cout << y << endl;
    }
};

int main()
{
    // ABC a(10, new int(10));

    // // Creating copy of the class
    // //  ABC b(a);
    // ABC b = a;
    ABC *a = new ABC(5, new int(10));
    ABC b = *a;

    a->print();
    b.print();

    delete a;

    return 0;
}