// Problem: L1-6 众筹
// URL: https://ac.nowcoder.com/acm/contest/130247/F
// Author: amazy
// Date: 2026-03-14 14:12:37

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<char> ch;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        char mx = ' ';
        for (int j = 0; j < s.length(); j++) mx = max(mx, s[j]);
        ch.push_back(mx);
    }

    sort(ch.rbegin(), ch.rend());
    for (int i = 0; i < ch.size(); i++) cout << ch[i];
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