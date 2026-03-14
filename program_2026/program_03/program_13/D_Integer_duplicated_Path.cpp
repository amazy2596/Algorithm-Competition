// Problem: D - Integer-duplicated Path
// URL: https://atcoder.jp/contests/abc448/tasks/abc448_d
// Author: amazy
// Date: 2026-03-13 11:21:17

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    map<int, int> mp;
    vector<int> ans(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        mp[a[u]]++;
        if (mp[a[u]] >= 2) ans[u] = 1, cnt++;
        if (cnt > 0) ans[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
        mp[a[u]]--;
        if (mp[a[u]] >= 1) cnt--;
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) cout << (ans[i] ? "Yes\n" : "No\n");
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