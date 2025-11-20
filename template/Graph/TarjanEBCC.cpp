#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
struct TarjanEBCC {
    int n, id = 0, timer = 0;
    vector<vector<pair<int, int>>> adj; 
    vector<int> dfn, low, bel, stk, bridge;
    int ebcc_count = 0;
    vector<vector<int>> ebcc, nadj;
    // 如果adj使用0-indexed, 那么ebcc和nadj也是0-indexed
    // 如果adj使用1-indexed, 那么ebcc和nadj也是1-indexed
    
    TarjanEBCC(int _n) : n(_n) {
        adj.resize(n);
        dfn.resize(n, 0);
        low.resize(n, 0);
        bel.assign(n, -1);
    }

    void add(int u, int v) {
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
        id++;
    }

    void dfs(int u, int fid) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);

        for (auto [v, eid] : adj[u]) {
            if (eid == fid) continue; 

            if (!dfn[v]) {
                dfs(v, eid);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    bridge[eid] = 1;
                }
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u]) {
            ebcc.emplace_back(); 
            int x;
            do {
                x = stk.back();
                stk.pop_back();
                bel[x] = ebcc_count; 
                ebcc.back().push_back(x);
            } while (x != u);
            ebcc_count++;
        }
    }

    void run() {
        bridge.assign(id, 0);
        timer = 0;
        ebcc_count = 0;
        
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfs(i, -1);
            }
        }
    }

    void build() {
        nadj.assign(ebcc_count, {});
        for (int u = 0; u < n; u++) {
            for (auto [v, eid] : adj[u]) {
                if (bridge[eid]) {
                    int x = bel[u];
                    int y = bel[v];
                    if (x < y) {
                        nadj[x].push_back(y);
                        nadj[y].push_back(x);
                    }
                }
            }
        }
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