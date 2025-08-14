#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

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

    vector<int> depth(n + 1), siz(n + 1);
    auto dfs = [&](auto dfs, int u, int p, int deep) -> void
    {
        depth[u] = deep;
        siz[depth[u]]++;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            dfs(dfs, v, u, deep + 1);
        }
    };
    dfs(dfs, 1, 0, 0);

    i64 ans = 0;
    for (int d = 1; d <= n; d++)
        ans += 1LL * siz[d] * (siz[d] - 1) / 2;

    for (int d = 2; d <= n; d += 2)
        ans += siz[d];

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}