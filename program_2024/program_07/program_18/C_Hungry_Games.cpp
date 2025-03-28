#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<intt> a(n + 1), prefixsum(n + 1);
        intt ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prefixsum[i] = prefixsum[i - 1] + a[i];
        }
        vector<int> dp(n + 2, 0);
        for (int l = n; l >= 1; l--)
        {
            auto it = upper_bound(prefixsum.begin() + l, prefixsum.end(), prefixsum[l - 1] + x);
            int r = it - prefixsum.begin(); 
            if (it == prefixsum.end())
                dp[l] = n - l + 1;
            else 
                dp[l] = dp[r + 1] + r - l;
            ans += dp[l];
        }
        cout << ans << "\n";
    }
    return 0;
}