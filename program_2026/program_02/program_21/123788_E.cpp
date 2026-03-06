// Problem: 无穷无尽的树
// URL: https://ac.nowcoder.com/acm/contest/123788/E
// Author: amazy
// Date: 2026-02-21 10:18:25

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<map<int, set<int>>> has(n + 1);
    vector<int> ans(n + 1);
    auto dfs = [&](auto dfs, int u, int p, int d) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p) continue;
            // cout << "v: " << v << "\n";
            // cout << adj[v].size() << "\n";
            if (adj[v].size() == 1 && v != 1) has[u][d].insert(u);
            dfs(dfs, v, u, d + 1);
        }
        if (has[u].size() != 0)
        {
            // cout << "u: " << u << "\n";
            ans[u] = has[u].rbegin()->second.size();
            for (auto x : has[u].rbegin()->second)
                has[p][has[u].rbegin()->first].insert(x);
        }
    };
    dfs(dfs, 1, 0, 0);                                   

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main()
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