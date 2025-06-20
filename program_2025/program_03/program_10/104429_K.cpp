#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        s = " " + s;
        for (int j = 1; j <= m; j++)
            g[i][j] = s[j] - '0';
    }

    auto check = [&](int x, int y)
    {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    auto dfs = [&](auto dfs, int x, int y) -> bool
    {
        if (x == n && y == m + 1)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (g[i][j] != 1)
                        return false;
                }
            }

            return true;
        }

        if (y == m + 1)
            x++, y = 1;
        
        if (dfs(dfs, x, y + 1))
            return true;

        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (check(nx, ny))
                g[nx][ny] ^= 1;
        }

        if (dfs(dfs, x, y + 1))
            return true;

        return false;
    };

    cout << (dfs(dfs, 1, 1) ? "YES\n" : "NO\n");
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