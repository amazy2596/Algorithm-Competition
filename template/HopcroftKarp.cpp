#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-9;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

class HopcroftKarp
{
    public:
        int n, m;
        vector<vector<int>> adj;
        vector<int> pair_u, pair_v, dist;
        HopcroftKarp(int size_u, int size_v)
        {
            n = size_u;
            m = size_v;
            pair_u.resize(n, 0);
            pair_v.resize(m, 0);
            dist.resize(n, 0);
            adj.resize(n, vector<int>());
        }

        void add(int u, int v)
        {
            adj[u].push_back(v);
        }

        bool bfs()
        {
            queue<int> q;
            for (int u = 1; u <= n; u++)
            {
                if (pair_u[u] == 0)
                {
                    dist[u] = 0;
                    q.push(u);
                }
                else
                    dist[u] = INT32_MAX;
            }
            dist[0] = INT32_MAX;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (u == 0)
                    continue;
                for (auto v : adj[u])
                {
                    if (dist[pair_v[v]] == INT32_MAX)
                    {
                        dist[pair_v[v]] = dist[u] + 1;
                        // if (pair_v[v] != 0)
                        q.push({pair_v[v]});
                    }
                }
            }
            return dist[0] != INT32_MAX;
        }

        bool dfs(int u)
        {
            if (u == 0)
                return true;
            for (auto v : adj[u])
            {
                if (dist[pair_v[v]] == dist[u] + 1)
                {
                    if (dfs(pair_v[v]))
                    {
                        pair_u[u] = v;
                        pair_v[v] = u;
                        return true;
                    }
                }
            }
            dist[u] = INT32_MAX;
            return false;
        }

        int max_matching()
        {
            int matching = 0;
            while (bfs())
            {
                for (int u = 1; u <= n; u++)
                {
                    if (pair_u[u] == 0)
                    {
                        if (dfs(u))
                            matching++;
                    }
                }
            }
            return matching;
        }

        vector<int> get_matching()
        {
            return pair_u;
        }
};

void solve()
{
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}