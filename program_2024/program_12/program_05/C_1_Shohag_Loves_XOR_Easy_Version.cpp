#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, m;
    cin >> x >> m;
    int ans = 0;
    for (int y = 1; y <= min(m, 2 * x); y++)
    {
        int temp = x ^ y;
        if (temp == 0)
            continue;
        if (x % temp == 0 || y % temp == 0)
            ans++;
    }
    cout << ans << "\n";
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