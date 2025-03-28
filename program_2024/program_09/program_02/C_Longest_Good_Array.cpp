#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    b -= a;
    int l = 2, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (mid * (mid - 1) / 2 <= b)
            l = mid + 1;
        else 
            r = mid;
    }
    cout << l - 1 << "\n";
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