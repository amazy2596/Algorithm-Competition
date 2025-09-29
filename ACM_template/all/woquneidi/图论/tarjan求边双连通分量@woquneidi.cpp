#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


struct EBCC {
    int n;
    vector<vector<int>> adj;
    vector<int> e;
    vector<int> stk;
    vector<int> dfn, low, bel;
    // vector<vector<int>> ecc;
    // vector<pair<int, int>> bridge; //割边
    int cur, tot;
    EBCC(int n) {
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
        e.clear();
        cur = tot = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(e.size());
        e.emplace_back(v);
        adj[v].push_back(e.size());
        e.emplace_back(u);
    }

    void dfs(int u, int laeid) {
        dfn[u] = low[u] = ++cur;
        stk.push_back(u);
        for(auto eid : adj[u]) {
            int v = e[eid];
            if(!dfn[v]) {
                dfs(v, eid);
                low[u] = min(low[u], low[v]);
            } else if(eid != (laeid ^ 1)) {
                low[u] = min(low[u], dfn[v]);
            }
        } 

        if(low[u] == dfn[u]) { 
            ++tot;
            // if(laeid != -1) bridge.push_back({u, e[laeid ^ 1]});
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
                dfs(i, -1);
            }
        }
        return bel; // bel : 每个点在哪个连通分量
    }


}; 
// 点下标为1~n是, 传的参数n应该为n而不是n+1
// ecc可求出每个点在哪个连通分量 下标是 1~tot
// bel是每个点属于哪个连通分量 分量标号是1~tot
// tot是连通分量的个数 
// bridge存的是每个割边的两个顶点



void solve(){
    int n, m;
    cin >> n >> m;
    EBCC g(n);

    for(int i = 1; i <= m; i++)  {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    auto bel = g.work();
    int tot = g.tot;
    cout << tot << '\n';

    vector<vector<int>> ebcc(tot + 1);

    for(int i = 1; i <= n; i++) {
        ebcc[bel[i]].push_back(i);
    }

    for(int i = 1; i <= tot; i++) {
        cout << ebcc[i].size() << ' ';
        for(auto it : ebcc[i]) cout << it << ' ';
            cout << '\n';
    }





    
}


int main(){
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T = 1;
    //cin >> T;
    while(T--) solve();

    return 0;
}