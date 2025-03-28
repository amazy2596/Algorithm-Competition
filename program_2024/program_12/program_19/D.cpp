#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> diff(n), eq(n);
    int suf_0 = -1, suf_1 = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        diff[i] = (s[i] == '1' ? suf_0 : suf_1);
        eq[i] = (s[i] == '1' ? suf_1 : suf_0);

        if (s[i] == '1')
            suf_1 = i;
        else if (s[i] == '0')
            suf_0 = i;
    }
    vector<int> dp(n, 1e11);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (eq[i] != -1)
            dp[i] = min(dp[i], dp[eq[i]] + x);
        if (diff[i] != -1)
            dp[i] = min(dp[i], dp[diff[i]] + y);
    }
    
    cout << dp[0] << "\n";
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