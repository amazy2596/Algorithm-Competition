#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

int hash_state(int u, int out)
{
    return (u - 1) * 3 + (out - 1);
}

pair<int, int> decode_state(int key) 
{
    return {(key / 3) + 1, (key % 3) + 1};
}

void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> edge;
    vector<vector<int>> adj(n + 1, vector<int>(4));
    for (int u = 1; u <= n; u++)
    {
        cin >> adj[u][0];
        for (int id = 1; id <= adj[u][0]; id++)
        {
            int v;
            cin >> v;
            edge[{u, v}] = id;
            adj[u][id] = v;
        }
    }

    vector<vector<int>> ans(n + 1, vector<int>(4));
    for (int i = 1; i <= n; i++)
    {
        if (ans[i][1])
            continue;
        
        map<pair<int, int>, int> mp;
        auto dfs = [&](auto dfs, int u, int id) -> void
        {
            if (ans[u][id])
                return;
            int v = adj[u][id];
            if (mp.find({u, v}) == mp.end())
            {
                mp[{u, v}]++;
                mp[{v, u}]++;
            }

            ans[u][id] = 1;
            int nid = (edge[{v, u}] % adj[v][0]) + 1;
            dfs(dfs, v, nid);
            ans[u][id] = mp.size() / 2;
        };
        dfs(dfs, i, 1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i][1] << "\n";

    // vector<int> memo(3 * n);
    // for (int i = 1; i <= n; i++)
    // {
    //     int u = i, out = 1;

    //     int key = hash_state(u, out);
    //     if (memo[key])
    //     {
    //         cout << memo[key] << "\n";
    //         continue;
    //     }

    //     vector<int> path;
    //     vector<bool> vis(n * 3, false);

    //     while (true) 
    //     {
    //         key = hash_state(u, out);
            
    //         if (memo[key] != 0 || vis[key]) 
    //             break;
            
    //         vis[key] = true;
    //         path.push_back(key);

    //         int v = adj[u][out];
    //         int in_label = edge[{v, u}];
    //         int next_out = (in_label % adj[v][0]) + 1;

    //         u = v;
    //         out = next_out;
    //     }

    //     int ans;
    //     if (memo[key] != 0) 
    //         ans = memo[key];
    //     else
    //     {
    //         map<pair<int, int>, int> cnt;
    //         bool in_cycle = false;
    //         for (int p_key : path) 
    //         {
    //             if (p_key == key) in_cycle = true;
    //             if (in_cycle) 
    //             {
    //                 auto [cu, cout] = decode_state(p_key);
    //                 int cv = adj[cu][cout];
    //                 cnt[{cu, cv}]++;
    //                 cnt[{cv, cu}]++;
    //             }
    //         }
    //         ans = cnt.size() / 2;
    //     }

    //     for (int p_key : path)
    //         memo[p_key] = ans;

    //     cout << ans << "\n";
    // }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}