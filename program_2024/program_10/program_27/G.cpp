#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int l = 0, r = 1e18;
    while (l < r)
    {
        int mid = (r - l) / 2 + l;
        if (__int128_t(n / 2 + n * mid) >= m)
            r = mid;
        else
            l = mid + 1;
    }
    if (n / 2 + n * l == m)
    {
        for (int i = 0; i < n; i++)
            cout << l + (i % 2 == 1) << " ";
        return;
    }
    if (n % 2 == 1)
    {
        l = 0, r = 1e12;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (__int128_t(n / 2 + 1 + n * mid) >= m)
                r = mid;
            else
                l = mid + 1;
        }
        if (n / 2 + 1 + n * l == m)
        {
            for (int i = 0; i < n; i++)
                cout << l + (i % 2 == 0) << " ";
            return;
        }
    }
    l = 0, r = 1e12;
    while (l < r)
    {
        int mid = (r - l) / 2 + l;
        if (__int128_t(n * mid + ((n - 1) * n) / 2) >= m)
            r = mid;
        else
            l = mid + 1;
    }
    if (n * l + ((n - 1) * n) / 2 == m)
    {
        for (int i = 0; i < n; i++)
            cout << l + i << " ";
        return;
    }
    cout << -1 << "\n";
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