// Problem: L1-5 自然语言大模型
// URL: https://ac.nowcoder.com/acm/contest/104429/E
// Author: amazy
// Date: 2026-03-05 16:53:54

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        mp[a] = b;
    }

    string s;
    getline(cin, s);
    if (mp.find(s) != mp.end()) cout << mp[s];
    else cout << "The server is busy, please try again later.";
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