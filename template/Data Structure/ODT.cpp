#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
struct Node {
    int l, r, v;
    // 只需要按 l 排序
    bool operator<(const Node& o) const { return l < o.l; }
};

struct ODT {
    set<Node> s;
    ODT(int n, int val = 0) {
        s.insert({1, n, val});
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
        
        // 如果需要统计 cnt，在这里遍历处理
        // for (auto it = itl; it != itr; ++it) {
        //     cnt[it->v] -= (it->r - it->l + 1);
        // }
        // cnt[val] += (r - l + 1);

        s.erase(itl, itr); // 【极速删除】直接删除范围内所有节点
        s.insert({l, r, val}); // 插入新区间
    }
};
// snippet-end

void solve()
{
    
}

signed main()
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