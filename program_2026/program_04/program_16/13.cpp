#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<pair<int, int>>> adj(n + 10);
    for (int i = 1; i <= m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    vector<int> vis(n + 10);
    int num = 0;
    i64 ans = 1e18;
    auto dfs = [&](auto dfs, int u, int p, i64 cnt)
    {
        if (num == n - 1 && u == n)
        {
            ans = min(ans, cnt);
            return;
        }
        else if (u == n) return;
        num++;
        vis[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (v == p) continue;
            dfs(dfs, v, u, cnt + w);
        }
        num--;
        vis[u] = 0;
    };
    dfs(dfs, 1, 0, 0);

    if (ans < h) 
    {
        cout << "Yes\n";
        cout << h - ans << "\n";
    }
    else 
    {
        cout << "No\n";
        cout << ans - h + 1 << "\n";
    }
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