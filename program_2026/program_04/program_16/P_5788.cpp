// Problem: 【模板】单调栈
// URL: https://www.luogu.com.cn/problem/P5788
// Author: amazy
// Date: 2026-04-16 16:46:56

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), f(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        while (stk.size() && a[i] >= a[stk.top()]) stk.pop();
        if (stk.size()) f[i] = stk.top() + 1;
        stk.push(i);
    }
    for (int i = 0; i < n; i++) cout << f[i] << " ";
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