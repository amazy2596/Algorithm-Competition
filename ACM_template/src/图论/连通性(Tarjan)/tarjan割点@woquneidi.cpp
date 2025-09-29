#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct VBCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<vector<int>> ecc;
    vector<int> dfn, low;
    int cur, tot;
    VBCC(int n) {
        init(n);
    }

    void init(int n){
        this->n = n;
        adj.assign(n + 1, {});
        ecc.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.resize(n + 1);
        stk.clear();
        cur = tot = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        dfn[u] = low[u] = ++cur;
        stk.push_back(u);
        int child = 0;
        for(auto v : adj[u]) {
            if(!dfn[v]) {
                child++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dfn[u]) {
                    ++tot;
                    while(1) {
                        int now = stk.back();
                        stk.pop_back();
                        ecc[tot].push_back(now);
                        if(now == v) break;
                    }
                    ecc[tot].push_back(u);
                }
            } else if(v != p) {
                low[u] = min(low[u], dfn[v]);
            }
        } 

        if(p == -1 && child == 0) { 
            ++tot;
            ecc[tot].push_back(u);
        }
    }

    vector<vector<int>> work() {
        for(int i = 1; i <= n; ++i) {
            if(!dfn[i]) {
                dfs(i, -1);
            }
        }
        return ecc;
    }

}; 

void solve(){
    int n, m;
    cin >> n >> m;
    VBCC g(n);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    auto ecc = g.work();
    int tot = g.tot;

    cout << tot << '\n';

    for(int i = 1; i <= tot; i++) {
        cout << ecc[i].size() << ' ';
        for(auto x : ecc[i]) cout << x << ' ';
        cout << '\n';
    }
}