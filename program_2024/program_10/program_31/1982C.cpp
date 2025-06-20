#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0, cur = 0;
    int beg = 0, ed = 0;
    while (beg < n && ed < n)
    {
        if (a[ed] > r)
        {
            cur = 0;
            ed++;
            beg = ed;
            continue;
        }
        cur += a[ed];
        if (cur >= l && cur <= r)
        {
            cur = 0;
            ans++;
            ed++;
            beg = ed;
            continue;
        }
        while (cur > r && beg < ed)
        {
            cur -= a[beg++];
        }
        if (cur >= l && cur <= r)
        {
            cur = 0;
            ans++;
            ed++;
            beg = ed;
            continue;
        }
        ed++;
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