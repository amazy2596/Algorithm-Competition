// Problem: L1-4 刮刮乐
// URL: https://ac.nowcoder.com/acm/contest/104429/D
// Author: amazy
// Date: 2026-03-05 16:50:00

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, m;
    cin >> n >> m;
    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> a(m), b(m);
        for (int j = 0; j < m; j++) cin >> a[j];
        for (int j = 0; j < m; j++) 
        {
            cin >> b[j];
            if (a[j] == 7) sum += b[j];
            else if (a[j] == 77) sum += 2 * b[j];
            else if (a[j] == 777) sum += 3 * b[j];
        }
    }

    cout << sum << "\n";
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