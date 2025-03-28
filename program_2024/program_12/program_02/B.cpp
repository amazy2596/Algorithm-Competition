#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, k, t;
    char c;
    cin >> x >> y >> k >> t >> c;
    if (c == 'R')
        cout << k + t << "\n";
    else
    {
        if (k >= t)
            cout << t << "\n";
        else
            cout << k + x + t << "\n";
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