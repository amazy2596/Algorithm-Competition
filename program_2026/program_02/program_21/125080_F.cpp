// Problem: 琪露诺的排列构造
// URL: https://ac.nowcoder.com/acm/contest/125080/F
// Author: amazy
// Date: 2026-02-21 17:15:46

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "-1\n";
        return;
    }
    if (n % 2 == 1)
    {
        for (int i = 2; i <= n; i++) cout << i << " ";
        cout << 1 << " \n";
    }
    else if (n % 4 == 0) 
    {
        for (int i = 1; i <= n; i += 4)
        {
            cout << i + 2 << " " << i << " " << i + 3 << " " << i + 1 << " ";
        }
    }
    else
    {
        int m = n - 6;
        for (int i = 1; i <= m; i += 4)
        {
            cout << i + 2 << " " << i << " " << i + 3 << " " << i + 1 << " ";
        }
        cout << m + 2 << " " << m + 3 << " " << m + 1 << " " << m + 6 << " " << m + 4 << " " << m + 5 << "\n";
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