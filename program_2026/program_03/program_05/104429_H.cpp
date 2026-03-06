// Problem: L1-8 回文复回文
// URL: https://ac.nowcoder.com/acm/contest/104429/H
// Author: amazy
// Date: 2026-03-05 17:15:47

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    string s;
    getline(cin, s);
    while (true)
    {
        int n = s.length();
        int l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!(i - j >= 0 && i + j < n)) break;
                if (s[i - j] == s[i + j]) 
                {
                    if (2 * j + 1 > r - l + 1)
                    {
                        l = i - j;
                        r = i + j;
                    }
                    // else if (2 * j + 1 == r - l + 1 && i - j < l)
                    // {
                    //     l = i - j;
                    //     r = i + j;
                    // }
                }
                else break;
            }

            for (int j = 0; j < n; j++)
            {
                if (!(i - j >= 0 && i + j + 1 < n)) break;
                if (s[i - j] == s[i + j + 1])
                {
                    if (2 * j + 2 > r - l + 1)
                    {
                        l = i - j;
                        r = i + j + 1;
                    }
                    // else if (2 * j + 2 == r - l + 1 && i - j < l)
                    // {
                    //     l = i - j;
                    //     r = i + j + 1;
                    // }
                }
                else break;
            }
        }
        if (r - l + 1 <= 1) break;
        s.erase(s.begin() + (r + l) / 2 + 1, s.begin() + r + 1);
    }

    cout << s << "\n";
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