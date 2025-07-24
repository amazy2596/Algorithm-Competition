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

    vector<vector<int>> canToM(n + 1, vector<int>(m + 1));
    vector<vector<int>> can(n + 1, vector<int>(m + 1));
    bfs1(1, m, canToM);

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
                if (y < m - k - 1)
                {
                    if (!canToM[nx][ny])
                    {
                        cout << "Yes\n";
                        return true;
                    }
                    q.push({nx, ny});
                }
            }
        }

        return false;
    };

    if (!bfs2(1, 1, can))
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