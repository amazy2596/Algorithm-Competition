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
    
    string ans(n + 1, '0');
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (a[u] == a[v])
            ans[a[u]] = '1';
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int num = a[v];
            if (vis[num] == u)
                ans[num] = '1';
            vis[num] = u;
        }
    }

    ans.erase(ans.begin());
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