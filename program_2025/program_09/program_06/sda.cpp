#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 mod =  998244353;
struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n), siz(n, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> op(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        op[i] = {u, v};
    }
    vector<array<int, 31>> anc(n + 1);
    vector<int> dep(n + 1);
    vector<vector<int>> edge(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    auto dfs = [&] (auto self, int x, int p) -> void {
        anc[x][0] = p;
        dep[x] = dep[p] + 1;
        for (int i = 1; i <= 30; i++) {
            anc[x][i] = anc[anc[x][i - 1]][i - 1];
        }
        for (auto y : edge[x]) {
            if (y == p) continue;
            self(self, y, x);
        }
    };
    dfs(dfs, 1, 0);

    auto lca = [&] (int u, int v) -> int {
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

    DSU dsu(n + 1);

    i64 ans = 1;

    for (int i = 1; i < n; i++) {
        auto [u, v] = op[i];
        int z = lca(u, v);
        int ip = 0;
        int zu = u, zv = v;
        for (int i = 30; i >= 0; i--) {
            if (dsu.connected(zu, anc[zu][i])) zu = anc[zu][i];
            if (dsu.connected(zv, anc[zv][i])) zv = anc[zv][i];
        }
        if (dsu.connected(anc[zu][0], v) || dsu.connected(anc[zv][0], u)) ip = 1;


        if (ip) {
            
            ans *= qmi(dsu.size(u), mod - 2);
            ans %= mod;
            ans *= qmi(dsu.size(v), mod - 2);
            ans %= mod;
        } else {
            ans *= 0;
        }
        dsu.merge(u, v);
    }
    cout << ans << '\n';





    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;

}