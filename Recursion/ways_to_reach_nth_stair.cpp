#include <bits/stdc++.h>
using namespace std;
int countWaysToReach(int n)
{
    // best case
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    return countWaysToReach(n - 1) + countWaysToReach(n - 2);
}

int main()
{
    int n;
    cin >> n;
    int ans = countWaysToReach(n);
    cout << ans << endl;
    return 0;
}
d