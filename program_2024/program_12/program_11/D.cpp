#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> order(3);
    iota(order.begin(), order.end(), 0);
    int ans = 1e18l;
    do
    {
        vector dp(n + 1, vector<int>(3, 1e18l));
        dp[0] = {0, 0, 0};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    dp[i][order[j]] = min(dp[i][order[j]], dp[i - 1][order[k]] + ((s[i] - '0') != order[j]) * a[i]);
                }
            }
        }
        ans = min(ans, *min_element(dp[n].begin(), dp[n].end()));
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << "\n";
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