// Problem: 【模板】Manacher
// URL: https://www.luogu.com.cn/problem/P3805
// Author: amazy
// Date: 2025-11-20 20:37:11

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

/*
start = (i - p[i]) / 2;
end = (i + p[i]) / 2 - 1 = start + p[i] - 1;
[start, end] 代表原始字符串中以 (i) 或者 (i - 1 和 i) 为中心的回文串
构造新字符串时，在每个字符之间插入了一个特殊字符 '#'
*/
vector<int> manacher(string &s)
{
    int n = s.length();
    vector<int> p(n);
    int center = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int mr = 2 * center - i;
        if (i < r)
            p[i] = min(p[mr], r - i);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1])
            p[i]++;

        if (i + p[i] - 1 > r)
        {
            center = i;
            r = i + p[i] - 1;
        }
    }

    return p;
}

void solve()
{
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < s.length(); i++)
    {
        t += '#';
        t += s[i];
    }
    t += '#';
    auto res = manacher(t);
    cout << *max_element(res.begin(), res.end()) << '\n';
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