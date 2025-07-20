#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    string s;
    cin >> s;
    s = " " + s;

    int n = s.length() - 1;
    vector<vector<int>> adj(n + 1);
    int id = 1;
    auto dfs1 = [&](auto dfs, int u) -> void
    {
        int cnt = s[u] - '0';
        for (int i = 0; i < cnt; i++)
        {
            id++;
            adj[u].push_back(id);
            dfs(dfs, id);
        }
    };

    dfs1(dfs1, id);

    // 0 -> red
    // 1 -> blue
    // 2 -> green
    vector<array<int, 3>> dpMIN(n + 1, {inf, inf, inf}), dpMAX(n + 1, {-inf, -inf, -inf});
    auto dfs2 = [&](auto dfs, int u) -> void
    {
        if (s[u] == '0')
        {
            dpMIN[u][0] = dpMAX[u][0] = 0;
            dpMIN[u][1] = dpMAX[u][1] = 0;
            dpMIN[u][2] = dpMAX[u][2] = 1;
        }

        if (s[u] == '1')
        {
            int v = adj[u].back();
            dfs(dfs, v);
            for (int j = 0; j < 3; j++)
            {
                int k = (j + 1) % 3, l = (j + 2) % 3;
                dpMIN[u][j] = min({dpMIN[u][j], dpMIN[v][k], dpMIN[v][l]}) + (j == 2);
                dpMAX[u][j] = max({dpMAX[u][j], dpMAX[v][k], dpMAX[v][l]}) + (j == 2);
            }
        }
        
        if (s[u] == '2')
        {
            int x = adj[u][0], y = adj[u][1];
            dfs(dfs, x);
            dfs(dfs, y);
            for (int j = 0; j < 3; j++)
            {
                int k = (j + 1) % 3, l = (j + 2) % 3;
                dpMIN[u][j] = min({dpMIN[u][j], dpMIN[x][k] + dpMIN[y][l], dpMIN[x][l] + dpMIN[y][k]}) + (j == 2);
                dpMAX[u][j] = max({dpMAX[u][j], dpMAX[x][k] + dpMAX[y][l], dpMAX[x][l] + dpMAX[y][k]}) + (j == 2);
            }
        }
    };

    dfs2(dfs2, 1);

    cout << *max_element(dpMAX[1].begin(), dpMAX[1].end()) << " ";
    cout << *min_element(dpMIN[1].begin(), dpMIN[1].end()) << "\n";
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