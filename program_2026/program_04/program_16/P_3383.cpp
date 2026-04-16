// Problem: 【模板】线性筛素数
// URL: https://www.luogu.com.cn/problem/P3383
// Author: amazy
// Date: 2026-04-16 16:33:17

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> minp(n + 1), prime;
    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto &p : prime)
        {
            if (i * p > n) break;
            minp[i * p] = p;
            if (minp[i] == p) break; 
        }
    }
    while (q--)
    {
        int k;
        cin >> k;
        cout << prime[k - 1] << "\n";
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