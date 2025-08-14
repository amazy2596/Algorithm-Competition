#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;

const long double eps = 1e-12;
// const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct Trie 
{
    struct Node
    {
        array<int, 26> nex;
        int cnt = 0, end = 0;

        Node() { nex.fill(0); }
    };

    vector<Node> tree;
    Trie(int n = 0)
    {
        tree.reserve(n);
        tree.emplace_back();
    } 

    int newNode()
    {
        tree.emplace_back(Node());
        return tree.size() - 1;
    }
    
    void insert(string s) 
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                tree[p].nex[c] = newNode();

            p = tree[p].nex[c];
            tree[p].cnt++;
        }

        tree[p].end++;
    }

    int find(string s) 
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                return 0;

            p = tree[p].nex[c];
        }

        return tree[p].end;
    }

};

// 模数为梅森素数 2^61 - 1。这是一个巨大的素数，可以有效减少哈希碰撞。
const u64 mod = (1ull << 61) - 1;
// 为多项式哈希随机选择的基数，以防止被特定数据卡掉。
const u64 base = rnd(mod / 2, mod - 1);
// 预处理基数幂次的最大长度。
const int N = 2e5 + 5;
// 存储基数的幂次，即 p[i] = base^i mod (2^61 - 1)。
vector<u64> p(N);

/**
 * @brief 在模 2^61 - 1 下执行加法。
 * @param a 第一个操作数。
 * @param b 第二个操作数。
 * @return 返回 (a + b) mod (2^61 - 1)。
 */
u64 add(u64 a, u64 b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

/**
 * @brief 在模 2^61 - 1 下使用128位整数执行快速乘法。
 * @param a 第一个操作数。
 * @param b 第二个操作数。
 * @return 返回 (a * b) mod (2^61 - 1)。
 */
u64 mul(u64 a, u64 b)
{
    __uint128_t c = __uint128_t(a) * b;
    return add(c >> 61, c & mod);
}

/**
 * @brief 查询子串 s[l..r] 的哈希值。
 *        此实现假设字符串和查询均为1-based索引。
 * @param h 前缀哈希数组，其中 h[i] 是 s[1..i] 的哈希值。
 * @param l 子串的左端点 (包含)。
 * @param r 子串的右端点 (包含)。
 * @return 子串 s[l..r] 的哈希值。
 */
u64 query(const vector<u64> &h, int l, int r)
{
    if (r < l)
        return 0ull;
    return add(h[r], mod - mul(h[l - 1], p[r - l + 1]));
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = mul(p[i - 1], base);
}

/**
 * @brief 为给定的序列 (如 vector<char> 或 vector<int>) 构建前缀哈希数组。
 *        此实现假设输入序列 `s` 是1-based索引 (即 s[0] 是占位符)。
 * @tparam T 序列中元素的类型。
 * @param s 输入的序列。
 * @return 一个前缀哈希数组，其中 `hashed[i]` 对应 s[1..i] 的哈希值。
 */
template<typename T>
vector<u64> build(vector<T> &s)
{
    vector<u64> hashed(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
        hashed[i] = add(mul(hashed[i - 1], base), s[i]);
    return hashed;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    Trie trie(5e5);
    string s;
    cin >> s;
    s = " " + s;
    vector<int> tmp(n + 1);
    for (int i = 1; i <= n; i++)
        tmp[i] = s[i] - 'a' + 1;

    auto hashed = build(tmp);
    
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        trie.insert(t);
    }

    unordered_map<u64, i64> mp;
    auto dfs = [&](auto dfs, int u, int id, u64 last) -> void
    {
        u64 cur = add(mul(last, base), id + 1);
        mp[cur] = mp[last] + trie.tree[u].cnt;
        for (int v = 0; v < 26; v++)
        {
            if (trie.tree[u].nex[v] == 0)
                continue;

            dfs(dfs, trie.tree[u].nex[v], v, cur);
        }
    };

    for (int i = 0; i < 26; i++)
    {
        if (trie.tree[0].nex[i] == 0)
            continue;
        dfs(dfs, trie.tree[0].nex[i], i, 0);
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            u64 cur = query(hashed, i, mid);
            if (mp.count(cur))
                l = mid;
            else 
                r = mid - 1;
        }

        u64 cur = query(hashed, i, l);
        ans = max(ans, mp[cur]);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}