#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        g[i] = " " + g[i];
    }

    vector<pair<pair<int, int>, pair<int, int>>> ans;
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto bfs = [&](int i, int j) -> void
    {
        vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
        vector<vector<pair<int, int>>> pre(n + 1, vector<pair<int, int>>(n + 1));
        queue<pair<int, int>> q;
        q.push({i, j});
        d[i][j] = 1;

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (g[x][y] == '1')
            {
                while (x != i || y != j)
                {
                    auto [nx, ny] = pre[x][y];
                    swap(g[x][y], g[nx][ny]);
                    ans.push_back({{x, y}, {nx, ny}});
                    x = nx, y = ny;
                }
                return;
            }

            for (int k = 0; k < 4; k++) 
            {
                auto [dx, dy] = dir[k];
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > n)
                    continue;
                if (vis[nx][ny] || d[nx][ny])
                    continue;
                d[nx][ny] = 1;

                pre[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    };

    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {
            if (g[i][j] == '0')
            {
                bfs(i, j);
            }
            vis[i][j] = 1;
        }
    }

    cout << ans.size() << "\n";
    for (auto [p1, p2] : ans)
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << g[i][j] << " ";
    //     cout << "\n";
    // }

}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}