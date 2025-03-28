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

    int ans = 1e18;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    auto bfs = [&](int i, int j)
    {
        queue<pair<int, pair<int, int>>> q;
        map<pair<int, int>, int> mp;
        q.push({1, {i, j}});
        
        int num = 0, cnt = 0;
        while (!q.empty())
        {
            auto [count, p] = q.front();
            auto [x, y] = p;
            q.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            num++;

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];

                if (nx < 1 || nx > n || ny < 1 || ny > m)
                {
                    cnt++;
                    continue;
                }

                if (g[nx][ny] == '1')
                {
                    cnt++;
                    q.push({count + 1, {nx, ny}});
                }

                if (g[nx][ny] == '0')
                    mp[{nx, ny}]++;
            }
        }
        for (auto [p, val] : mp)
            cnt += val - 1;
        ans = min(ans, num * 4 - cnt);
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '1' && !vis[i][j])
            {
                bfs(i, j);
            }
        }
    }

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