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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dp[u][k][s] 代表 以u为根都子树使用了k条路径当前节点状态为s的最大权值和
    // s -> 0 : u节点为白色。
    // s -> 1 : u节点为黑色，且u不会向父节点延伸, 所有路径都在以u为跟的子树内部。
    // s -> 2 : u节点为黑色，且u节点会想父节点延伸。

    vector<vector<array<int, 3>>> dp(n + 1, vector<array<int, 3>>(k + 1, {-inf, -inf, -inf}));
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        dp[u][0][0] = 0;
        dp[u][1][1] = a[u];
        dp[u][1][2] = a[u];

        for (auto v : adj[u])
        {   
            if (v == p)
                continue;
            dfs(dfs, v, u);

            vector<array<int, 3>> tmp(k + 1, {-inf, -inf, -inf});

            vector<int> fv(k + 1, -inf);
            for (int j = 0; j <= k; j++)
                fv[j] = max({dp[v][j][0], dp[v][j][1], dp[v][j][2]});

            for (int i = 0; i <= k; i++)
            {
                for (int j = 0; j <= k; j++)
                {
                    if (i + j <= k)
                    {
                        tmp[i + j][0] = max(tmp[i + j][0], dp[u][i][0] + fv[j]);
                        tmp[i + j][1] = max(tmp[i + j][1], dp[u][i][1] + fv[j]);
                        tmp[i + j][2] = max(tmp[i + j][2], dp[u][i][2] + fv[j]);
                    }

                    if (i + j <= k)
                        tmp[i + j][2] = max(tmp[i + j][2], dp[u][i][0] + dp[v][j][2] + a[u]);

                    if (i + j - 1 <= k && i + j - 1 >= 0)
                        tmp[i + j - 1][1] = max(tmp[i + j - 1][1], dp[u][i][2] + dp[v][j][2]);
                }
            }

            dp[u] = move(tmp);
        }
    };

    dfs(dfs, 1, 0);

    int ans = 0;
    for (int j = 0; j <= k; j++)
        ans = max({ans, dp[1][j][0], dp[1][j][1], dp[1][j][2]});

    cout << ans << "\n";
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