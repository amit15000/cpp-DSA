#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    static int x, y;
    int z = 4;
    static void print()
    {
        printf("X = %d\nY = %d\n", x, y);
        cout << z << endl; // z access  nahi ho payega--- bcz it's not a static value---
        // basically--- class ka member(eg- x,y) print ho sakta hai --- object ke variable(z) --nahi accessible hai
        //  z jis object ka hai --uska this(pointer) es 'static' function mein pass hi nahi ho raha hai.
    }
};
int ABC::x;
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