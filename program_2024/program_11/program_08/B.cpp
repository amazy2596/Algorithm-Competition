#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    long double c, d, e, f, g;
    cin >> c >> d >> e >> f >> g;
    long double a = c + d + e, b = f + g;
    long double ans = powl(a, 10) + 10 * powl(a, 9) * b;
    cout << fixed << setprecision(10) << (long double) 1 - ans << "\n";
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