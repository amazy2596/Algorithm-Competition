#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    while (x != 1 && k > 0)
    {
        int cnt = max((x / y + 1) * y - x, 1ll);
        x += min(cnt, k);
        while (x % y == 0)
            x /= y;
        k -= min(cnt, k);
    }
    cout << x + k % (y - 1) << "\n";
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