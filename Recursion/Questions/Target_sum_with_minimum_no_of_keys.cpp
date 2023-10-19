#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int x)
{

    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    return mini;
}
int main()
{
    // vector<int> num = {1, 2, 3};
    // int target = 5;
    // int ans = solve(num, target);
    // cout << ans << endl;
    int x = INT_MAX;
    cout << x << endl;
    x = x + 1;
    cout << x << endl;
}