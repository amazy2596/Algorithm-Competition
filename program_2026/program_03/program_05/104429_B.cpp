// Problem: L1-2 睡眠时间到
// URL: https://ac.nowcoder.com/acm/contest/104429/B
// Author: amazy
// Date: 2026-03-05 16:46:44

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int a, b;
    cin >> a >> b;
    cout << "Average = " << (b + a - 1) / a << "\n";
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