// Problem: 源石搜寻
// URL: https://ac.nowcoder.com/acm/contest/124444/F
// Author: amazy
// Date: 2025-11-28 22:50:18

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const i64 inf = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(2 * n + 1), premx(2 * n + 1, -inf), premn(2 * n + 1, inf), sufmx(2 * n + 2, -inf), sufmn(2 * n + 2, inf);
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= 2 * n; i++)
    {
        premn[i] = min(premn[i - 1], a[i]);
        premx[i] = max(premx[i - 1], a[i]);
    }    

    for (int i = 2 * n; i >= 1; i--)
    {
        sufmn[i] = min(sufmn[i + 1], a[i]);
        sufmx[i] = max(sufmx[i + 1], a[i]);
    }

    i64 ans = inf;
    for (int i = 1; i <= n; i++)
    {
        i64 l = a[i], r = a[i + n - 1];
        i64 u = max(premx[i - 1], sufmx[i + n]);
        i64 d = min(premn[i - 1], sufmn[i + n]);
        ans = min(ans, (r - l) * (u - d));
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