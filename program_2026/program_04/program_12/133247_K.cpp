// Problem: ATM9毕业中
// URL: https://ac.nowcoder.com/acm/contest/133247/K
// Author: amazy
// Date: 2026-04-12 21:54:47

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

void solve()
{
    int n;
    cin >> n;
    
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    int N_seg = n;
    vector<pair<int, int>> tree(2 * N_seg);
    for (int i = 0; i < N_seg; i++) tree[N_seg + i] = {0, i + 1};
    for (int i = N_seg - 1; i > 0; i--) tree[i] = min(tree[i << 1], tree[i << 1 | 1]);

    auto update = [&](int p, int val) 
    {
        p--;
        for (tree[p += N_seg].first = val; p >>= 1; ) 
        {
            tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
        }
    };

    auto query = [&](int l, int r) 
    {
        l--; 
        pair<int, int> res = {1e9, -1};
        for (l += N_seg, r += N_seg; l < r; l >>= 1, r >>= 1) 
        {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    };

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        pair<int, int> min1 = query(1, b[i]);
        if (min1.first > i - b[i]) 
        {
            cout << -1 << '\n';
            return;
        }
        
        int idx = min1.second;
        pair<int, int> min2 = {1e9, -1};
        
        if (idx > 1) min2 = min(min2, query(1, idx - 1));
        if (idx < b[i]) min2 = min(min2, query(idx + 1, b[i]));

        if (min2.first <= i - b[i]) 
        {
            cout << -1 << '\n';
            return;
        }

        a[i] = idx;
        update(idx, i);
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}