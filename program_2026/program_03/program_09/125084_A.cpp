// Problem: 小月的前缀（构造version）
// URL: https://ac.nowcoder.com/acm/contest/125084/A
// Author: amazy
// Date: 2026-03-09 15:27:44

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, r;
    cin >> n >> r;
    vector<int> a(n, 1);
    if (r == 0) a[n - 1] = -1e9;
    else a[r - 1] = -1e9;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
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