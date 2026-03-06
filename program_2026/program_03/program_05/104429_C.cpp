// Problem: L1-3 我是股神
// URL: https://ac.nowcoder.com/acm/contest/104429/C
// Author: amazy
// Date: 2026-03-05 16:47:33

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 mx = 0;
    for (int i = 0; i < k; i++)
    {
        i64 a;
        cin >> a;
        mx = max(mx, a);
    }

    cout << n * (mx - m) << "\n";
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