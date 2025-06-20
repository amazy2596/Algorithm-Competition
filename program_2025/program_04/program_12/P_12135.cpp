#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int x, y, dist;
    set<int> s;
};

void solve()
{
    vector<string> g(3);
    cin >> g[1] >> g[2];
    int n = g[1].length();
    g[1] = " " + g[1];
    g[2] = " " + g[2];

    vector<vector<int>> vis(3, vector<int>(n + 1)), vis1(3, vector<int>(n + 1));

    int tot = 0;
    auto bfs1 = [&](int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = tot;
            
            for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {0, 1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > 2 || ny < 1 || ny > n || g[nx][ny] == '.')
                    continue;

                q.push({nx, ny});
            }
        }
    };

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j] && g[i][j] == '#')
            {
                tot++;
                bfs1(i, j);
            }
        }
    }

    auto bfs2 = [&](int i, int j)
    {
        queue<node> q;
        set<int> temp;
        for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {0, 1}, {1, 0}, {-1, 0}})
        {
            int nx = i + dx, ny = j + dy;
            if (nx < 1 || nx > 2 || ny < 1 || ny > n || g[nx][ny] == '.')
                continue;
            temp.insert(vis[nx][ny]);
        }
        q.push({i, j, 0, temp});

        while (!q.empty())
        {
            auto [x, y, dist, s] = q.front();
            q.pop();

            if (vis1[x][y])
                continue;
            vis1[x][y] = 1;

            // cout << x << " " << y << " " << dist << " " << s.size() << "\n";

            if (s.size() == tot)
            {
                cout << dist << "\n";
                return;
            }

            temp = s;
            for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {0, 1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > 2 || ny < 1 || ny > n)
                    continue;
                
                for (auto [dxx, dyy] : vector<pair<int, int>> {{0, -1}, {0, 1}, {1, 0}, {-1, 0}})
                {
                    int nxx = nx + dxx, nyy = ny + dyy;
                    if (nxx < 1 || nxx > 2 || nyy < 1 || nyy > n || g[nxx][nyy] == '.')
                        continue;

                    temp.insert(vis[nxx][nyy]);
                }

                if (g[nx][ny] == '.')
                    q.push({nx, ny, dist + 1, temp});
                else 
                    q.push({nx, ny, dist, temp});
            }

        }
    };

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == '#')
            {
                bfs2(i, j);
                return;
            }
        }
    }
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