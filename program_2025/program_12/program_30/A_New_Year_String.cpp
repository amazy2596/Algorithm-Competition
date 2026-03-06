// Problem: A. New Year String
// URL: https://codeforces.com/contest/2182/problem/A
// Author: amazy
// Date: 2025-12-30 17:19:58

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans1 = 0;
    for (int i = 3; i < n; i++)
    {
        if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2' && s[i] == '5')
        {
            ans1++;
        }
    }
    int ans2 = 4;
    for (int i = 3; i < n; i++)
    {
        int tmp = 4;
        if (s[i - 3] == '2') tmp--;
        if (s[i - 2] == '0') tmp--;
        if (s[i - 1] == '2') tmp--;
        if (s[i] == '6') tmp--;
        ans2 = min(ans2, tmp);
    }
    // cout << ans1 << " " << ans2 << "\n";
    cout << min(ans1, ans2) << "\n";
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