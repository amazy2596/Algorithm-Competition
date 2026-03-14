// Problem: Digital Deletion
// URL: https://ac.nowcoder.com/acm/contest/125083/D
// Author: amazy
// Date: 2026-03-09 14:21:09

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    i64 r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= r + 1)
        {
            r += a[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > r || a[i] == 0) 
        {
            ans++;
        }
    }
    cout << ans << "\n";
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