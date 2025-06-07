#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct LCA
{
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