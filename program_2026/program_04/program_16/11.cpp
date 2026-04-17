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

    vector<int> siz(n + 1), dp(n + 1);
    auto dfs1 = [&](auto dfs1, int u, int p) -> void
    {
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs1(dfs1, v, u);
            siz[u] += siz[v];
            dp[u] += siz[v] + dp[v];
        }
    };

    vector<int> ans(n + 1);
    auto dfs2 = [&](auto dfs2, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p) continue;
            ans[v] = dp[v] + (ans[u] - (dp[v] + siz[v])) + (n - siz[v]);
            dfs2(dfs2, v, u);
        }
    };
    dfs1(dfs1, 1, 0);
    ans[1] = dp[1];
    dfs2(dfs2, 1, 0);

    int mn = *min_element(ans.begin() + 1, ans.end());
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == mn)
        {
            cout << i << " " << ans[i] << "\n";
            break;
        }
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