// Problem: L1-4 稳过
// URL: https://ac.nowcoder.com/acm/contest/130247/D
// Author: amazy
// Date: 2026-03-14 14:07:15

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    i64 n;
    cin >> n;
    int last = 0;
    for (int j = 0; j < 64; j++)
    {
        if ((n >> j & 1) == 1)
        {
            if (last == 1)
            {
                cout << "No\n";
                return;
            }
            last = 1;
        }
        else last = 0;
    }
    cout << "Yes\n";
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