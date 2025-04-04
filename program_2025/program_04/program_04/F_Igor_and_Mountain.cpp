#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 998244353;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> s(n + 1);
    s[0] = string(m + 1, ' ');
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] = " " + s[i];

    vector dp(n + 1, vector<int>(m + 1));
    for (int j = 1; j <= m; j++)
        dp[n][j] = s[n][j] == 'X';

    for (int i = n; i >= 1; i--)
    {
        int sum = 0;
        vector<int> b(m + 5);

        for (int j = 1; j <= m; j++)
        {
            b[max(1ll, j - d)] += dp[i][j];
            b[min(m + 1, j + d + 1)] -= dp[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            sum += b[j];
            if (s[i][j] == 'X')
                dp[i][j] = (sum + mod) % mod;
        }

        b.assign(m + 5, 0);
        sum = 0;
        int dist = sqrt(d * d - 1);
        for (int j = 1; j <= m; j++)
        {
            b[max(1ll, j - dist)] += dp[i][j];
            b[min(m + 1, j + dist + 1)] -= dp[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            sum += b[j];
            if (s[i - 1][j] == 'X')
                dp[i - 1][j] = (dp[i - 1][j] + sum) % mod;
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++)
        ans = (ans + dp[1][j]) % mod;

    cout << ans << "\n";
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