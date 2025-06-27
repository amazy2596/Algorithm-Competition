#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), sum(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1, -inf));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i < s)
            dp[i][1] = (sum[n][1] - sum[s - 1][1] + sum[i][1]);
        else 
            dp[i][1] = (sum[i][1] - sum[s - 1][1]);
    }

    for (int j = 2; j <= m; j++)
    {
        // u <= v
        // dp[v][j] = max(dp[v][j], dp[u][j - 1] + sum[v][j] - sum[u - 1][j]);
        // u > v
        // dp[v][j] = max(dp[v][j], dp[u][j - 1] + sum[n][j] - sum[u - 1][j] + sum[v][j])
        vector<int> pre(n + 1, -inf), suf(n + 2, -inf);
        for (int i = 1; i <= n; i++)
            pre[i] = max(pre[i - 1], dp[i][j - 1] - sum[i - 1][j]);
        for (int i = n; i >= 1; i--)
            suf[i] = max(suf[i + 1], dp[i][j - 1] + sum[n][j] - sum[i - 1][j]);

        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = max(dp[i][j], max(pre[i], suf[i + 1]) + sum[i][j]);
        }
    }

    cout << dp[t][m] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}