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
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n + 1, 1);
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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> g1(m1), g2(m2);
    DSU dsu1(n + 1), dsu2(n + 1);
    for (int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;
        g1[i] = {u, v};
    }

    set<int> s;
    for (int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;
        g2[i] = {u, v};
        dsu2.merge(u, v);
        s.insert(u);
        s.insert(v);
    }

    int ans = 0;
    for (auto [u, v] : g1)
    {
        if (!dsu2.query(u, v) || !s.count(u) || !s.count(v))
            ans++;
        else 
            dsu1.merge(u, v);
    }   

    for (auto [u, v] : g2)
    {
        if (!dsu1.query(u, v))
        {
            dsu1.merge(u, v);
            ans++;
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}