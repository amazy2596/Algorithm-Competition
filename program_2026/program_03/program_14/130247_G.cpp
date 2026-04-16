// Problem: L1-7 交替子段
// URL: https://ac.nowcoder.com/acm/contest/130247/G
// Author: amazy
// Date: 2026-03-14 14:15:07

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
    vector<int> a;
    int len = 0;
    for (int i = 0; i < n - 1; i++)
    {
        len++;
        if (s[i] == s[i + 1])
        {
            a.push_back(len);
            len = 0;
        }
    }
    len++;
    a.push_back(len);

    sort(a.rbegin(), a.rend());
    int mx = a[0], cnt = 0;
    for (int i = 0; i < a.size(); i++) cnt += (a[i] == mx);
    cout << mx << " " << cnt << "\n";
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