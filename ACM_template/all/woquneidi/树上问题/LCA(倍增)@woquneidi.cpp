vector<int> dep(tot + 1), vis1(tot + 1);
vector<array<int, 31>> anc(n + 1); 

auto dfs1 = [&] (auto self, int u, int p) -> void{
    vis1[u] = 1;
    anc[u][0] = p;
    dep[u] = dep[p] + 1;


    for(int i = 1; i <= 30; i++) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }

    for(auto v : edge2[u]) {
        if(v == p) continue;
        self(self, v, u);
    }
};
//森林
for(int i = 1; i <= tot; i++) {
    if(!vis1[i]) dfs1(dfs1, i, 0);
}

auto lca = [&] (int u, int v) {
    int zu = u, zv = v;
    if(dep[zu] < dep[zv]) swap(zu, zv);

    int gap = dep[zu] - dep[zv];
    for(int i = 0; i <= 30; i++) {
        if(((gap) >> i) & 1) zu = anc[zu][i];
    }
    if(zu == zv) return zu;

    for(int i = 30; i >= 0; i--) {
        if(anc[zu][i] != anc[zv][i]) {
            zu = anc[zu][i];
            zv = anc[zv][i];
        }
    }
    return anc[zu][0];
};