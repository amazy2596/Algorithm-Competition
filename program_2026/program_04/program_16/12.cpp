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
    vector<i64> dists(n, inf), distd(n, inf);
    dists[s] = 0;
    distd[d] = 0;

    auto djk = [&](int x, vector<i64> &d)
    {
        priority_queue<node> pq;
        pq.push({x, 0});
        while (pq.size())
        {
            auto [u, dist] = pq.top();
            pq.pop();
            
            // if (d[u] > dist) continue;

            for (auto [v, w] : adj[u])
            {
                if (dist + w < d[v])
                {
                    d[v] = dist + w;
                    pq.push({v, d[v]});
                }
            }
        }
    };

    djk(s, dists);
    djk(d, distd);

    int len = dists[d];
    vector<int> cand(n);
    for (int i = 0; i < n; i++)
    {
        if (dists[i] + distd[i] == len)
        {
            cand[i] = 1;
        }
    }

    i64 cnt = 1, op = 0;
    vector<queue<int>> tmp(2);
    tmp[op].push(s);
    vector<i64> vis(n), mx(n);
    mx[s] = a[s];
    while (true)
    {
        if (tmp[op].size() == 0) break;
        cnt *= tmp[op].size();
        while (tmp[op].size())
        {
            auto u = tmp[op].front();
            tmp[op].pop();

            if (vis[u]) continue;
            vis[u] = 1;

            if (u == d) continue;
            
            for (auto [v, w] : adj[u])
            {
                if (vis[v]) continue;
                if (cand[v] == 1)
                {
                    mx[v] = max(mx[v], mx[u] + a[v]);
                    tmp[op ^ 1].push(v);
                }
            }
        }
        op ^= 1;
    }

    cout << cnt << " " << mx[d] << "\n";
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