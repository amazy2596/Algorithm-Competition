#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    cout << max({x, y, z, x + y + z - max({x, y, z})}) << "\n";
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