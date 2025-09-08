// Problem: D. Antiamuny Wants to Learn Swap
// URL: https://codeforces.com/contest/2139/problem/D
// Author: amazy
// Date: 2025-09-08 23:51:50

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

#define ls (node * 2 + 1)
#define rs (node * 2 + 2)

template<typename Info, typename Tag>
struct SegmentTree
{
    int n;
    vector<Info> tree;
    vector<Tag> lazy;

    SegmentTree() {}

    SegmentTree(int _n) : n(_n)
    {
        init(vector<Info>(n, Info()));
    }

    template<typename T>
    SegmentTree(const vector<T> &input) : n(input.size())
    {
        init(input);
    }

    template<typename T>
    void init(const vector<T> &input)
    {
        n = input.size();
        tree.resize(4 * n + 5, Info());
        lazy.resize(4 * n + 5, Tag());
        build(0, 0, n - 1, input);
    }
    
    template<typename T>
    void build(int node, int start, int end, const vector<T> &input)
    {
        if (start == end)
        {
            tree[node] = input[start];
        }
        else 
        {
            int mid = (start + end) / 2;
            build(ls, start, mid, input);
            build(rs, mid + 1, end, input);
            tree[node] = tree[ls] + tree[rs];
        }
    }

    void pushdown(int node)
    {
        if (!lazy[node].empty())
        {
            lazy[node].apply(tree[ls]);
            lazy[node].apply(tree[rs]);

            lazy[ls].merge(lazy[node]);
            lazy[rs].merge(lazy[node]);

            lazy[node] = Tag();
        }
    }
    
    void update(int node, int start, int end, int l, int r, const Tag &val)
    {
        if (end < l || start > r)
            return ;

        if (l <= start && end <= r)
        {
            val.apply(tree[node]);
            lazy[node].merge(val);
            return;
        }

        pushdown(node);

        int mid = (start + end) / 2;
        if (l <= mid)
            update(ls, start, mid, l, r, val);
        if (mid < r)
            update(rs, mid + 1, end, l, r, val);
        
        tree[node] = tree[ls] + tree[rs];
    }

    void modify(int node, int start, int end, int pos, const Info &val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }

        pushdown(node);

        int mid = (start + end) / 2;
        if (pos <= mid)
            modify(ls, start, mid, pos, val);
        else if (pos > mid)
            modify(rs, mid + 1, end, pos, val);

        tree[node] = tree[ls] + tree[rs];
    }
    
    Info query(int node, int start, int end, int l, int r)
    {
        if (l > end || r < start) 
            return Info();
            
        if (l <= start && end <= r) 
            return tree[node];

        pushdown(node);
            
        int mid = (start + end) / 2;
        return query(ls, start, mid, l, r) + query(rs, mid + 1, end, l, r);
    }
    
    void update(int l, int r, const Tag &val)
    {
        if (l > r) 
            return;
        update(0, 0, n - 1, l, r, val);
    }
    
    void modify(int pos, const Info &val)
    {
        modify(0, 0, n - 1, pos, val);
    }

    Info query(int l, int r)
    {
        if (l > r) 
            return Info();
        return query(0, 0, n - 1, l, r);
    }
};

struct info
{
    i64 mx = -INF;
    i64 mn = INF;
    i64 sum = 0;
    i64 ssum = 0;
    int len = 0;
    
    info () : mx(-INF), mn(INF), sum(0), ssum(0), len(0) {};
    info (i64 val) : mx(val), mn(val), sum(val), ssum(val * val), len(1) {};
};

info operator+(const info &l, const info &r)
{
    info res;
    res.mx = max(l.mx, r.mx);
    res.mn = min(l.mn, r.mn);
    res.sum = l.sum + r.sum;
    res.ssum = l.ssum + r.ssum;
    res.len = l.len + r.len;

    return res;
}

// 区间加
struct tagAdd
{
    i64 add = 0;

    tagAdd() : add(0) {}
    tagAdd(i64 _add) : add(_add) {}

    bool empty() const
    {
        return add == 0;
    }

    void apply(info &a) const 
    {
        i64 old = a.sum;

        a.mx += add;
        a.mn += add;
        a.sum += add * a.len;
        a.ssum += 2 * add * old + add * add * a.len;
    }

    void merge(const tagAdd &o)
    {
        if (o.empty())
            return;

        add += o.add;
    }
};

// 区间赋值
struct tagAssign
{
    bool has = false;
    i64 val = 0;

    tagAssign() : has(false), val(0) {};
    tagAssign(i64 _val) : has(true), val(_val) {};

    bool empty() const 
    {
        return !has;
    }

    void apply(info &a) const
    {
        a.mx = val;
        a.mn = val;
        a.sum = val * a.len;
        a.ssum = val * val * a.len;
    }

    void merge(const tagAssign &o)
    {
        if (!o.has)
            return;

        has = true;
        val = o.val;
    }
};

#undef ls
#undef rs

void solve()
{
    // int n = 6;
    // vector<int> a(n);
    // iota(a.begin(), a.end(), 1);
    // do
    // {
    //     auto tmp = a;
    //     int ans1 = 0, ans12 = 0;
    //     while (!is_sorted(tmp.begin(), tmp.end()))
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             if (i + 1 < n && tmp[i] > tmp[i + 1])
    //             {
    //                 swap(tmp[i], tmp[i + 1]);
    //                 ans1++;
    //             }
    //         }
    //     }

    //     tmp = a;
    //     while (!is_sorted(tmp.begin(), tmp.end()))
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             if (i + 2 < n && tmp[i] > tmp[i + 2])
    //             {
    //                 swap(tmp[i], tmp[i + 2]);
    //                 ans12++;
    //             }
    //             if (i + 1 < n && tmp[i] > tmp[i + 1])
    //             {
    //                 swap(tmp[i], tmp[i + 1]);
    //                 ans12++;
    //             }
    //         }
    //     }

    //     int rev = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (a[j] > a[i])
    //                 rev++;
    //         }
    //     }

    //     if (ans12 != ans1) 
    //     {
    //         bool f = 0;
    //         for (int i = 0; i < n; i++)
    //         {
    //             for (int j = i + 1; j < n; j++)
    //             {
    //                 for (int k = j + 1; k < n; k++)
    //                 {
    //                     f = 1;
    //                     break;
    //                 }
    //             }
    //         }

    //         if (!f)
    //         {
    //             f = 0;
    //             for (int i = 0; i < n; i++)
    //             {
    //                 for (int j = i + 1; j < n; j++)
    //                 {
    //                     for (int k = j + 1; k < n; k++)
    //                     {
    //                         for (int l = k + 1; l < n; l++)
    //                         {
    //                             if (a[i] < a[j] && a[k] < a[l] && min(a[i], a[j]) > max(a[k], a[l]))
    //                             {
    //                                 f = 1;
    //                                 break;
    //                             }
    //                         }
    //                     }
    //                 }
    //             }

    //             if (!f)
    //             {
    //                 cout << "rev: " << rev << "\n";
    //                 cout << "ans1: " << ans1 << "\n";
    //                 cout << "ans12: " << ans12 << "\n";
    //                 for (auto x : a) cout << x << " ";
    //                 cout << "\n";
    //             }
    //         }
    //     }
    // } while (next_permutation(a.begin(), a.end()));

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> mn, mx;
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (mx.size() && a[mx.back()] <= a[i])
            mx.pop_back();
        pre[i] = mx.size() ? mx.back() : 0;
        mx.push_back(i);
    }

    for (int i = n; i >= 1; i--)
    {
        while (mn.size() && a[mn.back()] >= a[i])
            mn.pop_back();
        suf[i] = mn.size() ? mn.back() : n + 1;
        mn.push_back(i);
    }

    vector<tuple<int, int, int>> query(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r, i};
    }

    sort(query.begin(), query.end());
    SegmentTree<info, tagAdd> tree(n + 2);
    vector<vector<int>> bucket(n + 1);
    for (int i = 1; i <= n; i++)
    {
        bucket[pre[i]].push_back(i);
        if (pre[i] >= 1) tree.modify(i, suf[i]);
        else tree.modify(i, info());
    }

    vector<int> ans(q);
    int curL = 1;
    for (auto [l, r, id] : query)
    {
        while (curL < l)
        {
            for (int j : bucket[curL])
            {
                tree.modify(j, info());
            }
            curL++;
        }

        if (r - l + 1 < 3)
        {
            ans[id] = 1;
            continue;
        }

        auto res = tree.query(l, r).mn;
        ans[id] = (res <= r ? 0 : 1);
    }

    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "YES\n" : "NO\n");
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}