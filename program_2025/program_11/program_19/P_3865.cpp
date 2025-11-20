// Problem: 【模板】ST 表 & RMQ 问题
// URL: https://www.luogu.com.cn/problem/P3865
// Author: amazy
// Date: 2025-11-19 16:53:49

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

template<typename T>
struct ST 
{
    T op(T a, T b) { return max(a, b); }
    vector<vector<T>> a;
    int n;

    ST(vector<T>& input) 
    {
        n = input.size();

        int max_log = __lg(n);
        a.assign(n, vector<T>(max_log + 1, 0));

        for (int i = 0; i < n; i++) 
            a[i][0] = input[i];

        for (int j = 1; j <= max_log; j++) 
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++) 
            {
                // [i, i + 2 ^ (j - 1) - 1], [i + 2 ^ (j - 1), i + 2 ^ j - 1];
                a[i][j] = op(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) 
    {
        assert(l <= r && l >= 0 && r < n);

        int j = __lg(r - l + 1);
        // [l, l + 2 ^ j - 1], [r - 2 ^ j + 1, r];
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ST st(a);
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