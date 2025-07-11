#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
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
    int n;
    cin >> n;
    DSU dsu(n);
    vector<int> w(n + 1);
    map<int, vector<int>> group;
    for (int i = 1; i <= n; i++)
        cin >> w[i], group[w[i]].push_back(i);

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<int> vis(n + 1);
    for (auto it = group.rbegin(); it != group.rend(); it++)
    {
        auto &[val, vec] = *it;

        if (it != group.rbegin())
        {
            auto &[pre, pvec] = *prev(it);
            for (auto u : pvec)
            {
                vis[u] = 1;
                for (auto v : adj[u])
                {
                    if (vis[v])
                        dsu.merge(u, v);
                }
            }
        }

        map<int, int> cnt;
        for (auto u : vec)
        {
            for (auto v : adj[u])
            {
                if (!vis[v])
                    continue;
                int root = dsu.find(v);
                cnt[root]++;
            }
        }

        for (auto [root, c] : cnt)
            ans += c * (c - 1);

        for (auto u : vec)
        {
            for (auto v : adj[u])
            {
                if (u < v && w[v] == val)
                    ans += 2;
            }
        }

        for (auto u : vec)
        {
            vis[u] = 1;
            for (auto v : adj[u])
            {
                if (vis[v])
                    dsu.merge(u, v);
            }
        }
    }

    cout << ans << "\n";
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