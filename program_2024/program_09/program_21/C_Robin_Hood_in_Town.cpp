#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i], mx = max(mx, a[i]);
    if (n <= 2)
    {
        cout << -1 << "\n";
        return;
    }
    auto check = [&](int x)
    {
        int q = sum + x, p = n * 2, cnt = 0;
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == mx && f)
            {
                f = 0;
                continue;
            }
            if (a[i] * p < q)
                cnt++;
        }
        return cnt > (n / 2);
    };
    int l = 0, r = 1e18;
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}