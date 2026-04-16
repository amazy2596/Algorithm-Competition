// Problem: 【模板】ST 表 & RMQ 问题
// URL: https://www.luogu.com.cn/problem/P3865
// Author: amazy
// Date: 2026-04-16 17:16:20

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct ST
{
    vector<vector<int>> a; 
    int n;

    ST(int _n, vector<int> input)
    {
        n = _n;
        int mxlg = __lg(n + 1);
        a.resize(n + 1, vector<int>(mxlg + 1));
        for (int i = 0; i <= n; i++) a[i][0] = input[i];
        for (int j = 1; j <= mxlg; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r)
    {
        int j = __lg(r - l + 1);
        return max(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ST st(n + 1, a);

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
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