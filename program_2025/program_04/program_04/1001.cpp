#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(m + 1, vector<int>(v + 1));
    dp[0][0] = 1;
    for (int idx = 1; idx <= n; idx++)
    {
        int g = a[idx];
        for (int i = 1; i <= m; i++)
        {
            for (int j = g; j <= v; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - g]) % mod;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= v; j++)
        ans = (ans + dp[m][j]) % mod;
    cout << ans % mod << "\n";
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