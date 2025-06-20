#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int p, n, k;
    cin >> p >> n >> k;
    vector<int> discount(1), sub(1);
    for (int i = 0; i < n; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t == 0)
            discount.emplace_back(x);
        else 
            sub.emplace_back(x);
    }

    sort(discount.begin() + 1, discount.end());
    sort(sub.rbegin(), sub.rend() - 1);
    vector dp(k + 1, vector<double>(discount.size() + 1, INT32_MAX));
    for (int i = 0; i < dp[0].size(); i++)
        dp[0][i] = p;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= min(i, (int)dp[i].size() - 1); j++)
        {
            int l = i - j;
            if (j > 0 && j < discount.size())
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] * (1.0 * discount[j] / 10));
            if (l > 0 && l < sub.size())
                dp[i][j] = min(dp[i][j], max(0.0, dp[i - 1][j] - sub[l]));
        }
    }

    cout << fixed << setprecision(2) << *min_element(dp[k].begin(), dp[k].end()) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}