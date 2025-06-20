#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    bitset<10001> dp;
    dp[0] = 1;
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i] + 1; j < 10001; j++)
        {
            if (dp[j])
            {
                ans = min(ans, j + a[i]);
                break;
            }
        }

        dp |= dp << a[i];
    }

    cout << (ans == INT32_MAX ? -1 : ans) << "\n";
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