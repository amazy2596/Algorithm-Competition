// 不能使用0下标
// 传n + 1 使用下标 1~n
// son如果没有重儿子则为0
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