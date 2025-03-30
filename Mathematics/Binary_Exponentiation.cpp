#include <iostream>
using namespace std;

int calculatePower(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int res = calculatePower(a, b / 2);
    if (b & 1)
    {
        // odd power
        return res * res * a;
    }
    else
    {
        return res * res;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int res = calculatePower(a, b);
    cout << res;
}