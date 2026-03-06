// Problem: 恋恋的01串大冒险
// URL: https://ac.nowcoder.com/acm/contest/124143/D
// Author: amazy
// Date: 2026-02-21 14:41:03

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    int len = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0') len++;
        else len = 0;
        if (len == k)
        {
            ans.push_back(i - 1);
            len = 0;
        }
    }
    while (ans.size() != n + 1) ans.push_back(n);
    for (int x : ans) cout << x << " ";
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