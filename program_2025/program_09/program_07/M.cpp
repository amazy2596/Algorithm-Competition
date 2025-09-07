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



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, i64>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        i64 u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> path(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<i64> base(n + 1, INF), down(n + 1, INF), up(n + 1, INF);
    base[1] = 0;
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        for (auto [v, w] : adj[u])
        {
            if (v == p) continue;
            base[v] = base[u] + w;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
    cout << accumulate(base.begin() + 1, base.end(), 0LL) << "\n";

    auto dp = base;
    for (int k = 1; k <= n; k++)
    {
        auto ndp = dp;
        for (int u = 1; u <= n; u++)
        {
            for (auto v : path[u])
            {
                ndp[u] = min(ndp[u], dp[v]);
            }
        }
        dp.swap(ndp);

        auto dfs1 = [&](auto dfs1, int u, int p) -> void
        {
            down[u] = dp[u];
            for (auto [v, w] : adj[u])
            {
                if (v == p) continue;
                dfs1(dfs1, v, u);
                down[u] = min(down[u], down[v] + w);
            }
        };

        auto dfs2 = [&](auto dfs2, int u, int p) -> void
        {
            int siz = adj[u].size();
            vector<i64> cand(siz, INF), pre(siz, INF), suf(siz, INF);
            for (int i = 0; i < siz; i++) 
            {
                auto [v, w] = adj[u][i];
                if (v != p) cand[i] = down[v] + w;
            }

            for (int i = 0; i < siz; i++)      
                pre[i] = (i == 0 ? cand[i] : min(pre[i - 1], cand[i]));
            for (int i = siz - 1; i >= 0; i--)   
                suf[i] = (i == siz - 1 ? cand[i] : min(suf[i + 1], cand[i]));

            for (int i = 0; i < siz; i++)
            {
                auto [v, w] = adj[u][i];
                if (v == p) continue;
                i64 mn = INF;
                if (i > 0) mn = min(mn, pre[i - 1]);
                if (i < siz - 1) mn = min(mn, suf[i + 1]);

                i64 best = min({up[u], dp[u], mn});
                up[v] = (best >= INF ? INF : best + w);

                dfs2(dfs2, v, u);
            }
        };

        fill(down.begin(), down.end(), INF);
        fill(up.begin(), up.end(), INF);
        dfs1(dfs1, 1, 0);
        dfs2(dfs2, 1, 0);

        for (int i = 1; i <= n; i++)
            dp[i] = min(down[i], up[i]);
        cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << "\n";
    }
}

int main()
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