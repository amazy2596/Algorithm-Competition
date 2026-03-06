// Problem: L1-6 损失函数
// URL: https://ac.nowcoder.com/acm/contest/104429/F
// Author: amazy
// Date: 2026-03-05 16:58:58

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    double ans = 0;
    for (int i = 0; i < n; i++) ans += (a[i] - b[i]) * (a[i] - b[i]);
    ans /= n;
    cout << fixed << setprecision(5) << ans << "\n";
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