#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int a_max = (b * c - 1) / d;
    int diff = a - a_max;
    cout << diff << " ";
    // int l = 0, r = 1e9;
    // while (l < r)
    // {
    //     int mid = (l + r + 1) >> 1;
    //     if (mid * d < c * b)
    //         l = mid;
    //     else
    //         r = mid - 1;
    // }
    // cout << a - l << " ";
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