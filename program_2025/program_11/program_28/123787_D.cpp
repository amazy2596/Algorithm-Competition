// Problem: 小红的区间查询
// URL: https://ac.nowcoder.com/acm/contest/123787/D
// Author: amazy
// Date: 2025-11-28 19:29:26

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int a, b, l, r;
    cin >> a >> b >> l >> r;

    // (x - a) / (x - b) 
    // d = x - b
    // x = d + b
    // (d + b - a) / d
    // 1 + (b - a) / d >= 2
    // (b - a) / d >= 1

    int ans = 0;
    int t = b - a;
    for (int i = 1; i * i <= (b - a); i++)
    {
        if (t % i == 0)
        {
            if (l <= i + b && i + b <= r) ans++;
            if (t / i != i)
            {
                int j = t / i;
                if (l <= j + b && j + b <= r) ans++;
            }
        }
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