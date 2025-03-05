#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    unordered_map<int, unordered_map<int, int>> mp;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);

        mp[p][i]++;
    }

    vector<int> depth(n + 1);
    vector node(n + 1, vector<int>());
    auto find = [&](auto find, int u, int p, int cur) -> void
    {
        depth[cur]++;
        node[cur].push_back(u);
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            find(find, v, u, cur + 1);
        }
    };
    find(find, 1, 0, 1);

    vector<int> dp(n + 1);
    for (int cur = n - 1; cur >= 2; cur--)
    {
        dp[cur] = (dp[cur] + (node[cur].size() * node[cur + 1].size()) % mod + ((node[cur].size() - 1) * dp[cur + 1]) % mod) % mod;
        for (auto u : node[cur])
            dp[cur] = (dp[cur] - (adj[u].size() - 1) + mod) % mod;
    }

    cout << (dp[2] + adj[1].size() + 1) % mod << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}