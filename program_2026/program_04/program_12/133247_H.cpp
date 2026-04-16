// Problem: 随我出征,逐鹿天下
// URL: https://ac.nowcoder.com/acm/contest/133247/H
// Author: amazy
// Date: 2026-04-12 21:54:46

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

void solve()
{
    int n;
    i64 k;
    if (!(cin >> n >> k)) return;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    auto check = [&](int W) 
    {
        int L = n - W;
        for (int i = 0; i < W; i++) 
        {
            int p = L - i;
            i64 cur;
            if (p >= 30) continue;
            if (p >= 0) cur = k * (1LL << p);
            else 
            {
                if (-p >= 31) cur = 0;
                else cur = k / (1LL << -p);
            }
            if (cur < a[W - 1 - i]) return false;
        }
        return true;
    };

    int l = 0, r = n, ans = 0;
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;
        if (check(mid)) 
        {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << '\n';
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