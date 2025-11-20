// Problem: F. Tree, TREE!!!
// URL: https://codeforces.com/contest/2167/problem/F
// Author: amazy
// Date: 2025-10-28 22:57:29

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> siz(n + 1), fa(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        fa[u] = p;
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs(dfs, v, u);
            siz[u] += siz[v];
        }
    };
    dfs(dfs, 1, 0);

    i64 ans = n;
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            if (v == fa[u])
            {
                if (siz[u] >= k)
                {
                    ans += (n - siz[u]);
                }
            }
            else if (fa[v] == u)
            {
                if (n - siz[v] >= k)
                {
                    ans += siz[v];
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}