// Problem: 小红出牌（hard）
// URL: https://ac.nowcoder.com/acm/contest/125954/F
// Author: amazy
// Date: 2026-03-10 11:54:41

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += max(0, cnt[i] - cnt[i - 1]);

    auto calc = [&](int x) -> int
    {
        return max(0, cnt[x] - cnt[x - 1]);
    };

    for (int i = 0; i < n; i++)
    {
        int x = a[i];

        ans -= calc(x);
        ans -= calc(x + 1);

        cnt[x]++;

        ans += calc(x);
        ans += calc(x + 1);

        cout << ans << " ";
    }
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