#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class LCA
{
    public:
        int n, max_log;
        vector<vector<int>> adj, up;
        vector<int> depth;

        LCA(int n, int root, vector<vector<int>> &adj)
        {
            this->n = n;
            this->adj = adj;
            this->max_log = (int)log2(n) + 1;

            up.resize(n + 1, vector<int>(max_log, -1));
            depth.resize(n + 1, 0);

            dfs(root, -1);
        }

        void dfs(int root, int p) 
        {
            stack<pair<int, int>> stk;
            stk.push({root, p});
            
            while (!stk.empty()) 
            {
                auto [u, parent] = stk.top();
                stk.pop();
                
                up[u][0] = parent; 
                for (int i = 1; i < max_log; i++)
                    if (up[u][i - 1] != -1)
                        up[u][i] = up[up[u][i - 1]][i - 1];
        
                for (int v : adj[u]) 
                {
                    if (v == parent) 
                        continue;
                    depth[v] = depth[u] + 1;
                    stk.push({v, u});
                }
            }
        }

        int query(int u, int v)
        {
            if (depth[u] < depth[v])
                swap(u, v);

            for (int i = max_log - 1; i >= 0; i--)
                if (depth[u] - (1ll << i) >= depth[v])
                    u = up[u][i];

            if (u == v)
                return u;
            
            for (int i = max_log - 1; i >= 0; i--)
            {
                if (up[u][i] != up[v][i])
                {
                    u = up[u][i];
                    v = up[v][i];
                }
            }

            return up[u][0];
        }
};

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA lca(n + 1, s, adj);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << "\n";
    }
}

signed main()
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