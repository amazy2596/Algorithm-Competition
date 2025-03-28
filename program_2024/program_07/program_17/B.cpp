#include <bits/stdc++.h>
using intt = long long;
using namespace std;

vector<int> g, dp, vis;

int dfs(int node)
{
    if (dp[node] != -1)
        return dp[node];
    if (vis[node])
        return 0;
    vis[node] = 1;
    int nextNode = g[node];
    dp[node] = 1 + dfs(nextNode);
    vis[node] = 0;
    return dp[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n + 1), dp.resize(n + 1, -1), vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i] == -1)
            ans = max(ans, dfs(i));
    cout << ans << "\n";
    return 0;
}