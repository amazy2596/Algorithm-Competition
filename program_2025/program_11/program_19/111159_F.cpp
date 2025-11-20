// Problem: 小红的区间修改（二）
// URL: https://ac.nowcoder.com/acm/contest/111159/F
// Author: amazy
// Date: 2025-11-19 09:06:44

#include <bits/stdc++.h>
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

struct Node {
    int l, r, v;
    // 只需要按 l 排序
    bool operator<(const Node& o) const { return l < o.l; }
};

struct ODT {
    set<Node> s;
    unordered_map<int, int> cnt;
    ODT(int n, int val = 0) {
        s.insert({1, n, val});
        cnt[0] = n;
    }

    auto split(int pos) {
        auto it = s.lower_bound({pos, 0, 0});
        if (it != s.end() && it->l == pos) return it;
        
        it--; 
        int l = it->l, r = it->r, v = it->v;
        s.erase(it); // 删除原区间
        s.insert({l, pos - 1, v}); // 插入左半段
        return s.insert({pos, r, v}).first; // 插入右半段并返回迭代器
    }

    void assign(int l, int r, int val) {
        // 必须先 split 右边，再 split 左边，否则迭代器可能会失效
        auto itr = split(r + 1);
        auto itl = split(l);
        
        for (auto it = itl; it != itr; ++it) {
            auto [L, R, v] = *it;
            cnt[v] -= (R - L + 1);
            if (cnt[v] == 0) cnt.erase(v);
        }
        cnt[val] += r - l + 1;

        s.erase(itl, itr); // 【极速删除】直接删除范围内所有节点
        s.insert({l, r, val}); // 插入新区间
    }
};

void solve()
{
    int q;
    cin >> q;
    ODT odt(1e5 + 5);
    while (q--)
    {
        int l, r, val;
        cin >> l >> r >> val;
        odt.assign(l, r, val);
        cout << odt.cnt.size() << "\n";
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