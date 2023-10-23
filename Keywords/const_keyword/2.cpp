#include <bits/stdc++.h>
using namespace std;

class abc
{
    int x;
    int *y;
    int z;

public:
    // constructor

    abc(int _x, int _y, int _z = 0) // z is default argument here.
    {
        x = _x;
        y = new int(_y);
        z = _z;
    }

    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return *y;
    }

    int setX(int _val) const
    {
        // x = _val;

        // funtion ko constant bana diya to ----- x ki value ab change nahi kar sakte.
    }
};
void printABC(const abc &a) // const abce & a ===>>> eska mtlb jo andar functions likhe hain ---- getX() and getY() ===dono "const" function hone chahiye.
{
    // cout << "X = " << a.getX() << "Y = " << a.getY() << endl;
    cout << "X = " << a.getX() << ", Y = " << a.getY() << endl;
}
int main()
{
    abc obj1(3, 5);
    abc obj2(10, 20, 30);
    obj1.setX(4);
    printABC(obj2);
    // cout << obj1.getX();
    return 0;
}