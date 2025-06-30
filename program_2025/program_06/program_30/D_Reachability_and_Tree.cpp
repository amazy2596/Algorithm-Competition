#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



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

    vector<pair<int, int>> ans;
    int k = -1;
    for (int u = 1; u <= n; u++)
    {
        if (adj[u].size() == 2)
        {
            k = u;
            break;
        }
    }

    if (k == -1)
    {
        cout << "NO\n";
        return;
    }

    auto dfs = [&](auto dfs, int u, int p, int op) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            if (op % 2 == 0)
                ans.push_back({u, v});
            else 
                ans.push_back({v, u});

            dfs(dfs, v, u, op ^ 1);
        }
    };

    // u -> k -> v
    int u = adj[k][0];
    int v = adj[k][1];

    ans.push_back({u, k});
    dfs(dfs, u, k, 0);

    ans.push_back({k, v});
    dfs(dfs, v, k, 1);

    cout << "YES\n";
    for (auto [u, v] : ans)
        cout << u << " " << v << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}