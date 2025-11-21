// Problem: 【模板】KMP
// URL: https://www.luogu.com.cn/problem/P3375
// Author: amazy
// Date: 2025-11-20 20:28:05

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

vector<int> kmp(const string &s) 
{
    vector<int> v(s.size());
    for(int i = 1, j = 0; i < s.size(); ++i) 
    {
        while(j > 0 && s[i] != s[j]) j = v[j - 1];
        if(s[i] == s[j]) j++;
        v[i] = j;
    }
    return v;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    string tmp = t + '#' + s;
    auto pi = kmp(tmp);
    vector<int> res;
    for(int i = t.size() + 1; i < tmp.size(); ++i)
    {
        if(pi[i] == t.size())
        {
            cout << i - 2 * t.size() + 1 << '\n';
        }
    }
    for (int i = 0; i < t.size(); ++i)
    {
        cout << pi[i] << " ";
    }
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