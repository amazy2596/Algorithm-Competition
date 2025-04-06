#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i];

    vector dp(m + 1, vector<int>(v + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int cost = g[i];
        for (int j = 1; j <= m; j++)
        {
            for (int k = cost; k <= v; k++)
            {
                dp[j][k] = (dp[j][k] + dp[j - 1][k - cost]) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= v; i++)
        ans = (ans + dp[m][i]) % mod;

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}