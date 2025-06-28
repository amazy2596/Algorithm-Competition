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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int s, t, w;
        cin >> s >> t >> w;
        adj[t].push_back({s, w});
    }

    auto check = [&](int x)
    {
        vector<int> dist(n + 1);
        dist[1] = min(a[1], x);
        for (int v = 2; v <= n; v++)
        {
            for (auto [u, w] : adj[v])
            {
                if (dist[u] >= w)
                    dist[v] = max(dist[v], min(dist[u] + a[v], x));
            }
        }

        return dist[n] > 0;
    };

    int l = 0, r = inf;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << (l == inf ? -1 : l) << "\n";
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