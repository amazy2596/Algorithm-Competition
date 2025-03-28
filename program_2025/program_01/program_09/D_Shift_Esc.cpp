#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(m, 1e18l));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int shift = 0; shift < m; shift++)
        {
            vector<int> temp(m, 1e18l);
            for (int j = 0; j < m; j++)
                temp[j] = dp[i - 1][j] + a[i][(j + shift) % m] + k * shift;

            for (int j = 0; j < m; j++)
                temp[j] = min(temp[j], temp[(j - 1 + m) % m] + a[i][(j + shift) % m]);
            
            for (int j = 0; j < m; j++)
                dp[i][j] = min(dp[i][j], temp[j]);
        }
    }

    cout << dp[n][m - 1] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}