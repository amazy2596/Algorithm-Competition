#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
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
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

/**
 * @brief 回文自动机 (PAM - Palindromic Automaton)，也称回文树。
 *        用于在线性时间内处理字符串的所有回文子串信息。
 */
struct PAM
{
    /**
     * @brief PAM 的节点结构。
     */
    struct node
    {
        array<int, 26> nex; // 子节点指针，nex[c] 指向在当前回文串两端加上字符 c 构成的新回文串节点。
        int fail = 0;       // fail 指针，指向当前节点代表的回文串的最长回文后缀所对应的节点。
        int len = 0;        // 当前节点代表的回文串的长度。
        int end = 0;        // 记录以当前节点代表的回文串为后缀的次数。调用 count() 后，变为在整个串中的出现次数。
        int num = 0;        // 当前节点代表的回文串所包含的回文后缀数量 (包括自身)。
    };

    vector<node> tree; // 使用 vector 存储所有节点。
    string s;          // 存储构建 PAM 的字符串，为方便处理，下标从 1 开始。
    int last;          // 指向当前已处理字符串的最长回文后缀所对应的节点。

    /**
     * @brief 构造函数，初始化回文自动机。
     *        创建两个根节点：0号节点（偶根，长度为0）和1号节点（奇根，长度为-1）。
     */
    PAM()
    {
        tree.emplace_back(); // 0号节点
        tree.emplace_back(); // 1号节点
        tree[0].len = 0;
        tree[1].len = -1;

        tree[0].fail = 1; // 偶根的 fail 指向奇根
        tree[1].fail = 1; // 奇根的 fail 指向自身（或偶根，视实现而定）

        s = " ";  // 字符串下标从1开始，s[0]为占位符
        last = 0; // 初始时，最长回文后缀是空串，对应0号节点
    }

    /**
     * @brief 创建一个新节点。
     * @return 返回新节点在节点数组中的索引。
     */
    int newNode()
    {
        tree.emplace_back();
        return tree.size() - 1;
    }

    /**
     * @brief 沿着 fail 链寻找一个合适的父节点。
     *        该父节点 u 满足：s[i] + u的回文串 + s[i] 也是一个回文串。
     * @param u 当前的 last 节点索引。
     * @param i 新增字符 s[i] 的索引。
     * @return 合适的父节点的索引。
     */
    int getFail(int u, int i)
    {   
        // s[i - tree[u].len - 1] 是 u 对应回文串的前一个字符
        while (s[i - tree[u].len - 1] != s[i])
            u = tree[u].fail;
        return u;
    }

    /**
     * @brief 向自动机中插入一个新字符。
     * @param ch 要插入的字符。
     * @param i  字符在原字符串中的1-based索引。
     */
    void insert(char ch, int i)
    {
        s += ch;
        int c = ch - 'a';
        // 找到能扩展成新回文串的、当前串的最长回文后缀节点 u
        int u = getFail(last, i);

        // 如果这个新回文串不存在
        if (!tree[u].nex[c])
        {
            int v = newNode(); // 创建新节点 v

            tree[v].len = tree[u].len + 2;
            // v 的 fail 指针是 u 的 fail 链上第一个能扩展成回文串的节点
            tree[v].fail = tree[getFail(tree[u].fail, i)].nex[c];
            tree[v].num = tree[tree[v].fail].num + 1;
            
            tree[u].nex[c] = v;
        }

        // 更新 last 节点
        last = tree[u].nex[c];
        tree[last].end++;
    }

    /**
     * @brief 统计每个本质不同回文子串在整个字符串中的出现次数。
     *        必须在所有字符插入后调用。
     *        利用 fail 树的性质，从叶节点向根节点累加 end 计数。
     */
    void count()
    {
        // 从后往前遍历节点（拓扑序的逆序），确保子节点的贡献先计算
        for (int u = tree.size() - 1; u >= 2; u--)
            tree[tree[u].fail].end += tree[u].end;
    }
};