#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];

    for (int k = 1; k <= n - 2; k++)
    {
        vector<int> pre(n + 1), suf(n + 2);
        for (int i = 1; i <= n; i++)
            pre[i] = max(pre[i - 1], (s[i] - s[max(0ll, i - k)]));

        for (int i = n; i >= 1; i--)
            suf[i] = max(suf[i + 1], (s[min(n, i + k - 1)] - s[i - 1]));

        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, max(pre[i - 1], suf[i + 1]) - a[i]);

        cout << ans << " ";
    }

    cout << max(s[n] - a[1] - a[1], s[n] - a[n] - a[n]) << " " << "0\n";
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