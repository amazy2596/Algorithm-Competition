#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        a[l]++, b[r]++;
    }
    vector<int> target(n + 1);
    int ans = 0;
    for (int i = 1; i <= d; i++)
        ans += a[i];
    target[1] = ans;
    int r = d + 1, l = 1;
    while (r <= n)
    {
        ans += a[r];
        ans -= b[l];
        r++, l++;
        target[l] = ans;
    }
    int x = 1, xx = 0, y = 1, yy = 1e9;
    for (int i = 1; i + d - 1 <= n; i++)
    {
        if (target[i] > xx)
        {
            x = i;
            xx = target[i];
        }
        if (target[i] < yy)
        {
            y = i;
            yy = target[i];
        }
    }
    cout << x << " " << y << '\n';
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