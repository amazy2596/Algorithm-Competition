// 倍增求LCA
// 预处理O(nlogn) 单次查询O(logn)
void solve1(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> edge(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
 
    vector<int> dep(n + 1);
    vector<vector<int>> anc(n + 1, vector<int>(31));
    auto dfs = [&] (auto self, int x, int f) -> void {
        dep[x] = dep[f] + 1;
        anc[x][0] = f;
        for(int i = 1; i < 31; i++) {
            anc[x][i] = anc[anc[x][i - 1]][i - 1];
        }
 
        for(auto y : edge[x]) {
            if(y == f) continue;
            self(self, y, x);
        }
 
    };
    dfs(dfs, s, 0);
    auto lca = [&] (int x, int y) -> int{
        if(dep[x] > dep[y]) swap(x, y);
        int gap = dep[y] - dep[x];
        for(int i = 0; i <= 30; i++) {
            if((gap >> i) & 1) y = anc[y][i];
        }
        if(x == y) return x;
        for(int i = 30; i >= 0; i--) {
            if(anc[x][i] != anc[y][i]) {
                x = anc[x][i];
                y = anc[y][i];
            }
        }
        return anc[x][0];
 
    };
    while(m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
 
 
 
}




//tarjan离线求LCA
//节点数n 查询数m O(n + m)
void solve2() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> edge(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) p[i] = i;
    auto chazu = [&](auto self, int x) -> int {
        if(x != p[x]) p[x] = self(self, p[x]);
        return p[x];
    };
    vector<int> ans(m + 1), st(n + 1);
    vector<vector<info>> que(n + 1);
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        que[a].push_back({b, i});
        que[b].push_back({a, i});
    }
 
    auto dfs = [&] (auto self, int x, int f) -> void {
        st[x] = 1;
        
        for(auto y : edge[x]) {
            if(y == f) continue;
            self(self, y, x);
        }
        for(auto [y, idx] : que[x]) {
            if(st[y]) ans[idx] = chazu(chazu, y);
        }
        
 
        p[x] = f;
 
 
    };
    dfs(dfs, s, 0);
 
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
 
 
 
 
}