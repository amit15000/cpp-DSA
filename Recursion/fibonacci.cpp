#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{

    // 0 ko 1st--- 1 ko 2nd term mana tab.
    // if (n <= 1)
    //     return 0;

    // if (n == 2)
    //     return 1;

    // // 0 ko 0th--- 1 ko 1st term mana tab.
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int sp = fibonacci(n - 1) + fibonacci(n - 2);
    return sp;
}

int main()
{

    int n;
    cin >> n;

    int ans = fibonacci(n);
    cout << ans << endl;
    return 0;
}