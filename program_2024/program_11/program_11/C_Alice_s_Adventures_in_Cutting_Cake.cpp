#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2), ppre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], ppre[i] = ppre[i - 1] + a[i];
    int l = 1, r = 1, cur = 0;
    while (r <= n)
    {
        cur += a[r];
        if (cur >= v)
        {
            pre[r] = pre[l - 1] + 1;
            for (int i = l; i < r; i++)
                pre[i] = pre[l - 1];
            cur = 0;
            r++;
            l = r;
        }
        else
            r++;
    }
    int idx = l - 1;
    while (l <= n)
        pre[l++] = pre[idx];
    l = n, r = n, cur = 0;
    while (l >= 1)
    {
        cur += a[l];
        if (cur >= v)
        {
            suf[l] = suf[r + 1] + 1;
            for (int i = r; i > l; i--)
                suf[i] = suf[r + 1];
            cur = 0;
            l--;
            r = l;
        }
        else
            l--;
    }
    idx = r + 1;
    while (r >= 1)
        suf[r--] = suf[idx];
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        l = i, r = n + 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (suf[mid] >= m - pre[i - 1])
                l = mid;
            else
                r = mid - 1;
        }
        if (pre[i - 1] + suf[l] >= m)
            ans = max(ans, ppre[r - 1] - ppre[i - 1]);
    }
    cout << ans << "\n";
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