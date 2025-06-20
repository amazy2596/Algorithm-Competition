#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.length(), m = b.length(), k = c.length();
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = max(0ll, i - m); j <= min(n, i); j++)
        {
            int idx_a = j, idx_b = i - j;
            if (idx_a != 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[min(n, idx_a)] != c[i]));
            if (idx_b != 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (b[min(m, idx_b)] != c[i]));
        }
    }
    cout << *min_element(dp[k].begin(), dp[k].end()) << "\n";
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