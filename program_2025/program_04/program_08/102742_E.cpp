#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int r = lower_bound(a.begin(), a.end(), m - k + a[i] + 1) - a.begin();
        int L = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        int R = lower_bound(a.begin(), a.end(), m + a[i] + k + 1) - a.begin();
        r--, R--;

        ans += (r - i) * (m + a[i] - k + 1) - (pre[r] - pre[i]);
        if (R >= L)
            ans += (R - L + 1) * (m + a[i] + k + 1) - (pre[R] - pre[L - 1]);
    }

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