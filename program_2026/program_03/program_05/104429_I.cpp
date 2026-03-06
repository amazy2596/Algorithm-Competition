// Problem: L2-1 最小冲突值
// URL: https://ac.nowcoder.com/acm/contest/104429/I
// Author: amazy
// Date: 2026-03-05 17:54:24

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    i64 ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] * b[i];
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