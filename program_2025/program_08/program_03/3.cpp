#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int m;
    cin >> m;
    int n = 2;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++)    
        cin >> s[i];

    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    int ans = 0;
    auto bfs = [&](int i, int j, char ch)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (vis[x][y] == 1)
                continue;
            vis[x][y] = 1;

            for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {0, 1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] != ch)
                    continue;
                q.push({nx, ny});
            }
        }
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j])
            {
                bfs(i, j, s[i][j]);
                ans++;
            }
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}