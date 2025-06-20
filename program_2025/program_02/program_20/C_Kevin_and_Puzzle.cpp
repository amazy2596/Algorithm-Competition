#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] == a[i])
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        if (i >= 2 && a[i] == a[i - 2] + 1)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
    }

    cout << (dp[n] + dp[n - 1]) % mod << "\n";
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