#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int i, j, col;
};


void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<node> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].i >> a[i].j >> a[i].col;

    vector<vector<int>> adj(3 * n + 1, vector<int>());
    for (int k = 0; k < m; k++)
    {
        auto [i, j, col] = a[k];
        bool f = 0;
        int x = ceil(j * 1.0 / 2), y = 2 * n - i + 1, z = 2 * n + i - j / 2;

        if (col == x)
        {
            adj[y].emplace_back(x);
            adj[z].emplace_back(x);
            f = 1;
        }
        else if (col == y)
        {
            adj[x].emplace_back(y);
            adj[z].emplace_back(y);
            f = 1;
        }
        else if (col == z)
        {
            adj[x].emplace_back(z);
            adj[y].emplace_back(z);
            f = 1;
        }

        if (!f)
        {
            cout << "No\n";
            return;
        }
    }

    vector<int> vis(3 * n + 1);
    auto dfs = [&](auto dfs, int u) -> bool
    {
        vis[u] = 1;

        for (auto v : adj[u])
        {
            if (vis[v] == 0)
            {
                if (!dfs(dfs, v))
                    return false;
            }
            else if (vis[v] == 1)
                return false;
        }

        vis[u] = 2;
        return true;
    };

    for (int u = 1; u <= 3 * n; u++)
    {
        if (vis[u] == 0)
        {
            if (!dfs(dfs, u))
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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