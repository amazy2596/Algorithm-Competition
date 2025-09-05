// Problem: [JLOI2011] 飞行路线
// URL: https://www.luogu.com.cn/problem/P4568
// Author: amazy
// Date: 2025-09-05 16:36:01

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int s, t;
    cin >> s >> t;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    struct node
    {
        int u, t, rem;
        bool operator<(const node &o) const
        {
            return t > o.t;
        }
    };

    priority_queue<node> q;
    q.push({s, 0, k});
    vector<vector<int>> dist(n + 1, vector<int>(k + 1, inf));
    dist[s][k] = 0;
    while (!q.empty())
    {
        auto [u, t, rem] = q.top();
        q.pop();
        
        for (auto [v, w] : adj[u])
        {
            if (t + w < dist[v][rem])
            {
                dist[v][rem] = t + w;
                q.push({v, t + w, rem});
            }
            if (rem > 0 && t < dist[v][rem - 1])
            {
                dist[v][rem - 1] = t;
                q.push({v, t, rem - 1});
            }
        }
    }

    cout << *min_element(dist[t].begin(), dist[t].end()) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}