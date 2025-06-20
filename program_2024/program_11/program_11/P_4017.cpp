#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 80112002;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1), out(n + 1), num(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++, out[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            num[i] = 1;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (--in[v] == 0)
                q.push(v);
            num[v] = (num[v] + num[u]) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (out[i] == 0)
            ans = (ans + num[i]) % mod;
    cout << ans << "\n";
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