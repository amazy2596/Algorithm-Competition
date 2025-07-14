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



void solve()
{
    int n;
    cin >> n;
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> r[i];

    // vector<int> super(n + 1), d(n + 1);
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int l, k;
    //     cin >> l >> k;
    //     super[l] = k;
    //     d[k]++;
    // }

    // queue<int> q;
    // vector<int> sum0(n + 1), sum1(n + 1);

    // for (int i = 1; i <= n; i++)
    // {
    //     if (d[i] == 0)
    //         q.push(i);
    // }

    // int ans = 0;
    // while (!q.empty())
    // {
    //     int u = q.front();
    //     q.pop();

    //     ans = max({ans, sum0[u], sum1[u] + r[u]});

    //     int g0 = sum0[u];
    //     int g1 = sum1[u] + r[u];

    //     int p = super[u];
    //     sum0[p] += max(g0, g1);
    //     sum1[p] += g0;

    //     if (--d[p] == 0)
    //         q.push(p);
    // }

    // cout << ans << "\n";

    vector<int> super(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int l, k;
        cin >> l >> k;
        super[l] = k;
        adj[k].push_back(l);
    }

    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (super[i] == 0)
        {
            root = i;
            break;
        }
    }

    vector<array<int, 2>> dp(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
        dp[u][1] += r[u];
    };

    dfs(dfs, root, 0);
    cout << max(dp[root][0], dp[root][1]) << "\n";
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