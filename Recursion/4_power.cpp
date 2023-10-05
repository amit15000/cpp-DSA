#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int cp = power(a, b / 2);
    // power odd
    if (b & 1)
        return a * cp * cp;
    else
        return cp * cp;
}
int main()
{

    int a, b;
    cin >> a >> b;
    int ans = power(a, b);
    cout << "Answer is " << ans << endl;
    return 0;
}