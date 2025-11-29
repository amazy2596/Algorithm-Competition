// Problem: k进制？
// URL: https://ac.nowcoder.com/acm/contest/124444/H
// Author: amazy
// Date: 2025-11-29 00:04:12

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    auto id = [&](char ch)
    {
        if ('0' <= ch && ch <= '9') return (ch - '0');
        if ('A' <= ch && ch <= 'Z') return (ch - 'A' + 10);
        return -1;
    };

    auto cmp = [&](const string &s1, const string &s2) 
    {
        if (s1.length() > s2.length()) return true;
        if (s1.length() < s2.length()) return false;
        return s1 > s2; 
    };

    string ans, cur;
    for (auto ch : s)
    {
        if (ch == '0')
        {
            if (cmp("0", ans))
            {
                ans = "0";
            }
        }
        if (cur.empty() && ch == '0') continue;
        if (('a' <= ch && ch <= 'z') || id(ch) >= k)
        {
            if (!cur.empty())
            {
                if (cmp(cur, ans))
                {
                    ans = cur;
                }
            }
            cur = "";
            continue;
        }
        cur += ch;
    }
    if (cmp(cur, ans)) ans = cur;

    if (ans.empty()) cout << "-1\n";
    else cout << ans << "\n";
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