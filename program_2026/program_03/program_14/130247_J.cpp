// Problem: L2-2 排名
// URL: https://ac.nowcoder.com/acm/contest/130247/J
// Author: amazy
// Date: 2026-03-14 14:30:04

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    i64 n, m, k, h;
    cin >> n >> m >> k >> h;

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vector<i64> cnt(m + 1), v(m + 1);
        for (int j = 0; j < a; j++)
        {
            i64 b, c, d;
            cin >> b >> c >> d;
            if (v[b] == 1) continue;
            if (d == 0) cnt[b] += 20;
            else if (d == 1) cnt[b] += c, v[b] = 1;
        }

        i64 x = 0, y = 0, z = 0;
        for (int j = 1; j <= m; j++)
        {
            if (v[j] == 1)
            {
                x++;
                y += cnt[j];
            }
            else z += cnt[j];
        }

        if (x == m && y <= k) ans++;
        else if (y + z + (m - x) * h <= k) ans++;
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