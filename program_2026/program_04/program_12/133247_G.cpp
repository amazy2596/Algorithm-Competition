// Problem: 奶龙王朝
// URL: https://ac.nowcoder.com/acm/contest/133247/G
// Author: amazy
// Date: 2026-04-12 14:51:49

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    i64 n, m, p;
    cin >> n >> m >> p;
    vector<i64> a(n + 1), b(m + 1), pre(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= m; i++) pre[i] = pre[i - 1] + b[i];

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        i64 tar = p - a[i];
        // auto it = lower_bound(b.begin(), b.end(), tar);
        // i64 idx = it - b.begin(); 
        int l = 0, r = m;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (b[mid] >= tar) r = mid - 1;
            else l = mid;
        }
        i64 idx = l;
        // cout << tar << " " << idx << "\n";
        ans += a[i] * idx + pre[idx] + (m - idx) * p;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}