#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i], g[i] = " " + g[i];

    auto check = [&](int i, int j)
    {
        return !(i < 1 || i > n || j < 1 || j > m || g[i][j] == '1');
    };
    auto bfs1 = [&](int i, int j, vector<vector<int>> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = 1;

            for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '1')
                    continue;
                q.push({nx, ny});
            }
        }
    };

    auto bfs2 = [&](int i, int j, vector<vector<int>> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (vis[x][y])
                continue;
            vis[x][y] = 1;

            for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {1, 0}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '1')
                    continue;
                q.push({nx, ny});
            }
        }
    };
    vector<vector<int>> visM(n + 1, vector<int>(m + 1)), vis1(n + 1, vector<int>(m + 1)), vis(n + 1, vector<int>(m + 1));
    bfs1(1, m, visM);
    bfs2(1, 1, vis1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (check(i, j) && vis1[i][j])
                vis[i][j] = max(vis[i][j], j);
            if (check(i, j) && check(i, j + 1) && vis1[i][j + 1])   
                vis[i][j] = max(vis[i][j], vis[i][j + 1]);
        }
    }

    for (int j = m; j >= 1; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            if (check(i, j) && check(i, j + 1))
                vis[i][j] = max(vis[i][j], vis[i][j + 1]);
            if (check(i, j) && check(i - 1, j))
                vis[i][j] = max(vis[i][j], vis[i - 1][j]);
            if (check(i, j) && check(i, j + 1))
                vis[i][j] = max(vis[i][j], vis[i][j + 1]);
        }

        for (int i = n; i >= 1; i--)
        {
            if (check(i, j) && check(i, j + 1))
                vis[i][j] = max(vis[i][j], vis[i][j + 1]);
            if (check(i, j) && check(i + 1, j))
                vis[i][j] = max(vis[i][j], vis[i + 1][j]);
            if (check(i, j) && check(i, j + 1))
                vis[i][j] = max(vis[i][j], vis[i][j + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis1[i][j] && !visM[i][j] && vis[i][j] >= j + k - 1)
            {
                cout << "Yes\n";
                return;
            }
        }
    }
    
    cout << "No\n";
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