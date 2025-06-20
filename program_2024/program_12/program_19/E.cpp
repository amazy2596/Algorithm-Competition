#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    s = ' ' + s;
    vector<vector<int>> dp(n + 1, vector<int>(13, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (s[i + 1] == '1' || s[i + 1] == '?')
                dp[i + 1][(j * 10 + 1) % 13] += dp[i][j];
            if (s[i + 1] == '0' || s[i + 1] == '?')
                dp[i + 1][j * 10 % 13] += dp[i][j];
            dp[i + 1][j * 10 % 13] %= mod;
            dp[i + 1][(j * 10 + 1) % 13] %= mod;
        }
    }
    cout << dp[n][0] << "\n";
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