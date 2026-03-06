// Problem: L3-1 岛屿淹没问题
// URL: https://ac.nowcoder.com/acm/contest/104429/M
// Author: amazy
// Date: 2026-03-06 22:17:45

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct node
{
    int high;
    int i, j;

    bool operator<(const node o) const
    {
        return high > o.high;
    }
};

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    priority_queue<node> pq;
    for (int j = 0; j < m; j++) pq.push({g[0][j], 0, j}), pq.push({g[n - 1][j], n - 1, j});
    for (int i = 0; i < n; i++) pq.push({g[i][0], i, 0}), pq.push({g[i][m - 1], i, m - 1});

    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    int ans = n * m;
    for (int c = 1; c <= t; c++)
    {
        while (ans > 0 && pq.top().high <= c)
        {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            ans--;
            for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
                pq.push({g[nx][ny], nx, ny});
            }
        }

        cout << ans << "\n";
    }
}

int main()
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