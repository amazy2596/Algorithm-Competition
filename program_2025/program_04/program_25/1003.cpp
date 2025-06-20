#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        int r;
        cin >> r;
        for (int k = 0; k < r; k++)
        {
            int j;
            cin >> j;
            g[i][j] = 1;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (g[i][j] == 1)
    //             cout << "#";
    //         else 
    //             cout << "*";
    //     }
    //     cout << "\n";
    // }
    // #******
    // *#*##*#
    // ******#
    // #******
    // *##*###
    // *##*#*#
    // *#####*
    // ####***

    int ans = INT64_MAX;
    queue<array<int, 3>> q;
    vector vis(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        if (g[i][1] != 1)
            q.push({i, 1, 1});
    }

    while (!q.empty())
    {
        auto [x, y, dist] = q.front();
        q.pop();

        if (vis[x][y])
            continue;
        vis[x][y] = 1;

        if (y == m)
        {
            ans = dist;
            break;
        }

        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 0 || ny > m || g[nx][ny] == 1)
                continue;

            q.push({nx, ny, dist + 1});
        }
    }

    cout << ans << "\n";
}

signed main()
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