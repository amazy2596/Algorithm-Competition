#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n + 1);
    vector bucket(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bucket[a[i]].push_back(i);
    }

    auto getId1 = [&](int u, int k)
    {
        return (u - 1) * 3 + k;
    };

    auto getId2 = [&](int c, int k)
    {
        return 3 * n + (c - 1) * 3 + k;
    };

    int total = 6 * n;
    vector<vector<pair<int, int>>> adj(total);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        for (int k = 0; k < 3; k++)
        {
            int from = getId1(u, k);
            int to = getId1(v, (k + 1) % 3);
            adj[from].push_back({to, d});
        }
    }

    for (int c = 1; c <= n; c++)
    {
        auto &v = bucket[c];
        if (v.empty())
            continue;
        for (int k = 0; k < 3; k++)
        {
            int next = getId2(c, (k + 1) % 3);
            int cur = getId2(c, k);
            for (auto u : v)
            {
                adj[getId1(u, k)].push_back({next, x});
                adj[cur].push_back({getId1(u, k), 0});
            }
        }
    }

    int s = getId1(1, 0), t = getId1(n, 0);
    vector<int> dist(total, 1e18l);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();

        if (d > dist[u])
            continue;
        if (u == t)
            break;
        for (auto &[v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                q.push({dist[v], v});
            }
        }
    }

    int ans = dist[t];
    cout << (ans == 1e18l ? -1 : ans) << "\n";
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