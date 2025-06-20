#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> mp;
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, (int)(adj[i].size() - 1));

    for (int i = 1; i <= n; i++)
        if (adj[i].size() - 1 == ans)
            mp[i]++;
    
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            cout << ans << " " << i << "\n";
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