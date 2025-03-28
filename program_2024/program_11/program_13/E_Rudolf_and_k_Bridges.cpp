#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1, INT64_MAX));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0, dp[i][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        map<int, int> mp;
        for (int r = 1; r <= m; r++)
        {
            int mn = (*mp.begin()).first;
            dp[i][r] = min(dp[i][r], mn + a[i][r] + 1);
            mp[dp[i][r]]++;
            if (r >= d + 2)
            {
                if (--mp[dp[i][r - d - 1]] == 0)
                    mp.erase(dp[i][r - d - 1]);
            }
        }       
    }
    int l = 1, r = 1, cur = 0, ans = INT64_MAX;
    while (l <= r && r <= n)
    {
        cur += dp[r][m];
        if (r - l + 1 == k)
        {
            ans = min(ans, cur);
            cur -= dp[l++][m];
        }
        r++;
    }
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