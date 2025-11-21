// Problem: 【模板】扩展 KMP/exKMP（Z 函数）
// URL: https://www.luogu.com.cn/problem/P5410
// Author: amazy
// Date: 2025-11-20 21:25:10

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

vector<int> Z(const string &s) 
{
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) 
    {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) 
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z[0] = n; 
    return z;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    auto z = Z(b);
    string tmp = b + "#" + a;
    auto p = Z(tmp);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < z.size(); i++)
    {
        ans1 ^= (i + 1) * (z[i] + 1);
    }
    for (int i = b.length() + 1; i < p.size(); i++)
    {
        ans2 ^= (i - b.length()) * (p[i] + 1);
    }

    cout << ans1 << "\n" << ans2 << '\n';
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