#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x;
    cin >> x;
    bool f = 1;
    int y = 1;
    for (int k = 1; k <= 31; k++)
    {
        y += (1ll << k);
        if (y >= x)
            break;
        int c = x ^ y;
        if (x + y > c && x + c > y && c + y > x)
        {
            cout << y << "\n";
            f = 0;
            break;
        }
        y -= (1ll << k);
    }

    if (f)
        cout << "-1" << "\n";
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