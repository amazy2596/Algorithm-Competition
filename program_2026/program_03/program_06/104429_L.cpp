// Problem: L2-4 星际资源采集
// URL: https://ac.nowcoder.com/acm/contest/104429/L
// Author: amazy
// Date: 2026-03-06 21:57:18

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    i64 n, m;
    cin >> n >> m;
    vector<i64> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];

    auto check = [&](i64 t)
    {
        i128 sum = 0;
        // k * k - (k * k - 2 * k + 1) = 2 * k - 1
        // (2 * k - 1) * e <= t 
        // k <= (t / e + 1) / 2
        for (int i = 0; i < n; i++)
        {
            i64 k = (t / e[i] + 1) / 2;
            sum += (i128)k * k * e[i];
        }

        return sum;
    };

    i64 l = 0, r = m;
    while (l < r)
    {
        i64 mid = (l + r + 1) >> 1;
        if (check(mid) <= m)
            l = mid;
        else 
            r = mid - 1;
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) 
    {
        i64 k = (l / e[i] + 1) / 2;
        ans += k;
        m -= k * k * e[i];
    }

    for (int i = 0; i < n; i++)
    {
        i64 k = (l / e[i] + 1) / 2;
        if (k == l + 1 && m >= (2 * k + 1))
        {
            ans++;
            m -= 2 * k + 1;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}