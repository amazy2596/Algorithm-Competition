#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    n++, m++, x++, y++;
    map<pair<int, int>, int> mp;
    mp[{x, y}]++;
    for (auto [dx, dy] : vector<pair<int, int>> {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}})
    {
        int nx = x + dx, ny = y + dy;
        mp[{nx, ny}]++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (mp.find({i, j}) == mp.end())
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << "\n";
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