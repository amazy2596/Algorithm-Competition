// Problem: enar吃烤肉
// URL: https://ac.nowcoder.com/acm/contest/133247/C
// Author: amazy
// Date: 2026-04-12 16:31:52

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(a.begin() + 1, a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

    int m = b.size();
    i64 ans = 0;
    vector<int> cnt(m + 1), num(n + 1);

    for (int l = 1; l <= n; l++)
    {
        fill(cnt.begin(), cnt.end(), 0);
        fill(num.begin(), num.end(), 0);
        int tot = 0;
        for (int r = l; r <= n; r++)
        {
            if (cnt[a[r]] > 0)
            {
                num[cnt[a[r]]]--;
                if (num[cnt[a[r]]] == 0) tot--;
            }
            cnt[a[r]]++;
            if (num[cnt[a[r]]] == 0) tot++;
            num[cnt[a[r]]]++;
            if (tot == 1) ans++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}