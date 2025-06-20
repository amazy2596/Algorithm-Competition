#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        g[i] = " " + g[i];
    }

    map<char, pair<int, int>> dir;
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};

    vector can(n + 1, vector<int>(m + 1));
    vector vis(n + 1, vector<int>(m + 1));
    can[n][m] = 1;
    queue<pair<int, int>> q;
    q.push({n, m});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (vis[x][y])
            continue;
        vis[x][y] = 1;

        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            auto [rx, ry] = dir[g[nx][ny]];

            if (nx + rx == x && ny + ry == y)
            {
                q.push({nx, ny});
                can[nx][ny] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << can[i][j] << " ";
        }

        cout << "\n";
    }

    vis = vector<vector<int>> (n + 1, vector<int>(m + 1, 0));
    int x = 1, y = 1;

    while (true)
    {
        if (vis[x][y])
        {
            cout << "NO\n";
            return;
        }
        vis[x][y] = 1;

        if (can[x][y])
        {
            cout << "YES\n";
            return;
        }

        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            if (can[nx][ny])
            {
                cout << "YES\n";
                return;
            }
        }

        auto [dx, dy] = dir[g[x][y]];
        int nx = x + dx, ny = y + dy;
        
        if (nx < 1 || nx > n || ny < 1 || ny > m)
        {
            cout << "NO\n";
            return;
        }

        x = nx, y = ny;
    }
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