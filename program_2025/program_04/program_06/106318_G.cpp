#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    vector adj(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }

    vector<int> pre(n + 1), dp(n + 1), in(n + 1), out(n + 1);

    int time = 0;
    auto dfs = [&](auto dfs, int u, int p, int sum) -> void
    {
        in[u] = ++time;
        sum += val[u];
        pre[u] = sum;

        int best = INT64_MIN;
        for (auto v : adj[u])
        {
            if (p == v)
                continue;
            dfs(dfs, v, u, sum);
            best = max(best, dp[v]);
        }

        out[u] = time;
        if (adj[u].size() == 0)
            dp[u] = val[u];
        else 
            dp[u] = val[u] + best;
    };

    dfs(dfs, 1, 0, 0);

    vector<int> order(n + 1);
    for (int i = 1; i <= n; i++)
        order[in[i]] = i;

    vector<int> prefix(n + 1), suffix(n + 2);
    for (int i = 1; i <= n; i++)
        prefix[i] = max(prefix[i - 1], pre[order[i]]);

    for (int i = n; i >= 1; i--)
        suffix[i] = max(suffix[i + 1], pre[order[i]]);

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int cand1 = INT64_MIN;
        cand1 = max({cand1, prefix[in[x] - 1], suffix[out[x] + 1]});
        int cand2 = pre[y] + dp[x];

        cout << max(cand1, cand2) << "\n";
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