#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int ans = 0;
    // vector<map<int, int>> cnt(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        for (auto [v, w] : adj[u])
        {
            // cnt[u][a[v]] += w;
            if (v == p)
                continue;
            if (a[u] != a[v])
                ans += w;

            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    while (q--)
    {
        int v, c;
        cin >> v >> c;

        for (auto [u, w] : adj[v])
        {
            if (a[v] == a[u] && c != a[u])
                ans += w;
            else if (a[v] != a[u] && c == a[u])
                ans -= w;
        }

        a[v] = c;
        cout << ans << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}