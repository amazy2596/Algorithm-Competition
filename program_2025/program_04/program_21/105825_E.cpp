#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), nxt(n + 1, 1e9);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (__gcd(a[i], a[j]) != 1)
            {
                nxt[j] = min(nxt[j], i);
                pre[i] = max(pre[i], j);
            }
        }
    }

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int r = 1; r <= n; r++)
    {
        int mn = 1e9;
        for (int l = r; l >= 1; l--)
        {
            if (nxt[l] > r)
                mn = min(mn, pre[l]);
            else if (mn >= l && dp[l - 1] != -1)
                dp[r] = max(dp[r], dp[l - 1] + 1);
        }
    }

    cout << dp[n] << "\n";
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