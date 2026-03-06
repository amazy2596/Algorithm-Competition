// Problem: ⑨运算(Hard Version)
// URL: https://ac.nowcoder.com/acm/contest/125080/E
// Author: amazy
// Date: 2026-02-21 17:05:46

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    i64 x;
    cin >> x;
    i64 ans = 1e18;

    for (int d = 1; d <= 18; d++)
    {
        i64 v = pow(10, d) - 1;
        if (x % 9 == 0 && v >= x) ans = min(ans, (v - x) / 9);
        if (v < 9 * x) continue; 
        i64 k = v / 9 - x;
        i64 a = k / 9;
        i64 b = k - 9 * a;
        ans = min(ans, a + 1 + b);
    }
    cout << ans << "\n";
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