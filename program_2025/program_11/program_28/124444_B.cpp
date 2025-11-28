// Problem: 回文判断
// URL: https://ac.nowcoder.com/acm/contest/124444/B
// Author: amazy
// Date: 2025-11-28 22:20:40

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1]) 
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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