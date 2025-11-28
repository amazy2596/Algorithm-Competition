// Problem: 小红的点构造
// URL: https://ac.nowcoder.com/acm/contest/123787/A
// Author: amazy
// Date: 2025-11-28 19:14:24

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int x, y;
    cin >> x >> y;
    if (x > 0)
    {
        if (y > 0) cout << x + 1 << " " << y + 1 << "\n";
        else cout << x + 1 << " " << y - 1 << "\n";
    }
    else 
    {
        if (y > 0) cout << x - 1 << " " << y + 1 << "\n";
        else cout << x - 1 << " " << y - 1 << "\n";
    }
}

int main()
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