#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 3>> edge(m);
    vector<vector<int>> adj(n + 1);
    for (auto &[w, u, v] : edge)
    {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(edge.begin(), edge.end());
    DSU dsu(n + 1);
    i64 ans = 0, tot = n;
    for (auto [w, u, v] : edge)
    {
        if (dsu.connected(u, v))
            continue;
        tot--;
        u = dsu.find(u);
        v = dsu.find(v);

        if (adj[u].size() < adj[v].size())
            swap(u, v);

        int sizU = dsu.size(u);
        int sizV = dsu.size(v);

        i64 num = 1LL * sizU * sizV;

        for (auto x : adj[v])
        {
            if (dsu.find(x) == u)
                num--;
            adj[u].push_back(x);
        }

        dsu.merge(u, v);
        swap(adj[u], adj[dsu.find(u)]);
        ans = (ans + num * (w - 1)) % mod;
    }

    if (tot > 2)
    {
        cout << "0\n";
        return;
    }

    if (tot == 2)
    {
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(dsu.find(i));

        int u = *s.begin(), v = *s.rbegin();

        cout << 1LL * dsu.size(u) * dsu.size(v) % mod * k % mod % mod << "\n";
        return;
    }

    cout << ans % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}