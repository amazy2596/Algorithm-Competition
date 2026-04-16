// Problem: L2-3 字符串反转
// URL: https://ac.nowcoder.com/acm/contest/130247/K
// Author: amazy
// Date: 2026-03-14 14:44:44

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    vector<i64> cnt(26);
    for (auto ch : s) cnt[ch - 'a']++;
    i64 ans = 1 + n * (n - 1) / 2;
    for (int i = 0; i < 26; i++) ans -= cnt[i] * (cnt[i] - 1) / 2;
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