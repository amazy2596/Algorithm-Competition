// Problem: 【模板】数列离散化
// URL: https://www.luogu.com.cn/problem/B3694
// Author: amazy
// Date: 2026-04-16 16:42:46

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), all;
    for (int i = 0; i < n; i++) cin >> a[i], all.push_back(a[i]);

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto get = [&](int x) -> int
    {
        return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
    };

    for (int i = 0; i < n; i++) cout << get(a[i]) << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}