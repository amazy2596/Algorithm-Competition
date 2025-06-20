#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto check = [&](int mid)
    {
        vector<int> v = a;
        for (int i = 0; i < n; i++)
            v[i] = max(0ll, v[i] - mid);
        int b = mid, c = mid;
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] && v[i])
            {
                int mn = min(v[i - 1], v[i]);
                mn = min(mn, b);
                v[i - 1] -= mn, v[i] -= mn;
                b -= mn;
            }
        }
        c += b;
        for (int i = 0; i < n; i++)
            c -= v[i];
        return c >= 0;
    };
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
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