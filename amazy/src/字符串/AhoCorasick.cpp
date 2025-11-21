#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct AhoCorasick 
{
    struct Node
    {
        array<int, 26> nex; // 子节点指针，对于小写字母 'a'-'z'。
        int cnt = 0;        // 记录有多少个模式串经过此节点。
        int end = 0;        // 记录有多少个模式串在此节点结束。
        int fail = 0;       // fail 指针，指向当前节点代表字符串的最长后缀所对应的节点。
        int link = 0;       // 输出链（字典序指针），指向 fail 链上最近的、代表一个完整模式串的节点。用于优化统计。
        int occ = 0;        // 出现次数，在 query 时用于统计该节点代表的模式串在文本串中的出现次数。

        Node() { nex.fill(0); } // 构造时将所有子节点初始化为0（不存在）。
    };

    vector<Node> tree;   // 使用 vector 存储所有节点，构成 Trie 树。tree[0] 是根节点。
    vector<int> endpos;  // 记录每个模式串（按插入顺序）在 Trie 树中结尾节点的索引。
    vector<int> bfs;     // 存储 build 过程中节点的 BFS 遍历顺序，用于 query 时按拓扑序逆序更新 occ。

    AhoCorasick(int n)
    {
        // 创建根节点。
        tree.emplace_back();
        // 根据模式串数量 n，预分配 endpos 数组大小。
        endpos.resize(n);
    } 

    int newNode()
    {
        tree.emplace_back(Node());
        return tree.size() - 1;
    }
    
    /**
     * @brief 将一个模式串插入到 Trie 树中。
     * @param s  要插入的模式串。
     * @param id (可选) 该模式串的唯一ID，用于在 `endpos` 中记录其末尾节点位置。
     */
    void insert(string &s, int id = 0) 
    {
        int u = 0; // 从根节点开始
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a'; // 计算字符对应的索引
            // 如果子节点不存在，则创建一个新节点
            if (!tree[u].nex[c])
                tree[u].nex[c] = newNode();

            // 移动到子节点
            u = tree[u].nex[c];
            tree[u].cnt++; // 经过该节点的模式串数量加一
        }

        tree[u].end++;    // 在结尾节点，标记一个模式串在此结束
        endpos[id] = u; // 记录第 id 个模式串的结尾节点是 u
    }

    /**
     * @brief 构建 AC 自动机。
     *        核心是计算所有节点的 `fail` 指针，并在此过程中“补全”Trie 图。
     */
    void build()
    {
        queue<int> q;
        // 初始化队列，将根节点的所有直接子节点入队
        for (int c = 0; c < 26; c++)
        {
            if (tree[0].nex[c])
            {
                // 第一层节点的 fail 指针都指向根节点 0
                tree[tree[0].nex[c]].fail = 0;
                q.push(tree[0].nex[c]);
            }
        }

        // BFS 遍历所有节点以计算 fail 指针
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // 记录 BFS 顺序，用于后续查询
            bfs.push_back(u);
            
            for (int c = 0; c < 26; c++)
            {
                int v = tree[u].nex[c];
                // 如果节点 u 存在字符 c 的子节点 v
                if (v)
                {
                    // v 的 fail 指针是 u 的 fail 指针所指向的节点沿着相同字符 c 转移得到的节点
                    tree[v].fail = tree[tree[u].fail].nex[c];
                    // 计算 v 的输出链 link
                    int to = tree[v].fail;
                    // 如果 v 的 fail 节点本身就是一个模式串的结尾，则 link 指向它
                    if (tree[to].end > 0)
                        tree[v].link = to;
                    else // 否则，继承 fail 节点的 link
                        tree[v].link = tree[to].link;
                    
                    q.push(v);
                }
                else 
                {
                    // 如果节点 u 没有字符 c 的子节点，则将该路径“补全”
                    // 直接连接到 u 的 fail 节点沿着 c 转移的路径上
                    tree[u].nex[c] = tree[tree[u].fail].nex[c];
                }
            }
        }
    }

    /**
     * @brief 在文本串 s 上执行匹配，并统计每个模式串的出现次数。
     * @param s 文本串。
     */
    void query(string &s)
    {
        int node = 0;
        // 1. 遍历文本串 s，在 AC 自动机上进行匹配
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            // 移动到下一个状态。因为 build 过程补全了路径，所以可以直接转移
            node = tree[node].nex[c];
            // 匹配到的节点出现次数加一
            tree[node].occ++;
        }

        // 2. 沿 fail 链反向更新出现次数
        // 倒序遍历 BFS 序列（相当于拓扑排序的逆序）
        for (int i = bfs.size() - 1; i >= 0; i--)
        {
            int u = bfs[i];
            // 将当前节点的出现次数累加到其 fail 指针指向的节点上
            // 这样就保证了如果匹配到了 "abc"，那么 "bc" 和 "c" (如果它们是模式串) 也会被正确计数
            tree[tree[u].fail].occ += tree[u].occ;
        }
    }
    
    /**
     * @brief 重置所有节点的出现次数 `occ`，以便进行下一次查询。
     */
    void reset()
    {
        // 遍历所有在 build 中访问过的节点（除了根节点）并重置 occ
        for (auto u : bfs)
            tree[u].occ = 0;
        // 单独重置根节点的 occ
        tree[0].occ = 0;
    }
};
