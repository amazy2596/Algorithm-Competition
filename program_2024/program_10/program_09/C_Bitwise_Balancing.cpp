#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int b, c, d;
    cin >> b >> c >> d;
    int a = 0;
    for (int i = 0; i <= 61; i++)
    {
        int b1 = b >> i & 1, c1 = c >> i & 1, d1 = d >> i & 1;
        // cout << ((1 | b1) - (1 & c1)) << "\n";
        if (((1 | b1) - (1 & c1)) == d1)
            a |= 1ll << i;
    }
    if ((a | b) - (a & c) == d)
        cout << a << "\n";
    else 
        cout << -1 << "\n";
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