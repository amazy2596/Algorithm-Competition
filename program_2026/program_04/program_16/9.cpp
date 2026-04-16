#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> vis(n + 1);
    vector<int> nodes;
    map<int, int> circle;
    bool f = 1;
    auto dfs = [&](auto dfs, int u, int p) -> bool
    {
        if (vis[u] && f)
        {
            f = 0;
            while (nodes.size() && nodes.back() != u)
            {
                circle[nodes.back()] = 1;
                nodes.pop_back();
            }
            circle[u] = 1;
            return true;
        }
        vis[u] = 1;
        nodes.push_back(u);
        for (auto [v, i] : adj[u])
        {
            if (v == p) continue;
            if (dfs(dfs, v, u)) return true;
        }

        return false;
    };
    dfs(dfs, 1, 0);

    vector<int> cand;
    for (auto [u, _] : circle)
    {
        for (auto [v, i] : adj[u])
        {
            if (circle.find(u) != circle.end() && circle.find(v) != circle.end())
                cand.push_back(i);
        }
    }
    sort(cand.begin(), cand.end());
    cout << cand.back() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}