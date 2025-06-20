#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int l, r, x;
    cin >> l >> r >> x;
    for (int i = l; i <= r; i++)
    {
        if (i % x == 0)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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