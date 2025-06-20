#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1), p(m + 1), q(m + 1);
    vector<vector<int>> attach(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = x, p[i] = y, q[i] = z;
        attach[z].push_back(i);
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= m; i++)
    {
        if (q[i] != 0)
            continue;
        for (int j = n; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
            if (attach[i].size() >= 1)
            {
                int k = attach[i][0];
                if (j - v[i] - v[k] >= 0)
                    dp[j] = max(dp[j], dp[j - v[i] - v[k]] + v[i] * p[i] + v[k] * p[k]);
            }
            if (attach[i].size() >= 2)
            {
                int k1 = attach[i][0], k2 = attach[i][1];
                if (j - v[i] - v[k2] >= 0)
                    dp[j] = max(dp[j], dp[j - v[i] - v[k2]] + v[i] * p[i] + v[k2] * p[k2]);
                if (j - v[i] - v[k1] - v[k2] >= 0)
                    dp[j] = max(dp[j], dp[j - v[i] - v[k1] - v[k2]] + v[i] * p[i] + v[k1] * p[k1] + v[k2] * p[k2]);
            }
        }
    }
    cout << dp[n] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}