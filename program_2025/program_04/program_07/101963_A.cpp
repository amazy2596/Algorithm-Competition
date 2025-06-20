#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x == 1)
        cout << 10 + y;
    else if (x == 2)
        cout << (int)1e9 + y;
    else if (x == 3)
        cout << (int)1e18 + y;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}