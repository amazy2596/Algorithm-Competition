#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int mx = *max_element(a.begin(), a.end()), num = 0;
    int tar = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < mx)
        {
            tar = max(tar, a[i]);
        }
        else 
            num++;
    }

    bool f = 0;
    auto dfs = [&](auto dfs, int p, int u) -> int
    {
        if (f)
            return 0;
        int cnt = 0;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            cnt += dfs(dfs, u, v);
        }
        if (a[u] == tar && cnt < num)
        {
            cout << u << "\n";
            f = 1;
            return 0;
        }

        return cnt + (a[u] == mx);
    };
    dfs(dfs, 0, 1);
    if (f)
        return;
    
    cout << 0 << "\n";
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