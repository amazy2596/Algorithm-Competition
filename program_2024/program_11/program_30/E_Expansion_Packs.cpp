#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<long double> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    vector<vector<long double>> dp(n + 1, vector<long double>(n + 1));
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
            dp[i][j] = (j > 0 ? p[i] * dp[i - 1][j - 1] : 0) + (1 - p[i]) * dp[i - 1][j];
    }
    vector<long double> g(n + 1);
    for (int i = 0; i <= n; i++)
        g[i] = dp[n][i];

    vector<long double> f(x + 1);
    for (int i = 1; i <= x; i++)
    {
        long double sum = 0.0;
        for (int j = 1; j <= n; j++)
            sum += g[j] * f[max(0ll, i - j)];
        f[i] = (sum + 1) / (1 - g[0]);
    }
    cout << fixed << setprecision(16) << f[x] << "\n";
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