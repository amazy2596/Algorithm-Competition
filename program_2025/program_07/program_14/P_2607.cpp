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
    vector<int> hate(n + 1), w(n + 1), d(n + 1), in_cycle(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> hate[i];
        d[hate[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        in_cycle[u] = 0;
        
        int v = hate[u];
        if (--d[v] == 0)
            q.push(v);
    }

    vector<vector<int>> adj(n + 1);
    for (int u = 1; u <= n; u++)
    {
        int v = hate[u];
        if (!in_cycle[u])
            adj[v].push_back(u);
    }

    vector<int> sum0(n + 1), sum1(n + 1), d1(n + 1);
    queue<int> q1;
    for (int u = 1; u <= n; u++)
    {
        if (!in_cycle[u])
        {
            d1[u] = adj[u].size();
            if (d1[u] == 0)
                q1.push(u);
        }
    }

    // sum0[u]: 不选u         sum0[u] = max(sum0[u], sum1[u]);
    // sum1[u]: 选u           sum1[u] = w[u] + sum0[u];
    while (!q1.empty())
    {
        auto u = q1.front();
        q1.pop();

        int p = hate[u];
        int g0 = sum0[u];
        int g1 = w[u] + sum1[u];

        sum0[p] += max(g0, g1);
        sum1[p] += g0;

        if (!in_cycle[p] && --d1[p] == 0)
            q1.push(p);
    }

    int ans = 0;
    vector<int> used(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (in_cycle[i] && !used[i])
        {
            vector<int> cycle;
            int u = i;
            do
            {
                used[u] = 1;
                cycle.push_back(u);
                u = hate[u];
            } while (u != i);

            int k = cycle.size();
            vector<int> a(k), b(k);
            for (int j = 0; j < k; j++)
            {
                int v = cycle[j];
                a[j] = w[v] + sum1[v];
                b[j] = sum0[v];
            }

            vector<array<int, 2>> dp(k + 1, {-inf, -inf});
            dp[0][0] = b[0];
            dp[0][1] = -inf;
            for (int j = 1; j < k; j++)
            {
                dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]) + b[j];
                dp[j][1] = dp[j - 1][0] + a[j];
            }
            int res1 = max(dp[k - 1][0], dp[k - 1][1]);

            dp[0][0] = -inf;
            dp[0][1] = a[0];
            for (int j = 1; j < k; j++)
            {
                dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]) + b[j];
                dp[j][1] = dp[j - 1][0] + a[j];
            }
            int res2 = dp[k - 1][0];

            ans += max(res1, res2);
        }
    }

    cout << ans << "\n";
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