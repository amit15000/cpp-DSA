#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int N, P, T;

    // memo:
    // key -> best answer
    unordered_map<string, int> dp;

    string makeKey(int idx, vector<int>& mx) {

        string key = to_string(idx) + "#";

        for(int x : mx) {
            key += to_string(x) + ",";
        }

        return key;
    }

    int solve(int idx,
              vector<int>& mx,
              vector<vector<int>>& v,
              vector<vector<int>>& d) {

        // all tasks assigned
        if(idx == N) {

            int totalTime = 0;

            for(int x : mx)
                totalTime += x;

            if(totalTime <= T)
                return 0;

            return -1e9;
        }

        string key = makeKey(idx, mx);

        if(dp.count(key))
            return dp[key];

        int ans = -1e9;

        // try assigning current task
        // to every phase
        for(int phase = 0; phase < P; phase++) {

            vector<int> newMx = mx;

            newMx[phase] =
                max(newMx[phase],
                    d[idx][phase]);

            int totalTime = 0;

            for(int x : newMx)
                totalTime += x;

            // prune invalid states early
            if(totalTime > T)
                continue;

            ans = max(
                ans,
                v[idx][phase]
                + solve(idx + 1,
                        newMx,
                        v,
                        d)
            );
        }

        return dp[key] = ans;
    }

    int maxValue(int n,
                 int p,
                 int t,
                 vector<vector<int>>& v,
                 vector<vector<int>>& d) {

        N = n;
        P = p;
        T = t;

        vector<int> mx(P, 0);

        return solve(0, mx, v, d);
    }
};