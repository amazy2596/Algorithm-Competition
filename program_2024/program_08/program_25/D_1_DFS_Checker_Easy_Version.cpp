#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;
vector<int> dfs_order;
vector<int> vis(N);
vector<vector<int>> adj(N);

void dfs(int node)
{
    vis[node] = true;
    dfs_order.push_back(node);

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!vis[adj[node][i]])
            dfs(adj[node][i]);
    }
}

void solve()
{
    vis.resize(N, 0);
    adj.resize(N);
    int n, q;
    cin >> n >> q;
    for (int v = 2; v < n; v++)
    {
        int u;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
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