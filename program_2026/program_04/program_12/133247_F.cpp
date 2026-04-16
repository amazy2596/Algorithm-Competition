// Problem: 我的世界之诡异回廊
// URL: https://ac.nowcoder.com/acm/contest/133247/F
// Author: amazy
// Date: 2026-04-12 15:52:47

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node
{
    i64 i, j, my, other;
};

vector<pair<int, int>> dist = {{0, 1}, {1, 0}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> g(n + 2, vector<i64>(m + 2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    vector<vector<i64>> dp(n + 2, vector<i64>(m + 2, INT64_MIN));
    i64 ans = INT64_MIN;
    dp[1][1] = g[1][1] - g[1][m];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i + 1][j] = max({
                dp[i + 1][j],
                dp[i][j] + (g[i + 1][j] - g[i + 1][m - j + 1])
            });

            dp[i][j + 1] = max({
                dp[i][j + 1],
                dp[i][j] + (g[i][j + 1] - g[i][m - j])
            });

            ans = max(ans, dp[i][j]);
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << ans << "\n";

    // i64 ans = g[1][1] - g[1][m];
    // queue<node> q;
    // q.push({1, 1, g[1][1], g[1][m]});
    // while (q.size())
    // {
    //     auto [i, j, my, other] = q.front();
    //     q.pop();
    //     // cout << i << " " << j << " " << my << " " << other << "\n";
    //     ans = max(ans, my - other);
    //     for (auto [dx, dy] : dist)
    //     {
    //         int nx = i + dx, ny = j + dy;
    //         int onx = i + dx, ony = (m - j + 1) - dy;
    //         if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
    //         i64 nmy = my + g[nx][ny], nother = other + g[onx][ony];
    //         q.push({nx, ny, nmy, nother});
    //     }
    // }

    // cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}