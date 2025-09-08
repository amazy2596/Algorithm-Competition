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
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
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

    vector<i64> dp(n + 1, INF);
    dp[1] = 0;
    auto dfs = [&](auto self, int u, int p) -> void
    {
        for (auto [v, w] : adj[u])
        {
            if (v == p) continue;
            dp[v] = dp[u] + w;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << "\n";

    for (int k = 1; k <= n; k++)
    {
        auto ndp = dp;
        for (int u = 1; u <= n; u++)
        {
            for (auto v : path[u])
            {
                ndp[v] = min(ndp[v], dp[u]);
            }
        }
        dp = move(ndp);

        vector<i64> down(n + 1, INF), up(n + 1, INF);
        auto dfs1 = [&](auto self, int u, int p) -> void
        {
            down[u] = dp[u];
            for (auto [v, w] : adj[u])
            {
                if (v == p) continue;
                self(self, v, u);
                down[u] = min(down[u], down[v] + w);
            }
        };

        auto dfs2 = [&](auto self, int u, int p) -> void
        {
            vector<pair<int, i64>> cand;
            for (auto [v, w] : adj[u])
            {
                if (v == p) continue;
                cand.push_back({v, w});
            }
            
            int siz = cand.size();
            vector<i64> pre(siz, INF), suf(siz, INF);
            for (int i = 0; i < siz; i++)
            {
                auto [v, w] = cand[i];
                if (i == 0)
                    pre[i] = down[v] + w;
                else 
                    pre[i] = min(pre[i - 1], down[v] + w);
            }

            for (int i = siz - 1; i >= 0; i--)
            {
                auto [v, w] = cand[i];
                if (i == siz - 1)
                    suf[i] = down[v] + w;
                else 
                    suf[i] = min(suf[i + 1], down[v] + w);
            }

            for (int i = 0; i < siz; i++)
            {
                auto [v, w] = cand[i];
                i64 best = INF;
                if (i != 0) best = min(best, pre[i - 1]);
                if (i != siz - 1) best = min(best, suf[i + 1]);
                up[v] = min({dp[u] + w, up[u] + w, best + w});
                self(self, v, u);
            }
        };
        dfs1(dfs1, 1, 0);
        dfs2(dfs2, 1, 0);

        for (int i = 1; i <= n; i++)
            dp[i] = min(down[i], up[i]);
        cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << "\n";
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