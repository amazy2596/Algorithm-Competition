#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
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
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

// snippet-begin:
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

        sccs.emplace_back();
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
// snippet-end

void solve()
{
    
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