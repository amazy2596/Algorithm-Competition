#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            mp[x]++, mp[y]++;
        }
        n -= mp.size();
        vector<intt> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] += dp[i - 1];
            if (i >= 2)
            {
                dp[i] += dp[i - 2] * 2 * (i - 1) % mod;
                dp[i] %= mod;
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}