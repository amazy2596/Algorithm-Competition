#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
int dfs(int p, int u)
{
    for (auto v : adj[u])
        if (v != p)
            return dfs(u, v) + 1;
    return 1;
}

void solve()
{
    int n, t;
    cin >> n >> t;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u;
    cin >> u;
    vector<int> dis;
    for (auto v : adj[u])
        dis.push_back(dfs(u, v));
    if (dis.size() == 2)
    {
        if (dis[0] % 2 == 0 && dis[1] % 2 == 0)
            cout << "Hermione\n";
        else
            cout << "Ron\n";
    }
    else 
    {
        if (dis[0] % 2 == 0)
            cout << "Hermione\n";
        else
            cout << "Ron\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}