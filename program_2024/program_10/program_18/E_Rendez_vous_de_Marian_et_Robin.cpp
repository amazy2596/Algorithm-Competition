#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> have(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        have[x] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    auto dijkstra = [&](int x, vector<vector<int>> &a)
    {
        auto cmp = [&](pair<int, int> x, pair<int, int> y)
        {
            return make_pair(a[x.first][x.second], x) < make_pair(a[y.first][y.second], y);
        };
        set<pair<int, int>, decltype(cmp)> s(cmp);
        a[x][0] = 0;
        s.insert({x, 0});
        while (!s.empty())
        {
            auto [u, f] = *s.begin();
            s.erase(s.begin());
            bool horse = (f || have[u]);
            for (auto [v, w] : adj[u])
            {
                int dist = (horse ? w / 2 : w);
                if (a[u][f] + dist < a[v][horse])
                {
                    s.erase({v, horse});
                    a[v][horse] = a[u][f] + dist;
                    s.insert({v, horse});
                }
            }
        }
    };
    vector<vector<int>> a(n + 1, vector<int>(2, 1e18)), b(n + 1, vector<int>(2, 1e18));
    dijkstra(1, a);
    dijkstra(n, b);
    int ans = 1e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans, max(min(a[i][0], a[i][1]), min(b[i][0], b[i][1])));
    cout << (ans == 1e18 ? -1 : ans) << "\n";
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