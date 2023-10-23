#include <bits/stdc++.h>
using namespace std;

int power(int n)
{

    cout << n << endl;
    // best case
    if (n == 0)
        return 1;
    int cp = power(n - 1);
    int bp = 2 * cp;
    return bp;
}

int main()
{

    int n = 5;
    int ans = power(n);
    cout << ans << endl;
    return 0;
}