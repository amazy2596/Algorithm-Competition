// Problem: 毒苯
// URL: https://ac.nowcoder.com/acm/contest/116343/F
// Author: amazy
// Date: 2025-09-01 13:15:24

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct node
{
    int x, y, v;
    
    bool operator<(const node &o) const
    {
        return v > o.v;
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    vector<vector<int>> vis(n + 1, vector<int>(m + 1, inf));
    priority_queue<node> que;
    for (int j = 1; j <= m; j++)
    {
        vis[1][j] = a[1][j];
        que.push({1, j, a[1][j]});
    }

    while (!que.empty())
    {
        auto [x, y, v] = que.top();
        que.pop();

        for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {1, 0}, {0, 1}, {0, -1}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            int t = max(v, a[nx][ny]);
            if (t < vis[nx][ny])
            {
                vis[nx][ny] = t;
                que.push({nx, ny, vis[nx][ny]});
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res.push_back(vis[i][j]);
        }
    }

    sort(res.begin(), res.end());

    while (q--)
    {
        int x;
        cin >> x;
        cout << upper_bound(res.begin(), res.end(), x) - res.begin() << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}