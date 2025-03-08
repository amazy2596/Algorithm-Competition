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
    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());
    map<pair<int, int>, int> mp;
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, z;
        cin >> u >> v >> z;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}] = z;
        mp[{v, u}] = z;
        dsu.merge(u, v);
    }

    bool f1 = 1;
    vector<int> a(n + 1), vis(n + 1);
    for (int k = 0; k <= 31; k++)
    {
        vis.assign(n + 1, 0);
        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                if (vis[v])
                {
                    if ((a[u] >> k & 1) ^ (a[v] >> k & 1) != (mp[{u, v}] >> k & 1))     
                    {
                        f1 = 0;
                        break;
                    }
                    continue;
                }
                vis[v] = 1;

                if ((mp[{u, v}] >> k & 1) == 1)
                    a[v] |= (1ll << k);
            }
            vis[u] = 1;
            if (!f1)
                break;
        }
        if (!f1)
            break;
    }

    map<int, int> count1;
    if (f1)
    {
        for (int u = 1; u <= n; u++)
            count1[dsu.find(u)] += a[u];
    }

    bool f2 = 1;
    a.resize(n + 1), vis.resize(n + 1);
    for (int k = 0; k <= 31; k++)
    {
        vis.assign(n + 1, 0);
        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                if (vis[v])
                {
                    if ((a[u] >> k & 1) ^ (a[v] >> k & 1) != (mp[{u, v}] >> k & 1))     
                    {
                        f2 = 0;
                        break;
                    }
                    continue;
                }
                vis[v] = 1;

                if (!vis[u])
                    a[u] |= (1ll << k);

                if ((mp[{u, v}] >> k & 1) == 0)
                    a[v] |= (1ll << k);
            }
            vis[u] = 1;
            if (!f2)
                break;
        }
        if (!f2)
            break;
    }

    map<int, int> count2;
    if (f2)
    {
        for (int u = 1; u <= n; u++)
            count2[dsu.find(u)] += a[u];
    }

    if (count1.size() == 0 && count2.size() == 0)
    {
        cout << "-1\n";
        return;
    }

    int ans = 0, temp = 0;
    for (auto [key, val] : count1)
        temp += max(val, count2[key]);
    ans = max(ans, temp);

    temp = 0;
    for (auto [key, val] : count2)
        temp += max(val, count1[key]);
    ans = max(ans, temp);

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