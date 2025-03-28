#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> dp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int maxlen = 0;
        for (int j = 0; j < 30; j++)
        {
            if (x & (1 << j))
            {
                int mask = 1 << j;
                if (dp.find(mask) != dp.end())
                    maxlen = max(maxlen, dp[mask]);
            }
        }
        for (int bit = 0; bit < 30; bit++)
        {
            if (x & (1 << bit))
            {
                int mask = 1 << bit;
                dp[mask] = max(dp[mask], maxlen + 1);
            }
        }
    }
    int ans = 0;
    for (auto [key, val] : dp)
        ans = max(ans, val);
    cout << ans;
    return 0;
}