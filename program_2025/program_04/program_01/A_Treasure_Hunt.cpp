#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, y;
    double a;
    cin >> x >> y >> a;
    a += 0.5;
    a -= (((int)(a / (x + y))) * (x + y));
    if (a - x <= 0)
        cout << "NO\n";
    else
        cout << "YES\n";
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