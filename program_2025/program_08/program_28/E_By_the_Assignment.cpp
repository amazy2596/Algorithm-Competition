// Problem: E. By the Assignment
// URL: https://codeforces.com/contest/2136/problem/E
// Author: amazy
// Date: 2025-08-29 00:35:19

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 998244353;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct TarjanEBCC
{
    int n, id = 0, ebcc_count = 0, timer = 0;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> ebcc, nadj;
    vector<int> dfn, low, bel, stk;
    vector<bool> bridge, instk;
    
    TarjanEBCC(int _n) : n(_n)
    {
        instk.resize(n + 1);
        adj.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        bel.resize(n + 1);
        ebcc.resize(1);
    }

    void add(int u, int v)
    {
        id++;
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
    }

    void dfs(int u, int fid)
    {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        instk[u] = true;

        for (auto [v, eid] : adj[u])
        {
            if (eid == fid) continue;

            if (!dfn[v])
            {
                dfs(v, eid);
                low[u] = min(low[u], low[v]);

                if (low[v] > dfn[u]) 
                    bridge[eid] = true;
            }
            else if (instk[v])
                low[u] = min(low[u], dfn[v]);
        }

        if (dfn[u] == low[u])
        {
            ebcc_count++;
            ebcc.emplace_back();
            while (true)
            {
                int x = stk.back();
                stk.pop_back();
                instk[x] = false;
                bel[x] = ebcc_count;
                ebcc.back().push_back(x);
                if (x == u) break;
            }
        }
    }

    void run()
    {
        bridge.assign(id + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
            {
                dfs(i, -1);
            }
        }
    }

    void build()
    {
        nadj.assign(ebcc_count + 1, {});
        for (int u = 1; u <= n; u++)
        {
            for (auto [v, id] : adj[u])
            {
                if (bridge[id])
                {
                    int x = bel[u];
                    int y = bel[v];
                    if (x > y) 
                    {
                        nadj[x].push_back(y);
                        nadj[y].push_back(x);
                    }
                }
            }
        }
    }
};

void solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    TarjanEBCC ebcc(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ebcc.add(u, v);
    }
    ebcc.run();

    i64 ans = 1;
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= ebcc.ebcc_count; i++)
    {
        queue<int> q;
        set<int> exist;

        q.push(ebcc.ebcc[i][0]);
        color[ebcc.ebcc[i][0]] = 0;
        exist.insert(a[ebcc.ebcc[i][0]]);
        bool ok = true;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto [v, id] : ebcc.adj[u])
            {
                if (ebcc.bridge[id]) continue;
                if (ebcc.bel[v] != i) continue;
                exist.insert(a[v]);
                if (color[v] == -1)
                {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[u] == color[v])
                    ok = false;
            }
        }
        if (exist.count(-1))
            exist.erase(-1);

        if (exist.size() >= 2)
        {
            cout << "0\n";
            return;
        }
        if (!ok && !exist.empty() && *exist.rbegin() > 0)
        {
            cout << "0\n";
            return;
        }

        if (ok && exist.empty())
            ans = (ans * v) % mod;
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