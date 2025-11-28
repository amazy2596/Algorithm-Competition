// Problem: 小红的数组重排
// URL: https://ac.nowcoder.com/acm/contest/123787/B
// Author: amazy
// Date: 2025-11-28 19:19:10

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// a[i] - a[j] != i - j
// i < j
// i - j < 0
// a[i] - a[j] >= 0

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());    
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
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