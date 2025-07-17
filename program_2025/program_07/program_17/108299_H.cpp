#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int v, t, w;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<node>> adj(n + 1), radj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, t, w;
        cin >> u >> v >> t >> w;
        adj[u].push_back({v, t, w});
        radj[v].push_back({u, t, w});
    }

    auto dijk = [&](int i, vector<vector<node>> &cadj) 
    {
        vector<int> dist(n + 1, inf), vis(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, i});
        vis[i] = 1;
        dist[i] = 0;
        while (!q.empty())
        {
            auto [d, u] = q.top();
            q.pop();

            for (auto [v, t, w] : cadj[u])
            {
                if (dist[v] > dist[u] + t && !vis[v])
                {
                    dist[v] = dist[u] + t;
                    q.push({dist[v], v});
                }
            }
        }

        return dist;
    };

    auto oneToAll = dijk(1, adj);
    auto nToAll = dijk(n, radj);

    map<int, int> mp;
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, t, w] : adj[u])
        {
            int c = oneToAll[u] + nToAll[v] + t;
            if (mp.find(w) != mp.end())
                mp[w] = min(mp[w], c);
            else 
                mp[w] = c;
        }
    }

    vector<pair<int, int>> v;
    vector<int> tmp;
    for (auto [w2, c2] : mp)
    {
        while (!v.empty())
        {
            auto [w1, c1] = v.back();
            int K = (c2 - c1 + w2 - w1 - 1) / (w2 - w1);
            int prevK = tmp.back();
            if (K <= prevK)
            {
                v.pop_back();
                tmp.pop_back();
            }
            else 
                break;
        }
        if (tmp.empty())
            tmp.push_back(0);
        else 
        {
            auto [w1, c1] = v.back();
            int K = (c2 - c1 + w2 - w1 - 1) / (w2 - w1);
            tmp.push_back(K);
        }
        v.push_back({w2, c2});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;

        auto it = upper_bound(tmp.begin(), tmp.end(), k);
        if (it != tmp.begin())
            it--;
 
        int idx = it - tmp.begin();
        auto [w, c] = v[idx]; 
 
        cout << c - w * k << "\n";
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