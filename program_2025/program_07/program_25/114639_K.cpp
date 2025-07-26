#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct TarjanSCC
{
    int n;
    vector<vector<int>> adj;

    int scc_count;
    vector<int> scc_id;
    vector<int> scc_size;
    vector<vector<int>> sccs;
    vector<vector<int>> nadj;

    int time;
    vector<int> dfn, low, in_stk;
    stack<int> stk;

    TarjanSCC(int _n) : n(_n), scc_count(0), time(0)
    {
        adj.resize(n + 1);
        scc_id.resize(n + 1);
        scc_size.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        in_stk.resize(n + 1);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
    }

    void run()
    {
        auto tarjan = [&](auto tarjan, int u) -> void
        {
            dfn[u] = low[u] = ++time;
            stk.push(u);
            in_stk[u] = 1;

            for (auto v : adj[u])
            {
                if (!dfn[v])
                {
                    tarjan(tarjan, v);
                    low[u] = min(low[u], low[v]);
                }
                else if (in_stk[v])
                    low[u] = min(low[u], dfn[v]);
            }

            if (dfn[u] == low[u])
            {
                scc_count++;
                sccs.emplace_back();
                int node;
                do
                {
                    node = stk.top();
                    stk.pop();

                    in_stk[node] = 0;
                    scc_id[node] = scc_count;
                    scc_size[scc_count]++;
                    sccs.back().push_back(node);
                } while (node != u);
            }
        };

        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
            {
                tarjan(tarjan, i);
            }
        }
    }

    void build()
    {
        nadj.resize(scc_count + 1);
        vector<pair<int, int>> e;
        for (int u = 1; u <= n; u++)
        {
            for (int v : adj[u])
            {
                if (scc_id[u] != scc_id[v])
                {
                    e.push_back({scc_id[u], scc_id[v]});
                }
            }
        }

        sort(e.begin(), e.end());
        e.erase(unique(e.begin(), e.end()), e.end());

        for (auto [u, v] : e)
            nadj[u].push_back(v);
    }
};

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e.push_back({u, v});
    }

    TarjanSCC tj(n + 1);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        tj.add(u, v);
    }

    tj.run();

    DSU dsu1(n + 1), dsu2(n + 1);;
    for (auto [u, v] : e)
    {
        dsu1.merge(u, v);
        if (tj.scc_id[u] != tj.scc_id[v])
            dsu2.merge(tj.scc_id[u], tj.scc_id[v]);
    }

    for (int i = 0; i < tj.scc_count; i++)
    {
        set<int> s;
        for (auto u : tj.sccs[i])
        {
            s.insert(dsu1.find(u));
        }

        if (s.size() != 1)
        {
            cout << "NO\n";
            return;
        }
    }

    tj.build();
    for (int u = 0; u < tj.scc_count; u++)
    {
        for (auto v : tj.nadj[u])
        {
            if (!dsu2.connected(u, v))
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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