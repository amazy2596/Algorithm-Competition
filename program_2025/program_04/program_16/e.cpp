#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int b, c;
    cin >> b >> c;
    array<int, 5> x, y;
    for (int j = 1; j <= 4; j++)
        cin >> x[j] >> y[j];

    vector<pair<int, int>> a(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> a[i].first >> a[i].second;

    auto get = [&](int x1, int y1, int x2, int y2) -> double
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    vector<array<double, 4>> dist(k + 1, {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX});
    vector<int> vis(4);
    vector<int> idx;
    auto dfs = [&](auto dfs, int i, int n) -> void
    {
        if (idx.size() == n)
        {
            idx.push_back(4);
            double ans = get(a[i].first, a[i].second, x[idx[0]], y[idx[0]]);
            for (int j = 1; j < idx.size(); j++)
                ans += get(x[idx[j - 1]], y[idx[j - 1]], x[idx[j]], y[idx[j]]);
            idx.pop_back();

            dist[i][n] = min(dist[i][n], ans);
            return ;
        }

        for (int j = 1; j <= 3; j++)
        {
            if (vis[j])
                continue;
            vis[j] = 1;
            idx.push_back(j);
            dfs(dfs, i, n);
            idx.pop_back();
            vis[j] = 0;
        }
    };

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            vis.resize(4, 0);
            dfs(dfs, i, j);
        }
    }

    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 1; j <= 3; j++)
    //         cout << dist[i][j] << " ";
    //     cout << "\n";
    // }

    int mx = max(ceil(n * 1.0 / b), ceil(m * 1.0 / c));
    vector<vector<double>> dp(k + 1, vector<double>(mx + 1, INT32_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = mx; j >= 0; j--)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j >= 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist[i][1]);
            if (j >= 2)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + dist[i][2]);
            if (j >= 3)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 3] + dist[i][3]);
        }
    }

    cout << fixed << setprecision(10) << dp[k][mx] << "\n";
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