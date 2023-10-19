#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/operator-overloading-cpp/
// Conversion Operator: We can also write conversion operators that can be used to convert one type to another type. example--->
class Fraction
{
public:
    float num;
    float den;
    Fraction(int n, int d)
    {
        num = n;
        den = d;
    }

    // float to tha hi usko float hi rehne diya.
    operator float()
    {
        return float(num) / float(den);
    }

    // float to tha hi usko int kar diya.
    operator int()
    {
        return int(num) / int(den);
    }
};
int main()
{
    Fraction f(10.5, 3.1);
    Fraction d(10.5, 3.1);
    float val = f;
    int val2 = d;
    cout << val << endl;
    cout << val2 << endl;

    // hamne operator overriding karke float ko 'int' bana diya hai.
    return 0;
}