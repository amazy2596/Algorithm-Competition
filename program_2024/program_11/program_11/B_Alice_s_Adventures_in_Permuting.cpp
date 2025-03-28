#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, b, c;
    cin >> n >> b >> c;
    if (b == 0)
    {
        if (n >= c + 3)
            cout << -1 << "\n";
        else if (c <= n - 1)
            cout << n - 1 << "\n";
        else    
            cout << n << "\n";
        return;
    }
    auto get = [&](int k) -> __int128_t
    {
        __int128_t res = c + __int128_t(k - 1) * b;
        return res;
    };
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        __int128_t res = get(mid);
        if (res < n)
            l = mid;
        else 
            r = mid - 1;
    }
    cout << n - l << "\n";
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