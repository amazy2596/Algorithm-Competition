#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    if (n == 1)
    {
        cout << a[1] + b[1] << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + b[i];

    int ans = -1e18;
    for (int i = 1; i <= n; i++)
        ans = max(ans, pre[i] + suf[i]);

    vector<int> mx1(n + 2, -1e18), mx2(n + 2, -1e18), mx3(n + 2, -1e18), mx4(n + 2, -1e18);
    for (int i = 1; i <= n; i++)
    {
        mx1[i] = max(mx1[i - 1], b[i]);
        mx3[i] = max(mx3[i - 1], b[i] - a[i]);
    }

    for (int i = n; i >= 1; i--)
    {
        mx2[i] = max(mx2[i + 1], a[i]);
        mx4[i] = max(mx4[i + 1], a[i] - b[i]);
    }

    for (int i = 2; i <= n - 1; i++)
    {
        ans = max(ans, pre[i] + suf[i] + mx3[i - 1] + mx4[i + 1]);
        ans = max(ans, pre[i] + suf[i] + mx1[i - 1] - b[i]);
        ans = max(ans, pre[i] + suf[i] + mx2[i + 1] - a[i]);
    }

    ans = max(ans, pre[1] + suf[1] + mx2[2] - a[1]);
    ans = max(ans, pre[n] + suf[n] + mx1[n - 1] - b[n]);

    cout << ans << "\n";
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