// Problem: TSC 的糖分投喂计划
// URL: https://ac.nowcoder.com/acm/contest/133247/I
// Author: amazy
// Date: 2026-04-12 17:26:43

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct ST
{
    i64 op(i64 a, i64 b) { return min(a, b); }
    vector<vector<i64>> a;
    int n;

    ST(vector<int> &input)
    {
        n = input.size();
        int max_log = __lg(n);
        a.assign(n, vector<i64>(max_log + 1));
        for (int i = 0; i < n; i++) a[i][0] = input[i];

        for (int j = 1; j <= max_log; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                a[i][j] = op(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    i64 query(int l, int r)
    {
        assert(l <= r && l >= 0 && r < n);
        int j = __lg(r - l + 1);
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1, 2e9), y(n + 1, 2e9);
    for (int i = 1; i <= k; i++)
    {
        int t, a;
        cin >> t >> a;
        x[t] = a - t;
        y[t] = a + t;
    }
    ST l(x), r(y);
    for (int j = 1; j <= n; j++)
    {
        i64 left = l.query(1, j);
        i64 right = r.query(j, n);
        cout << min(left + j, right - j) << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}