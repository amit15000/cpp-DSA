// compile-time-polymorphism
#include <bits/stdc++.h>
using namespace std;

class Math
{
public:
    int val;

    int operator+(Math &object2)
    {
        int val1 = this->val;
        int val2 = object2.val;
        return val1 - val2;
    }
};
int main()
{
    Math object1, object2;

    object1.val = 10;
    object2.val = 4;
    // without defining the behaviour of '+' in class ---- compiler can't understand what would be the behaviour of '+' with the user defined class's object 1 & 2.
    cout << (object1 + object2);

    // we have defined + as '-'      object1 + object2 => object1-object2;

    cout << object1;
    return 0;
}