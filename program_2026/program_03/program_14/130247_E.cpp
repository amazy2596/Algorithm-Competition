// Problem: L1-5 洗浴
// URL: https://ac.nowcoder.com/acm/contest/130247/E
// Author: amazy
// Date: 2026-03-14 14:09:25

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) pq.push(0);

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int mn = pq.top();
        pq.pop();
        mn += a[i];
        ans = max(ans, mn);
        pq.push(mn);
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