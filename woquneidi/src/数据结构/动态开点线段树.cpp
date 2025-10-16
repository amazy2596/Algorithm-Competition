#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ls (id->lchild)
#define rs (id->rchild)
template<class Info, class Tag, class T = i64>
struct SegmentTree{
    struct Node {
        Node* lchild = nullptr;
        Node* rchild = nullptr;
        Info info;
        Tag tag;
    };
    T L, R;
    Node* root = nullptr;
    
    SegmentTree(T l, T r) : L(l), R(r) {
        root = new Node();
        (root->info).len = r - l + 1;
    }
    SegmentTree(T n) : SegmentTree(0, n) {}

    void apply(Node* id,const Tag &dx) {
        id->info.apply(dx);
        id->tag.apply(dx);
    }

    void pushdown(Node* id, T l, T r) {
        T mid = l + r >> 1;
        if (ls == nullptr) {
            ls = new Node();
            ls->info.len = mid - l + 1; 
        }
        if (rs == nullptr) {
            rs = new Node();
            rs->info.len = r - mid;
        }
        apply(ls, id->tag);
        apply(rs, id->tag);
        id->tag = Tag();
    }

    void pushup(Node* id) {
        id->info = ls->info + rs->info;
    }

    void rangeUpdate(Node* id, T l, T r, T x, T y,const Tag &dx) {
        
        if (x <= l && y >= r) {
            apply(id, dx);
            return;
        }

        T mid = l + r >> 1;
        
        pushdown(id, l, r);

        if (x <= mid) {
            rangeUpdate(ls, l, mid, x, y, dx);
        }   
        if (y > mid) {
            rangeUpdate(rs, mid + 1, r, x, y, dx);
        }
        pushup(id);
    }
    void modify(Node* id, T l, T r, T pos, const Info &val) {
        if (l == r) {
             id->info = val;
             return;
        }
        pushdown(id, l, r);
        T mid = l + r >> 1;
        if (pos <= mid) {
            modify(ls, l, mid, pos, val);
        } else {
            modify(rs, mid + 1, r, pos, val);
        }
        pushup(id);
    }


    Info rangeQuery(Node* id, T l, T r, T x, T y) {
        if (l >= x && r <= y) {
            return id->info;
        }
        Info res;
        T mid = l + r >> 1;
        
        pushdown(id, l, r);

        if (x <= mid) {
            res = res + rangeQuery(ls, l, mid, x, y);
        }
        if (y > mid) {
            res = res + rangeQuery(rs, mid + 1, r, x, y);
        }
        return res;
    }



    void rangeUpdate(T x, T y, const Tag &dx) {
        rangeUpdate(root, L, R, x, y, dx);
    }
    void modify(T pos, const Info &val) {
        modify(root, L, R, pos, val);
    }
    Info rangeQuery(T x, T y) {
        return rangeQuery(root, L, R, x, y);
    }
};
#undef ls
#undef rs
struct Tag {
    i64 add = 0;
    void apply(const Tag &dx) {
        add += dx.add;
    }
};

struct Info{
    i64 sum = 0;
    i64 len = 0;

    void apply(const Tag &dx) {
        sum += (dx.add * len);
    }
};
Info operator+(const Info a, const Info b) {
    Info res;
    res.sum = a.sum + b.sum;
    res.len = a.len + b.len;
    return res;
}



void solve() {
    int n, m;
    cin >> n >> m;
    SegmentTree<Info, Tag> seg(1, n);
    while(m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            Tag tag;
            tag.add = k;
            seg.rangeUpdate(l, r, tag);
            // cout << 1 << endl;
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.rangeQuery(l, r).sum << '\n';
            // cout << 2 << endl;
        }
    }





}


int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T = 1;
    //cin >> T;
    while (T--) solve();

    return 0;
}