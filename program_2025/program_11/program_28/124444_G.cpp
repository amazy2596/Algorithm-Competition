// Problem: 智慧or力量
// URL: https://ac.nowcoder.com/acm/contest/124444/G
// Author: amazy
// Date: 2025-11-28 23:30:43

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct node
{
    int x, y, t;

    bool operator<(const node &o) const 
    {
        return t > o.t;
    }
};

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    i64 M;
    cin >> x >> y >> M;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), vis(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    priority_queue<node> q;
    vis[x][y] = 1;
    for (auto [dx, dy] : dir)
    {
        int nx = x + dx, ny = y + dy;
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        vis[nx][ny] = 1;
        q.push({nx, ny, a[nx][ny]});
    }

    int ans = 0;
    while (!q.empty())
    {
        auto [i, j, t] = q.top();
        q.pop();

        if (M < t) break;
        M += t;
        ans++;

        for (auto [dx, dy] : dir)
        {
            int nx = i + dx, ny = j + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny, a[nx][ny]});
        }
    }

    cout << ans << "\n";
}

int main()
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