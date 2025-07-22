#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> best(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        s = " " + s;
        vector<int> pre(m + 1);
        for (int j = 1; j <= m; j++)
            pre[j] = pre[j - 1] + (s[j] == '1');

        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        for (int j = 1; j <= m; j++)
        {
            for (int k = m; k >= 0; k--)
            {
                dp[j][k] = dp[j - 1][k];
                for (int p = 1; p <= j && k >= 1; p++)
                {
                    int score = max(pre[j] - pre[p - 1], (j - p + 1) - (pre[j] - pre[p - 1]));
                    dp[j][k] = max({dp[j][k], dp[j - 1][k], dp[p - 1][k - 1] + score});
                }
            }
        }

        for (int k = 0; k <= m; k++)
            best[i][k] = dp[m][k];
    }

    vector<int> dp(t + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            for (int k = 0; k <= min(j, m); k++)
            {
                dp[j] = max(dp[j], dp[j - k] + best[i][k]);
            }
        }
    }

    cout << dp[t] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}