// Problem: C - Except and Min
// URL: https://atcoder.jp/contests/abc448/tasks/abc448_c
// Author: amazy
// Date: 2026-03-13 11:11:33

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    multiset<int> s;
    for (int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        s.insert(a[i]);
    }

    while (q--)
    {
        int k;
        cin >> k;
        vector<int> b(k);
        for (int i = 0; i < k; i++) cin >> b[i], s.extract(a[b[i]]);
        cout << *s.begin() << "\n";
        for (int i = 0; i < k; i++) s.insert(a[b[i]]);
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