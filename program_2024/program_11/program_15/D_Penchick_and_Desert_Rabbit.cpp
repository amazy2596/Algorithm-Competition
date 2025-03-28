#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), ans(n), pre(n), suf(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        pre[i] = mx;
    }
    int mn = 1e9;
    for (int i = n - 1; i >= 0; i--)
    {
        mn = min(mn, a[i]);
        suf[i] = mn;
    }
    ans[n - 1] = pre[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int x = pre[i], y = suf[i + 1];
        if (x > y)
            ans[i] = max(ans[i], ans[i + 1]);
        else
            ans[i] = max(ans[i], pre[i]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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