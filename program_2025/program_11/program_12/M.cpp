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
    int u;
    i64 t;
    const bool operator<(const node &o) const
    {
        return t > o.t;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) cin >> a[i];

    vector<vector<pair<int, i64>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<node> q;
    vector<i64> dist1(n + 1, INF);
    q.push({1, 0});
    dist1[1] = 0;
    while (!q.empty())
    {
        auto [u, t] = q.top();
        q.pop();

        if (dist1[u] != t) continue;

        for (auto [v, w] : adj[u])
        {
            if (dist1[u] + w < dist1[v])
            {
                dist1[v] = dist1[u] + w;
                q.push({v, dist1[v]});
            }
        }
    }

    i64 T = 0;
    for (int i = 1; i <= k; i++) T = max(T, dist1[a[i]]);

    vector<i64> dist2(n + 1, INF);
    vector<int> color(n + 1, 0);
    for (int i = 1; i <= k; i++)
    {
        q.push({a[i], 0});
        dist2[a[i]] = 0;
        color[a[i]] = i;
    }

    vector<i64> ans(k + 1, INF);
    while (!q.empty())
    {
        auto [u, t] = q.top();
        q.pop();

        if (dist2[u] != t) continue;

        for (auto [v, w] : adj[u])
        {
            if (dist2[u] + w < dist2[v])
            {
                dist2[v] = dist2[u] + w;
                color[v] = color[u];
                q.push({v, dist2[v]});
            }
        }
    }
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : adj[u])
        {
            if (color[u] != color[v])
            {
                i64 path = (dist2[u] + w + dist2[v]);
                double time1 = path / 2.0;
                double time2 = time1 - dist2[u];
                double time3 = w - time2;
                double time4 = min(dist1[u] + time2, dist1[v] + time3);
                if (time1 + time4 <= T)
                {
                    ans[color[u]] = min(ans[color[u]], path);
                    ans[color[v]] = min(ans[color[v]], path);
                }
            }
        }
    }

    cout << fixed << setprecision(1);
    for (int i = 1; i <= k; i++) cout << T - (ans[i] * 1.0 / 2) << " \n"[i == k];
}

int main()
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