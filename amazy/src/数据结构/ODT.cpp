#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;


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
        s.erase(it);
        s.insert({l, pos - 1, v});
        return s.insert({pos, r, v}).first;
    }

    void assign(int l, int r, int val) {
        auto itr = split(r + 1);
        auto itl = split(l);
        
        // 如果需要统计 cnt，在这里遍历处理
        // for (auto it = itl; it != itr; ++it) {
        //     cnt[it->v] -= (it->r - it->l + 1);
        // }
        // cnt[val] += (r - l + 1);

        s.erase(itl, itr);
        s.insert({l, r, val});
    }
};
