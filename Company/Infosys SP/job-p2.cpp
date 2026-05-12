#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs(int idx, int n, int p, int t, vector<vector<int>>& v, vector<vector<int>>& d, vector<int>& mx, int curVal) {
    int curTime = 0;
    for (int x : mx) curTime += x;
    if (curTime > t) return;

    if (idx == n) {
        ans = max(ans, curVal);
        return;
    }

    for (int ph = 0; ph < p; ph++) {
        int old = mx[ph];
        mx[ph] = max(mx[ph], d[idx][ph]);
        dfs(idx + 1, n, p, t, v, d, mx, curVal + v[idx][ph]);
        mx[ph] = old;
    }
}

int solve(int n, int p, int t, vector<vector<int>>& v, vector<vector<int>>& d) {
    ans = -1;
    vector<int> mx(p, 0);
    dfs(0, n, p, t, v, d, mx, 0);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int p; cin >> p;
    int t; cin >> t;

    vector<vector<int>> v(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) cin >> v[i][j];
    }

    vector<vector<int>> d(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) cin >> d[i][j];
    }

    auto result = solve(n, p, t, v, d);
    cout << result << endl;
    return 0;
}