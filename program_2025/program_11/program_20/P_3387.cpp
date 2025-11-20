// Problem: 【模板】缩点
// URL: https://www.luogu.com.cn/problem/P3387
// Author: amazy
// Date: 2025-11-20 10:31:27

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct TarjanSCC {
    int n, scc_count = 0, timer = 0;
    vector<int> dfn, low, bel, stk, instk;
    vector<vector<int>> adj, scc, nadj;
    // 如果adj使用0-indexed, 那么scc和nadj也是0-indexed
    // 如果adj使用1-indexed, 那么scc和nadj也是1-indexed

    TarjanSCC(int _n) : n(_n) {
        adj.resize(n);
        dfn.resize(n, 0);
        low.resize(n, 0);
        bel.assign(n, -1);
        instk.assign(n, 0);
    }

    void add(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        instk[u] = 1;

        for (auto v : adj[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (instk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u]) {
            scc.emplace_back();
            int x;
            do {
                x = stk.back();
                stk.pop_back();
                instk[x] = 0;
                bel[x] = scc_count;
                scc.back().push_back(x);
            } while (x != u);
            scc_count++;
        }
    }

    void run() {
        timer = 0;
        scc_count = 0;
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
    }

    void build() {
        nadj.assign(scc_count, {});
        vector<pair<int, int>> e;
        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                if (bel[u] != bel[v]) {
                    e.push_back({bel[u], bel[v]});
                }
            }
        }

        sort(e.begin(), e.end());
        e.erase(unique(e.begin(), e.end()), e.end());

        for (auto [u, v] : e) {
            nadj[u].push_back(v);
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    TarjanSCC tj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        tj.add(u, v);
    }  
    tj.run();
    tj.build();

    auto &adj = tj.nadj;
    auto &scc = tj.scc;
    auto &bel = tj.bel;
    vector<int> cnt(tj.scc_count);
    for (int i = 1; i <= n; i++) cnt[bel[i]] += a[i];

    map<int, int> memo;
    auto dfs = [&](auto dfs, int u) -> i64
    {
        if (memo.find(u) != memo.end()) return memo[u];
        i64 mx = 0;
        for (auto v : adj[u]) mx = max(mx, dfs(dfs, v));
        memo[u] = cnt[u] + mx;
        return cnt[u] + mx;
    };

    i64 ans = 0;
    for (int i = 1; i < tj.scc_count; i++)
    {
        ans = max(ans, dfs(dfs, i));
    }    

    cout << ans << "\n";
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