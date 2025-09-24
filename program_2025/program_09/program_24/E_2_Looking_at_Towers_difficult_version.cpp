// Problem: E2. Looking at Towers (difficult version)
// URL: https://codeforces.com/contest/2144/problem/E2
// Author: amazy
// Date: 2025-09-25 00:31:38

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 998244353;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) 
{
    return fast_pow(x, mod - 2);
}

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
        init(vector<Info>(n, Info(0)));
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
        if (lazy[node].empty()) return;

        lazy[node].apply(tree[ls]);
        lazy[node].apply(tree[rs]);

        lazy[ls].merge(lazy[node]);
        lazy[rs].merge(lazy[node]);

        lazy[node] = Tag();
    }
    
    void update(int node, int start, int end, int l, int r, const Tag &val)
    {
        if (end < l || start > r) return;
        if (l <= start && end <= r)
        {
            val.apply(tree[node]);
            lazy[node].merge(val);
            return;
        }

        pushdown(node);
        int mid = (start + end) / 2;
        if (l <= mid) update(ls, start, mid, l, r, val);
        if (mid < r) update(rs, mid + 1, end, l, r, val);
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
        if (pos <= mid) modify(ls, start, mid, pos, val);
        else if (pos > mid) modify(rs, mid + 1, end, pos, val);
        tree[node] = tree[ls] + tree[rs];
    }
    
    Info query(int node, int start, int end, int l, int r)
    {
        if (l > end || r < start) return Info();
        if (l <= start && end <= r) return tree[node];
        pushdown(node);
        int mid = (start + end) / 2;
        return query(ls, start, mid, l, r) + query(rs, mid + 1, end, l, r);
    }
    
    void update(int l, int r, const Tag &val)
    {
        if (l > r) return;
        update(0, 0, n - 1, l, r, val);
    }
    
    void modify(int pos, const Info &val)
    {
        modify(0, 0, n - 1, pos, val);
    }

    Info query(int l, int r)
    {
        if (l > r) return Info();
        return query(0, 0, n - 1, l, r);
    }
};

struct info
{
    i64 val = 0;
    
    info () : val(0) {};
    info (i64 val) : val(val) {};
};

info operator+(const info &l, const info &r)
{
    info res;
    res.val = (l.val + r.val) % mod;

    return res;
}

struct tag
{
    i64 add = 0;
    i64 mul = 1;

    bool has = 0;

    tag() {}
    tag(int _add, int _mul) : add(_add), mul(_mul), has(true) {}

    bool empty() const
    {
        return !has;
    }

    void apply(info &a) const
    {
        a.val = (a.val * mul + add) % mod;
    }

    void merge(const tag &o)
    {
        if (o.empty()) return;
        mul = mul * o.mul % mod;
        add = (o.mul * add + o.add) % mod;
        has = true;
    }
};

// // 区间加
// struct tagAdd
// {
//     i64 add = 0;

//     tagAdd() : add(0) {}
//     tagAdd(i64 _add) : add(_add) {}

//     bool empty() const
//     {
//         return add == 0;
//     }

//     void apply(info &a) const 
//     {
//         i64 old = a.sum;

//         a.mx += add;
//         a.mn += add;
//         a.sum += add * a.len;
//         a.ssum += 2 * add * old + add * add * a.len;
//     }

//     void merge(const tagAdd &o)
//     {
//         if (o.empty())
//             return;

//         add += o.add;
//     }
// };

// // 区间赋值
// struct tagAssign
// {
//     bool has = false;
//     i64 val = 0;

//     tagAssign() : has(false), val(0) {};
//     tagAssign(i64 _val) : has(true), val(_val) {};

//     bool empty() const 
//     {
//         return !has;
//     }

//     void apply(info &a) const
//     {
//         a.mx = val;
//         a.mn = val;
//         a.sum = val * a.len;
//         a.ssum = val * val * a.len;
//     }

//     void merge(const tagAssign &o)
//     {
//         if (!o.has)
//             return;

//         has = true;
//         val = o.val;
//     }
// };

#undef ls
#undef rs

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<i64> L(1, -INF), R(1, -INF);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > L.back())
            L.push_back(a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] > R.back())
            R.push_back(a[i]);
    }

    auto get = [&](vector<i64> &T)
    {
        int k = T.size() - 1;
        // vector<i64> dp(n + 1), c(k + 1, 0), nc(k + 1, 0);
        // c[0] = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (a[i] == T.back()) dp[i] = c[k - 1];
        
        //     nc = c;
        //     for (int j = 0; j < k; j++)
        //     {
        //         if (a[i] <= T[j])
        //             nc[j] = (nc[j] + c[j]) % mod;
        //         if (a[i] == T[j + 1])
        //             nc[j + 1] = (nc[j + 1] + c[j]) % mod;
        //     }
        //     c.swap(nc);
        // }

        vector<i64> dp(n + 1);
        SegmentTree<info, tag> seg(k + 1);
        seg.modify(0, 1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == T.back()) dp[i] = seg.query(k - 1, k - 1).val;

            int j = lower_bound(T.begin(), T.begin() + k, a[i]) - T.begin();
            int t = lower_bound(T.begin() + 1, T.end(), a[i]) - T.begin();
            i64 val = seg.query(t - 1, t - 1).val;

            seg.update(j, k - 1, tag(0, 2));
            if (T[t] == a[i] && t <= k - 1)
                seg.update(t, t, tag(val, 1));
        }

        return dp;
    };

    auto dpL = get(L);
    reverse(a.begin() + 1, a.end());
    auto dp_tmp = get(R);
    reverse(a.begin() + 1, a.end());

    vector<i64> dpR(n + 1);
    for (int i = 1; i <= n; i++)
        dpR[i] = dp_tmp[n - i + 1];

    i64 ans = 0;
    int mx = *max_element(a.begin() + 1, a.end());
    i64 inv2 = inv(2);
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mx)
        {
            ans = (ans + dpR[i] * fast_pow(2, i) % mod * inv2 % mod * pre[i - 1]) % mod;
            ans = (ans + dpL[i] * dpR[i] % mod) % mod;
        }
        pre[i] = (pre[i - 1] + (dpL[i] * inv(fast_pow(2, i)))) % mod;
    }

    cout << ans % mod << "\n";
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