#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    static int x, y; // sare objects ka x,y same hoga.
    int z;           // z har object ka apna apna hoga.
    // static hai to enko --- class ke outside define bhi karna rahega---> int ABC ::x;
    void print()
    {
        printf("X = %d\nY = %d\n", x, y);
    }
};
int ABC::x; // x class in static member hona chaiye.
int ABC::y;

int main()
{
    ABC a, b;
    a.x = 10;
    a.y = 20;

    b.x = 15;
    b.y = 25;
    a.print();
    b.print();
    return 0;
}