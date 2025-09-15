// Problem: 小红的线下查询
// URL: https://ac.nowcoder.com/acm/contest/116945/F
// Author: amazy
// Date: 2025-09-15 10:40:59

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

using namespace __gnu_pbds;
template<class Key>
using ordered_set = tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int n, q; 
    cin >> n >> q;
    
    struct P 
    {
        i64 u, v; 
        int id; 
    };
    vector<P> pts(n);
    for (int i = 0; i < n; ++i) 
    {
        i64 x, y; 
        cin >> x >> y;
        pts[i] = {y - x, y + x, i};
    }

    struct Q 
    { 
        i64 k1, k2; 
        int id; 
    };

    vector<Q> qs(q);
    for (int i = 0; i < q; ++i) 
    {
        i64 k1, k2; 
        cin >> k1 >> k2;
        qs[i] = {k1, k2, i};
    }

    sort(pts.begin(), pts.end(), [](const P &a, const P &b) {
        if (a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });
    sort(qs.begin(), qs.end(), [](const Q &a, const Q &b) {
        if (a.k1 != b.k1) return a.k1 < b.k1;
        return a.k2 < b.k2;
    });

    ordered_set<pair<i64,int>> os;
    vector<i64> ans(q, 0);

    int ptr = 0;
    for (const auto& qu : qs) 
    {
        while (ptr < n && pts[ptr].u < qu.k1) 
        {
            os.insert({pts[ptr].v, pts[ptr].id});
            ++ptr;
        }
        i64 cnt = os.order_of_key({qu.k2, INT_MIN});
        ans[qu.id] = cnt;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}