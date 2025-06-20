#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector adj(n + 1, vector<int>());
    int mx = 0;
    int root = -1;
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        adj[v].push_back(i);
        if (v != 0)
        {
            d[v]++;
            mx = max(mx, d[v]);
        }
        if (v == 0)
            root = i;
    }

    for (int i = 1; i <= n; i++)
        if (d[i] != 0 && d[i] != mx)
            f = false;

    vector<int> ans;
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        ans.push_back(u);
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, root, 0);

    cout << mx << " " << (f == true ? "yes\n" : "no\n");
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
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