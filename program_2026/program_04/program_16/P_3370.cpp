// Problem: 【模板】字符串哈希
// URL: https://www.luogu.com.cn/problem/P3370
// Author: amazy
// Date: 2026-04-16 16:11:48

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

using u64 = uint64_t;
struct StringHash
{
    vector<u64> hashed;
    static vector<u64> p;
    const u64 base = 131;

    void init()
    {
        p[0] = 1;
        for (int i = 1; i < 3e6; i++) p[i] = p[i - 1] * base;
    }

    StringHash(string &s)
    {
        p.resize(3e6);
        hashed.resize(s.length() + 1);
        for (int i = 1; i <= s.length(); i++) 
            hashed[i] = hashed[i - 1] * base + s[i - 1];
    }

    u64 query(int l, int r)
    {
        return hashed[r + 1] - (hashed[l] * p[r - l + 1]);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
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