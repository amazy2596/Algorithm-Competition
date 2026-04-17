#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node
{
    int u;
    i64 dist;

    bool operator<(node o) const
    {
        return dist > o.dist;
    }
};

void solve()
{
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<pair<int, i64>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        i64 u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    const i64 inf = 4e18;
    vector<i64> dist(n, inf), cnt(n, 0), mx(n, 0);
    dist[s] = 0, cnt[s] = 1, mx[s] = a[s];

    priority_queue<node> pq;
    pq.push({s, 0});
    while (pq.size())
    {
        auto [u, d] = pq.top();
        pq.pop();
        
        if (dist[u] > d) continue;

        for (auto [v, w] : adj[u])
        {
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                cnt[v] = cnt[u];
                mx[v] = mx[u] + a[v];
                pq.push({v, dist[v]});
            }
            else if (d + w == dist[v])
            {
                cnt[v] += cnt[u];
                mx[v] = max(mx[v], mx[u] + a[v]);
            }
        }
    }

    cout << cnt[d] << " " << mx[d] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}