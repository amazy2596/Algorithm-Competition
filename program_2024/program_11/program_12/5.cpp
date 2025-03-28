#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    // vector<int> v(n + 1), w(n + 1), s(n + 1);
    vector<pair<int, int>> p;
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2)
        {
            s -= k;
            p.push_back({k * v, k * w});
        }
        if (s)
            p.push_back({s * v, s * w});
    }
    vector<int> dp(m + 1);
    for (auto [v, w] : p)
    {
        for (int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + w);
            // for (int k = 0; k <= s[i]; k++)
            // {
                // if (j >= k * v[i])
                    // dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            // }
        }
    }
    cout << dp[m] << "\n";
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