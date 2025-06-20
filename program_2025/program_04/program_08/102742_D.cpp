#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    int t;
    cin >> t;
    vector tag(n + 1, vector<int>(m + 1, INT32_MAX));
    while (t--)
    {
        int x, y, v;
        cin >> x >> y >> v;
        tag[x][y] = v;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i + j - 2 >= tag[i][j]) 
                g[i][j] = -1e14;

    int ans = 0;
    vector dp(n + 1, vector<int>(m + 1, INT32_MIN));
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
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