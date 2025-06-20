#include <bits/stdc++.h>
#define int long long
using namespace std;

struct state
{
    int node, num, time;
    state(int node, int num, int time)
    {
        this->node = node;
        this->num = num;
        this->time = time;
    }
    bool operator<(const state &other) const
    {
        return time > other.time;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 2, INT64_MAX));
    vector<vector<int>> vis(n + 1, vector<int>(k + 2, 0));
    priority_queue<state> q;
    if (k != 0)
    {
        dp[1][1] = 1;
        q.push({1, 1, 1});
    }
    dp[1][0] = a[1];
    q.push({1, 0, a[1]});
    while (!q.empty())
    {
        auto [node, num, time] = q.top();
        q.pop();

        if (vis[node][num])
            continue;
        vis[node][num] = 1;

        for (auto v : g[node])
        {
            if (a[v] + time < dp[v][0])
            {
                dp[v][0] = a[v] + time;
                q.push({v, 0, dp[v][0]});
            }

            if (num < k && time + 1 < dp[v][num + 1])
            {
                dp[v][num + 1] = time + 1;
                q.push({v, num + 1, dp[v][num + 1]});
            }
        }
    }
    int ans = 1e18;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << "\n";
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