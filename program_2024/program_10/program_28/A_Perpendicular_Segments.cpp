#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    cout << "0 " << min(x, y) << " " << min(x, y) << " 0\n";
    cout << x << " " << y << " " << x - min(x, y) << " " << y - min(x, y) << "\n";
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