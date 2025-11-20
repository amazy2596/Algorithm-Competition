// Problem: D. Catshock
// URL: https://codeforces.com/contest/2154/problem/D
// Author: amazy
// Date: 2025-11-05 08:16:52

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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1), fa(n + 1), ch(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void
    {
        fa[u] = p;
        depth[u] = depth[p] + 1;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            self(self, v, u);
            ch[u]++;
        }
    };
    dfs(dfs, n, 0);

    vector<vector<int>> leaf(2);
    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == 0) 
        {
            leaf[depth[i] & 1].push_back(i);
        }
    }

    vector<pair<int, int>> ans;
    int cur = depth[1] & 1;
    for (int i = 1; i < n; i++)
    {
        if (leaf[cur ^ 1].empty())
        {
            ans.push_back({1, 0});
            cur ^= 1;
        }

        int v = leaf[cur ^ 1].back();
        leaf[cur ^ 1].pop_back();
        ans.push_back({2, v});

        int p = fa[v];
        ch[p]--;
        if (ch[p] == 0) leaf[depth[p] & 1].push_back(p);

        ans.push_back({1, 0});
        cur ^= 1;
    }

    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
    {
        if (x == 1) cout << x << "\n";
        else cout << x << " " << y << "\n";
    }
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