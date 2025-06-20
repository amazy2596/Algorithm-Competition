#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m)), vis(n, vector<int>(m));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    auto bfs = [&](int i, int j)
    {
        int res = 0, tar = g[i][j];
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            res++;

            for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (g[nx][ny] == tar)
                    q.push({nx, ny});
            }
        }

        return res;
    };

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j])
                continue;
            
            int res = bfs(i, j);
            if (res >= 2)
                mp[g[i][j]] = 2, cnt = 2;
            else if (mp.find(g[i][j]) == mp.end())
                mp[g[i][j]] = 1;
        }
    }

    int sum = 0;
    for (auto [key, val] : mp)
        sum += val;

    cout << sum - cnt << "\n";
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