#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    vector<vector<int>> vis(n, vector<int>(m));
    auto dfs = [&](auto dfs, int x, int y, int count) -> int
    {
        if (vis[x][y])
            return 0;
        if (count == k)
            return 1;
        vis[x][y] = 1;
        int res = 0;
        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#')
                continue;
            
            res += dfs(dfs, nx, ny, count + 1);
        }
        vis[x][y] = 0;
        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] != '#')
                ans += dfs(dfs, i, j, 0);
    
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