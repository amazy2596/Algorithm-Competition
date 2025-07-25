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
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    uint cur = (1ll << 32) - 1;
    map<int, int> cnt;
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        uint tmp = cur;

        cnt[popcount(cur & w[u])]++;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            cur &= w[u];
            dfs(dfs, v, u);
            cur = tmp;
        }
    };
    dfs(dfs, 1, 0);

    while (q--)
    {
        int x;
        cin >> x;

        cout << cnt[x] << "\n";
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