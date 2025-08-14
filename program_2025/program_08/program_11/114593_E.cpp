#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1), fa(n + 1);
    auto dfs1 = [&](auto dfs1, int u, int p, int d) -> void
    {
        fa[u] = p;
        depth[u] = d;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            dfs1(dfs1, v, u, d + 1);
        }
    };
    dfs1(dfs1, 1, 0, 0);

    unordered_map<int, int> mp;
    auto dfs2 = [&](auto dfs2, int u, int p, int d, int val) -> void
    {
        if (val >= (1LL << 21)) 
            return;

        mp[val]++;

        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            int nval = (val << 1) | (s[v] - '0');
            dfs2(dfs2, v, u, d, nval);
        }
    };
    for (int u = 1; u <= n; u++)
    {
        dfs2(dfs2, u, fa[u], depth[u], s[u] - '0');
    }

    for (int i = 1; i <= n; i++)
    {
        int val = 0;
        int u = i;
        while (u != 0)
        {
            val = (val << 1) | (s[u] - '0');
            if (val >= (1LL << 21)) break;
            mp[val]++;
            u = fa[u];
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        if (mp.count(x))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}

signed main()
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