#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = mp[x];
    }
    vector<vector<int>> dp(n + 1, vector<int>(1, INT32_MAX));
    int tot = 1;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = tot + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[i] <= dp[mid].back())
                r = mid;
            else
                l = mid + 1;
        }
        if (l == tot + 1)
            dp[++tot].push_back(a[i]);
        else
            dp[l].push_back(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i].size() >= 2)
            ans++;
        else
            break;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}