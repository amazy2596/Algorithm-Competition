#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x = 343720 * 2, y = 233333 * 2;
    int dx = 15, dy = 17;
    for (int i = 1; i < 1e5 ; i++)
    {
        for (int j = 1; j < 1e5 ; j++)
        {
            x = i * (343720 * 2), y = j * (233333 * 2);
            if (x * 17 == y * 15)
            {
                cout << fixed << setprecision(2) << sqrtl(x * x + y * y) << "\n";
                return;
            }
        }
    }
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