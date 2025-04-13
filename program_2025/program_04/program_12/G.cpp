#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector dp(n + 1, vector<int>());

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
            dp[i].push_back(val[i]);
    }

    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        if (adj[u].size() == 1 && u != 1)
            return;

        for (int v : adj[u])
        {
            if (p == v)
                continue;

            dfs(dfs, v, u);
        }

        dp[u].resize(val[u] + 1, -1);
        dp[u][0] = 0;
        for (int v : adj[u])
        {
            if(v == p) 
                continue;

            for (int j = val[u]; j >= 0; j--)
            {
                for (int k = 0; k < dp[v].size(); k++)
                {
                    if (j >= dp[v][k] && dp[u][j - dp[v][k]] != -1)
                        dp[u][j] = max(dp[u][j], dp[u][j - dp[v][k]] + dp[v][k]);
                }
            }
        }

        vector<int> temp;
        for (int i = 0; i <= val[u]; i++)
        {
            if (dp[u][i] != -1)
                temp.push_back(dp[u][i]);
        }

        sort(temp.begin(), temp.end());
        dp[u].erase(unique(temp.begin(), temp.end()), temp.end());

        dp[u] = temp;
    };

    dfs(dfs, 1, 0);

    // cout << *max_element(dp[1].begin(), dp[1].end()) << "\n";
    cout << val[1] << "\n";
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