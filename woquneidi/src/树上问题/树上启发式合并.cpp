#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
// 不能使用0下标
// 传n + 1 使用下标 1~n
struct HLD {
    HLD(const int &n) : n(n), edge(n) {
        fa = dep = son = sz = top = dfn = out = rnk = std::vector<int>(n);
    }
 
    void addEdge(const int &x, const int &y) {
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
 
    void dfs1(int u, int p) {
        sz[u] = 1;
        fa[u] = p;
        dep[u] = dep[p] + 1;
        for(const auto &v : edge[u]) {
            if(v == fa[u]) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            if(sz[son[u]] < sz[v]) {
                son[u] = v;
            }
        }
    }
    void dfs2(int u, int t, int &dfncnt) {
        dfncnt++;
        dfn[u] = dfncnt;
        rnk[dfncnt] = u;
        top[u] = t;
        if(son[u] == 0) return;
        dfs2(son[u], t, dfncnt);
        for(const auto &v : edge[u]) {
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v, dfncnt);
        }
    }
    void work(int root = 1) {
        int dfncnt = 0;
        dfs1(root, 0);
        dfs2(root, root, dfncnt);
    }
    int lca(int u, int v) {
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) {
                std::swap(u, v);
            }
            u = fa[top[u]];
        }
        return (dep[u] < dep[v] ? u : v);
    }
 
    int dis(int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
 
    // int kth(int id, int k) {
    //  if(k > dep[id]) return 0;
    //  while(dep[id] - dep[top[id]] + 1 <= k) {
    //      k -= (dep[id] - dep[top[id]] + 1);
    //      id = fa[top[id]];
    //  }
    //  return rnk[dfn[id] - k];
    // }
 
    vector<vector<int>> edge;
    vector<int> fa, dep, son, sz, top, dfn, out, rnk;
    int n;
};
 
void solve() {
    int n;
    cin >> n;
    HLD tree(n + 1);
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        tree.addEdge(u, v);
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> cnt(n + 1);
    int dif = 0;
    vector<int> ans(n + 1);
    tree.work(1);
    auto &dfn = tree.dfn;
    auto &rnk = tree.rnk;
    auto &son = tree.son;
    auto &sz = tree.sz;
 
    auto dfs = [&] (auto self, int u, int p, int keep) -> void {
 
        for (auto v : edge[u]) {
            if (v == p || v == son[u]) continue;
            self(self, v, u, 0);
        }
        if (son[u]) self(self, son[u], u, 1);
        cnt[a[u]]++;
        if (cnt[a[u]] == 1) dif++;
 
        for (auto v : edge[u]) {
            if (v == p || v == son[u]) continue;
            for (int i = dfn[v]; i <= dfn[v] + sz[v] - 1; i++) {
                cnt[a[rnk[i]]]++;
                if (cnt[a[rnk[i]]] == 1) dif++;
            }
        }
        ans[u] = dif;
 
        if (!keep) {
            dif = 0;
            for (int i = dfn[u]; i <= dfn[u] + sz[u] - 1; i++) {
                cnt[a[rnk[i]]]--;
            }
        }
 
 
    };
 
    dfs(dfs, 1, 0, 1);
    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
 
 
 
 
}
 
 
int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int T = 1;
    //cin >> T;
    while (T--) solve();
 
    return 0;
}