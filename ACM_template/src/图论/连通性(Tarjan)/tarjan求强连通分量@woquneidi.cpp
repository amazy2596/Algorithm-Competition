#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    // vector<vector<int>> ecc;
    int cur, tot;
    SCC(int n) {
        init(n);
    }

    void init(int n){
        this->n = n;
        adj.assign(n + 1, {});
        // ecc.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.resize(n + 1);
        bel.assign(n + 1, 0);
        stk.clear();
        cur = tot = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++cur;
        stk.push_back(u);
        for(auto v : adj[u]) {
            if(!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if(bel[v] == 0) {
                low[u] = min(low[u], low[v]);
            }
        } 

        if(low[u] == dfn[u]) {
            ++tot;
            while(1) {
                int now = stk.back();
                // ecc[tot].push_back(now);
                bel[now] = tot;
                stk.pop_back();
                if(now == u) break;
            }
        }
    }

    vector<int> work() {
        for(int i = 1; i <= n; ++i) {
            if(!dfn[i]) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<vector<int>> edge1(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    SCC g(n);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
        edge1[u].push_back(v);
    }

    auto bel = g.work();

    int tot = g.tot;
    vector<int> val(tot + 1), vis(tot + 1), ans(tot + 1);
    vector<vector<int>> edge2(tot + 1);

    for(int i = 1; i <= n; i++) {
        val[bel[i]] += a[i];
        for(auto j : edge1[i]) {
            if(bel[i] != bel[j]) edge2[bel[i]].push_back(bel[j]);
        }
    }
    int res = 0;
    auto dfs = [&] (auto self, int u, int p) -> void {
        if(vis[u]) return;
        vis[u] = p;
        for(auto v : edge2[u]) {
            if(vis[v] != u) {
                self(self, v, u);
                ans[u] = max(ans[u], ans[v]);
            } 
            
        }
        ans[u] += val[u];
        res = max(res, ans[u]);
    };
    for(int i = 1; i <= tot; i++) {
        if(!vis[i]) {
            dfs(dfs, i, -1);
        }
    }
    cout << res << '\n';
    
}