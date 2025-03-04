#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class DSU
{
    public:
        vector<int> parent, rank;

        DSU(int n)
        {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n, 1);
        }

        int find(int x)
        {
            if (x == parent[x])
                return x;
            return parent[x] = find(parent[x]);
        }

        void merge(int x, int y)
        {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY)
            {
                rank[rootX] += rank[rootY];
                rank[rootY] = 0;
                parent[rootY] = rootX;
            }
        }

        bool query(int x, int y)
        {
            return find(x) == find(y);
        }
};

void solve()
{
    int n, st, en;
    cin >> n >> st >> en;
    vector adj(n + 1, vector<int>());
    DSU dsu(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == en || v == en)
            continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dsu.merge(u, v);
    }

    vector<int> cnt;
    for (int i = 1; i <= n; i++)
    {
        if (dsu.rank[i] != 0)
            cnt.push_back(dsu.rank[i]);
    }

    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}