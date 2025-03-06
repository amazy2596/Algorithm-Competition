#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int m, n;
    cin >> m >> n;
    swap(n, m);
    vector g(n + 1, vector<int>(m + 1));
    int tarX = -1, tarY = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 2)
                tarX = i, tarY = j;
        }
    }

    int k;
    cin >> k;
    map<pair<int, int>, int> mp;
    for (int x = 1; x <= k; x++)
    {
        int i, j;
        cin >> i >> j;
        swap(i, j);
        mp[{i, j}] = x;
    }

    map<int, int> count;
    auto bfs = [&](int i, int j)
    {
        vector vis(n + 1, vector<int>(m + 1));
        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> len(k + 1);
        q.push({{i, j}, 0});

        while (!q.empty())
        {
            auto [p, dist] = q.front();
            auto [x, y] = p;
            q.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = 1;

            if (mp.contains({x, y}))
            {
                int idx = mp[{x, y}];
                len[idx] = {dist, idx};
                count[dist]++;
            }

            for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] == 0)
                    continue;
                q.push({{nx, ny}, dist + 1});
            }
        }

        return len;
    };

    auto len = bfs(tarX, tarY);
    sort(len.begin() + 1, len.end());
    for (int i = 1; i < len.size(); i++)
    {
        if (count[len[i].first] == 1)
        {
            cout << len[i].second << " " << len[i].first << "\n";
            return;
        }
    }

    cout << "No winner.\n";
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