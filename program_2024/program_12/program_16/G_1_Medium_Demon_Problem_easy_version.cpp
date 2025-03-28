#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1), vis(n + 1);
    for (int u = 1; u <= n; u++)
    {
        int v;
        cin >> v;
        adj[u].push_back(v);
        d[v]++;
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push({i, 1});
    }

    int ans = 0;
    while (!q.empty())
    {
        auto [u, count] = q.front();
        q.pop();

        ans = max(ans, count);
        if (vis[u])
            continue;
        vis[u] = 1;

        for (auto v : adj[u])
        {
            d[v]--;
            if (d[v] == 0)
                q.push({v, count + 1});
        }
    }
    bool f = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 0)
            f = 1;
    }

    cout << ans + (f ? 2 : 0) << "\n";
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