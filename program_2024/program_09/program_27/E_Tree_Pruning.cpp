#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> height(n + 1), max_high(n + 1, -1);
    vector<vector<int>> depth_node(n + 1);
    int high = 0, max_depth = 0;
    function<void(int, int)> dfs = [&](int p, int u)
    {
        height[u] = high++;
        max_high[u] = height[u];
        depth_node[height[u]].push_back(u);
        if (a[u].size() == 1 && u != 1)
            max_depth = max(max_depth, height[u]);
        for (auto v : a[u])
        {
            if (v == p)
                continue;
            dfs(u, v);
            max_high[u] = max(max_high[u], max_high[v]);
        }
        high--;
    };
    dfs(0, 1);

    vector<int> delta(n + 2, 0);
    for (int i = 1; i <= n; i++)
        delta[height[i]]++, delta[max_high[i] + 1]--;

    vector<int> pre(n + 1, 0);
    int d = n, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + delta[i];
        if (pre[i] > cnt)
        {
            cnt = pre[i];
            d = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (height[i] <= d && max_high[i] >= d)
            ans++;
    }

    cout << n - ans << '\n';
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