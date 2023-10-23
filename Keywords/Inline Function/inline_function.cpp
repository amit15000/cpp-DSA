#include <bits/stdc++.h>
using namespace std;
inline int getMax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{

    int a = 5, b = 1;
    int ans = getMax(a, b);
    cout << ans;

    return 0;
}