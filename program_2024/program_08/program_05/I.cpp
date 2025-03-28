#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int m, k, h;
    cin >> m >> k >> h;
    if (m == k)
    {
        cout << min(m, h) << "\n";
        return;
    }
    auto check = [&](int x)
    {      
        return x + (x - k) / (m - k) * k >= h;
    };
    int l = 0, r = max(m, h);
    while (l < r) 
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }
    cout << min(l, h) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}