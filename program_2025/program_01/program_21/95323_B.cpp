#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() > 2)
            sum++;
    }

    if (sum > 0)
    {
        cout << -1 << "\n";
        return;
    }

    vector<int> vis(n + 1), path;
    auto dfs = [&](auto dfs, int u) -> bool
    {
        vis[u] = 1;
        path.push_back(u);

        if (path.size() == n)
            return true;

        for (auto v : adj[u])
        {
            if (!vis[v])
                if (dfs(dfs, v))
                    return true;
        }

        path.pop_back();
        return false;
    };

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1 && dfs(dfs, i))
        {
            cout << *path.begin() << " " << path.back() << "\n";
            return;
        }
    }
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