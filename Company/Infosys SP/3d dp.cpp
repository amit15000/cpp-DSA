#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxValue(int N,
                 int P,
                 int T,
                 vector<vector<int>> &v,
                 vector<vector<int>> &d)
    {

        int FULL = 1 << N;

        // phaseValue[p][mask]
        // phaseDuration[p][mask]
        vector<vector<int>> phaseValue(P,
                                       vector<int>(FULL, 0));

        vector<vector<int>> phaseDuration(P,
                                          vector<int>(FULL, 0));

        // preprocess subset info
        for (int p = 0; p < P; p++)
        {

            for (int mask = 0; mask < FULL; mask++)
            {

                int totalValue = 0;
                int maxDuration = 0;

                for (int i = 0; i < N; i++)
                {

                    if (mask & (1 << i))
                    {

                        totalValue += v[i][p];

                        maxDuration =
                            max(maxDuration,
                                d[i][p]);
                    }
                }

                phaseValue[p][mask] = totalValue;
                phaseDuration[p][mask] = maxDuration;
            }
        }

        // dp[phase][mask][time]
        vector<vector<vector<int>>> dp(
            P + 1,
            vector<vector<int>>(
                FULL,
                vector<int>(T + 1, -1)));

        dp[0][0][0] = 0;

        for (int phase = 0; phase < P; phase++)
        {

            for (int mask = 0; mask < FULL; mask++)
            {

                for (int time = 0; time <= T; time++)
                {

                    if (dp[phase][mask][time] == -1)
                        continue;

                    // remaining tasks
                    int remaining =
                        ((FULL - 1) ^ mask);

                    // iterate all subsets of remaining
                    for (int sub = remaining;
                         ;
                         sub = (sub - 1) & remaining)
                    {

                        int newTime =
                            time +
                            phaseDuration[phase][sub];

                        if (newTime <= T)
                        {

                            int newMask =
                                mask | sub;

                            dp[phase + 1][newMask][newTime] = max(
                                dp[phase + 1][newMask][newTime],
                                dp[phase][mask][time] + phaseValue[phase][sub]);
                        }

                        if (sub == 0)
                            break;
                    }
                }
            }
        }

        int ans = -1;

        int allTasks = FULL - 1;

        for (int time = 0; time <= T; time++)
        {

            ans = max(
                ans,
                dp[P][allTasks][time]);
        }

        return ans;
    }
};