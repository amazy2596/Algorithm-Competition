// Problem: B. New Year Cake
// URL: https://codeforces.com/contest/2182/problem/B
// Author: amazy
// Date: 2025-12-30 17:36:28

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int a, b;
    cin >> a >> b;

    for (int i = 32; i >= 1; i--)
    {
        int x = 0, y = 0;
        for (int j = 0; j < i; j++)
        {
            if (j % 2) x += (1 << j);
            else y += (1 << j);
        }
        if ((x <= a && y <= b) || (x <= b && y <= a))
        {
            cout << i << "\n";
            return;
        }
    }
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