#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct Substring
{
    string str;
    int cost;
};

int main()
{
    int n;
    cin >> n;
    vector<Substring> substrings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> substrings[i].str >> substrings[i].cost;
    }
    string mainString;
    cin >> mainString;

    int m = mainString.size();
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0; // Base case: cost to construct an empty string is 0.

    for (int i = 1; i <= m; i++)
    {
        for (const auto &sub : substrings)
        {
            int len = sub.str.size();
            if (i >= len && mainString.substr(i - len, len) == sub.str)
            {
                if (dp[i - len] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - len] + sub.cost);
                }
            }
        }
    }

    if (dp[m] == INT_MAX)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << dp[m] << endl;
    }
    return 0;
}
