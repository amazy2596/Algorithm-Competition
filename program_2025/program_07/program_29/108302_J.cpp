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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), dist(n + 1, vector<int>(m + 1, inf));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    auto check = [&](int k)
    {
        vector<pair<int, int>> p(4);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (dist[i][j] > k)
                {
                    auto [x1, y1] = p[0];
                    if (i + j > x1 + y1 || x1 == 0)
                        p[0] = {i, j};
                    auto [x2, y2] = p[1];
                    if (i + j < x2 + y2 || x2 == 0)
                        p[1] = {i, j};
                    auto [x3, y3] = p[2];
                    if (i - j > x3 - y3 || x3 == 0)
                        p[2] = {i, j};
                    auto [x4, y4] = p[3];
                    if (i - j < x4 - y4 || x4 == 0)
                        p[3] = {i, j};
                }
            }
        }

        if (p[0].first == 0)
            return true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int mx = 0;
                for (auto [x, y] : p)
                    mx = max(mx, abs(i - x) + abs(j - y));
                if (mx <= k)
                    return true;
            }
        }

        return false;
    };

    int l = 0, r = n + m + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << "\n";
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