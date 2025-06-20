#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int x, y, time, can;
    bool operator<(const node &other) const
    {
        return time > other.time;
    }
};


void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector g(n + 1, vector<char>(m + 1));
    vector<pair<int, int>> init;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == '*')
                init.push_back({i, j});
        }
    }

    int ans = INT64_MAX;
    auto bfs = [&]()
    {
        vector vis(n + 1, vector<int>(m + 1, 0));
        priority_queue<node> q;
        for (auto [i, j] : init)
            q.push({i, j, 0, 1});
        
        while (!q.empty())
        {
            auto [x, y, time, can] = q.top();
            q.pop();

            if (vis[x][y] && can != 1)
                continue;
            vis[x][y] = 1;

            if (g[x][y] == '%')
            {
                ans = min(ans, time);
                return;
            }

            if (x + 1 <= n && g[x + 1][y] != '#')
                q.push({x + 1, y, time + 1, 1});
            else if (x + 1 <= n && g[x + 1][y] == '#')
            {
                if (y - 1 >= 1 && g[x][y - 1] != '#')
                    q.push({x, y - 1, time + 1, 0});
                if (y + 1 <= m && g[x][y + 1] != '#')
                    q.push({x, y + 1, time + 1, 0});

                if (can && !vis[x + 1][y])
                    q.push({x + 1, y, time + h + 1, 1});
            }
        }
    };

    bfs();
    cout << (ans == INT64_MAX ? -1 : ans) << "\n";
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