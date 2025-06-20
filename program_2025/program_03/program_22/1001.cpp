#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), l(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> l[i];
    
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (l[i] >= a[i])
        {
            int ones = __builtin_popcountll(a[i]);
            ans = (ans * (1ll << ones) % mod) % mod;
            continue;
        }

        vector dp(33, vector<int>(2));
        dp[32][1] = 1;
        for (int k = 31; k >= 0; k--)
        {
            int bitA = (a[i] >> k) & 1;
            int bitL = (l[i] >> k) & 1;

            for (int tight = 0; tight < 2; tight++)
            {
                int ways = dp[k + 1][tight];
                if (!ways)
                    continue;
                
                for (int bit = 0; bit <= (bitA == 1 ? 1 : 0); bit++)
                {
                    if (tight == 1)
                    {
                        if (bit > bitL)
                            continue;
                        int nTight = (bit < bitL ? 0 : 1);
                        dp[k][nTight] += ways;
                    }
                    else 
                    {
                        dp[k][0] += ways;
                    }
                }
            }
        }

        int res = dp[0][0] + dp[0][1];
        ans = (ans * res) % mod;
    }

    cout << ans % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}