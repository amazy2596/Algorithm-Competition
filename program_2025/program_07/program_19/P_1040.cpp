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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i];
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int root = l; root <= r; root++)
            {
                if (l < root && root < r)
                    dp[l][r] = max(dp[l][r], dp[l][root - 1] * dp[root + 1][r] + a[root]);
                else if (l == root)
                    dp[l][r] = max(dp[l][r], a[root] + dp[root + 1][r]);
                else if (r == root)
                    dp[l][r] = max(dp[l][r], a[root] + dp[l][root - 1]);
            }
        }
    }

    cout << dp[1][n] << "\n";
    auto dfs = [&](auto dfs, int l, int r, int tar) -> void
    {
        if (l > r)
            return;
        if (l == r)
        {
            cout << l << " ";
            return;
        }
        for (int root = l; root <= r; root++)
        {
            if (l == root && tar == dp[root + 1][r] + a[root])
            {
                cout << root << " ";
                dfs(dfs, l, root - 1, dp[l][root - 1]);
                dfs(dfs, root + 1, r, dp[root + 1][r]);
                break;
            }
            if (r == root && tar == dp[l][root - 1] + a[root])
            {
                cout << root << " ";
                dfs(dfs, l, root - 1, dp[l][root - 1]);
                dfs(dfs, root + 1, r, dp[root + 1][r]);
                break;
            }
            if (l < root && root < r && tar == dp[l][root - 1] * dp[root + 1][r] + a[root])
            {
                cout << root << " ";
                dfs(dfs, l, root - 1, dp[l][root - 1]);
                dfs(dfs, root + 1, r, dp[root + 1][r]);
                break;
            }
        }
    };

    dfs(dfs, 1, n, dp[1][n]);
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