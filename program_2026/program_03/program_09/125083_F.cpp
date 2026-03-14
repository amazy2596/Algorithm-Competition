// Problem: Sequence Covering
// URL: https://ac.nowcoder.com/acm/contest/125083/F
// Author: amazy
// Date: 2026-03-09 15:30:35

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct ST 
{
    pair<i64, i64> op(pair<i64, i64> a, pair<i64, i64> b) 
    { 
        if (a.first != b.first) return a.first > b.first ? a : b;
        return a.second < b.second ? a : b;
    }
    vector<vector<pair<i64, i64>>> a;
    int n;

    ST(vector<pair<i64, i64>>& input) 
    {
        n = input.size();

        int max_log = __lg(n);
        a.assign(n, vector<pair<i64, i64>>(max_log + 1, {0, 0}));

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

    pair<i64, i64> query(int l, int r) 
    {
        assert(l <= r && l >= 0 && r < n);

        int j = __lg(r - l + 1);
        // [l, l + 2 ^ j - 1], [r - 2 ^ j + 1, r];
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<i64> a(n + 1, -1e9);
    vector<pair<i64, i64>> input(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], input[i].first = a[i], input[i].second = i;
    ST st(input);

    int i = 1;
    while (i <= n && k > 0)
    {
        auto [valr, idr] = st.query(i, min(n, i + k));
        int vall = a[i - 1];
        if (valr >= vall)
        {
            int j = i;
            while (j <= idr) a[j] = valr, j++;
            k -= idr - i;
            i = j;
        }
        else 
        {
            a[i] = a[i - 1];
            k--;
            i++;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
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