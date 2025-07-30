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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> g(n + 1);
    auto dfs1 = [&](auto dfs, int u, int p) -> void
    {
        g[u] = gcd(g[u], a[u]);
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
            g[u] = gcd(g[u], g[v]);
        }
    };
    dfs1(dfs1, 1, 0);

    vector<int> ans(n + 1);
    auto dfs2 = [&](auto dfs, int u, int p, int val) -> void
    {
        vector<int> ch;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            ch.push_back(v);
        }

        int m = ch.size();
        vector<int> pre(m + 1), suf(m + 1);
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
                pre[i] = g[ch[i]];
            else 
                pre[i] = gcd(pre[i - 1], g[ch[i]]);

        }
        for (int i = m - 1; i >= 0; i--)
        {
            if (i == m - 1)
                suf[i] = g[ch[i]];
            else 
                suf[i] = gcd(suf[i + 1], g[ch[i]]);
        }

        int tmp;
        for (int i = 0; i < m; i++)
        {
            int v = ch[i];

            tmp = val;
            if (i == 0 && i + 1 < m)
                tmp = gcd(tmp, suf[i + 1]);
            else if (i == m - 1 && i - 1 >= 0)
                tmp = gcd(tmp, pre[i - 1]);
            else if (i - 1 >= 0 && i + 1 < m)
                tmp = gcd(tmp, gcd(pre[i - 1], suf[i + 1]));
            ans[v] = tmp;

            dfs(dfs, v, u, ans[v]);
        }
    };
    dfs2(dfs2, 1, 0, 0);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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