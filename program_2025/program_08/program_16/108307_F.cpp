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
    int idx = -1;
    int len = 0;
    
    info () : mx(-INF), mn(INF), sum(0), ssum(0), len(0), idx(-1) {};
    info (i64 val) : mx(val), mn(val), sum(val), ssum(val * val), len(1), idx(-1) {};
    info (i64 val, int _idx) : mx(val), mn(val), sum(val), ssum(val * val), len(1), idx(_idx) {};
    
    info operator+(const info &o) const
    {
        info res;
        res.mx = max(mx, o.mx);
        res.mn = min(mn, o.mn);
        res.sum = sum + o.sum;
        res.ssum = ssum + o.ssum;
        res.len = len + o.len;

        if (mx > o.mx)
            res.idx = idx;
        else 
            res.idx = o.idx;

        return res;
    }
};

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

// 区间加乘
struct tagAddMul
{
    i64 add = 0, mul = 1;

    tagAddMul() : add(0), mul(1) {}
    tagAddMul(i64 _add, i64 _mul) : add(_add), mul(_mul) {}

    bool empty() const 
    {
        return mul == 1 && add == 0;
    }

    void apply(info &o) const 
    {
        i64 old_sum = o.sum;
        i64 old_ssum = o.ssum;

        o.mx = o.mx * mul + add;
        o.mn = o.mn * mul + add;

        o.sum = old_sum * mul + add * o.len;
        o.ssum = old_ssum * mul * mul + 2 * old_sum * mul * add + o.len * add * add;
    }

    void merge(const tagAddMul &o)
    {
        mul = mul * o.mul;
        add = add * o.mul + o.add;
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

struct tagAddMIN
{
    tagAdd tagadd;
    i64 mn = INF;

    tagAddMIN() : tagadd(), mn(INF) {}
    tagAddMIN(tagAdd _tagadd) : tagadd(_tagadd) {}
    tagAddMIN(i64 _mn) : mn(_mn) {}

    bool empty() const
    {
        return tagadd.empty() && mn == INF;
    }

    void apply(info &a) const
    {
        tagadd.apply(a);
        a.mn = min(a.mn, mn);
        a.mx = min(a.mx, mn);
    }

    void merge(const tagAddMIN &o)
    {
        tagadd.merge(o.tagadd);
        mn = min(mn + o.tagadd.add, o.mn);
    }
};

#undef ls
#undef rs

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    unordered_map<int, vector<int>> idx;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 2; i--)
        idx[a[i]].push_back(i);

    unordered_map<int, int> mp, mp1, mp2, mp3;
    mp1[a[1]] = 1;
    mp2[a[2]] = 1;

    for (int i = 3; i <= n; i++)
    {
        mp3[a[i]]++;
        if (mp1.count(a[i]) && mp2.count(a[i]))
            mp[a[i]]++;
    }

    vector<info> input(n + 1, info(0));
    input[3] = info(mp.size(), 3);
    for (int i = 4; i <= n; i++)
    {
        mp3[a[i - 1]]--;
        mp2[a[i - 1]]++;
        
        if(mp.count(a[i - 1])) {
            if(!mp1[a[i - 1]] || !mp2[a[i - 1]] || !mp3[a[i - 1]]) {
                mp.erase(a[i - 1]);
            }
        } else {
            if(mp1[a[i - 1]] && mp2[a[i - 1]] && mp3[a[i - 1]]) {
                mp[a[i - 1]] = 1;
            }
        }

        input[i] = info(mp.size(), i);
    }

    SegmentTree<info, tagAdd> tree(input);

    auto tmp = tree.query(3, n);
    int ans = tmp.mx;
    int b1 = 2, b2 = tmp.idx;

    for (int i = 3; i <= n; i++)
    {
        idx[a[i - 1]].pop_back();
        if (mp1[a[i - 1]] > 0 && idx[a[i - 1]].size())
        {
            int l = i;
            int r = idx[a[i - 1]].back();
            tree.update(l, r, -1);
        }
        else if (idx[a[i - 1]].size())
        {
            int l = idx[a[i - 1]].back() + 1;
            int r = idx[a[i - 1]].front();
            tree.update(l, r, 1);
        }

        auto res = tree.query(i + 1, n);
        if (res.mx > ans)
        {
            ans = res.mx;
            b1 = i, b2 = res.idx;
        }

        mp1[a[i - 1]]++;
    }

    cout << ans << "\n";
    cout << b1 << " " << b2 << "\n";
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