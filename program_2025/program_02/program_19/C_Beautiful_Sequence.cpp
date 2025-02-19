#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> dp(4);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 2)
            dp[x] = (dp[x] * 2) % mod;
        dp[x] = (dp[x] + dp[x - 1]) % mod;
    }

    cout << dp[3] << "\n";
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