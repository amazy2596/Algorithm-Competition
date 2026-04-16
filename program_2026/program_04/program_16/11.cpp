#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto dfs, int u, int p, int d) -> int
    {
        int res = d;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            res += dfs(dfs, v, u, d + 1);
        }
        return res;
    };

    vector<pair<int, int>> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[i].first = dfs(dfs, i, 0, 0);
        ans[i].second = i;
    }

    sort(ans.begin() + 1, ans.end());
    cout << ans[1].second << " " << ans[1].first << "\n";
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