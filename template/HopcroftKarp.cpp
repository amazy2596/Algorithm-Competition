#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

struct HopcroftKarp
{
    int n, m;                     // n: 左部顶点数, m: 右部顶点数
    vector<vector<int>> adj;      // 邻接表，存储从左部到右部的边
    vector<int> pair_u, pair_v;   // 匹配数组。pair_u[u] = v, pair_v[v] = u
    vector<int> dist;             // BFS 中用于记录从左部未匹配点出发的距离

    HopcroftKarp(int size_u, int size_v)
    {
        n = size_u;
        m = size_v;
        pair_u.resize(n + 1, 0);
        pair_v.resize(m + 1, 0);
        dist.resize(n + 1, 0);
        adj.resize(n + 1);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
    }

    /**
     * @brief 通过 BFS 寻找增广路径，并对左部顶点进行分层。
     * @return 如果找到了至少一条增广路径，返回 `true`；否则返回 `false`。
     */
    bool bfs()
    {
        queue<int> q;
        for (int u = 1; u <= n; u++)
        {
            if (pair_u[u] == 0) // 从所有未匹配的左部点开始
            {
                dist[u] = 0;
                q.push(u);
            }
            else
                dist[u] = INT32_MAX;
        }
        dist[0] = INT32_MAX; // 虚拟NIL节点的距离设为无穷大
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (dist[u] >= dist[0]) // 剪枝：如果当前路径长度已超过已找到的增广路，则停止
                continue;
            for (auto v : adj[u])
            {
                if (dist[pair_v[v]] == INT32_MAX) // 如果 v 的匹配点尚未被访问
                {
                    dist[pair_v[v]] = dist[u] + 1;
                    q.push(pair_v[v]);
                }
            }
        }
        return dist[0] != INT32_MAX; // 如果NIL节点被访问，说明找到了增广路
    }

    /**
     * @brief 通过 DFS 在 BFS 构建的分层图上寻找一条增广路径。
     * @param u 当前搜索的左部顶点 (1-based)。
     * @return 如果从 u 出发找到了一条增广路径，返回 `true`；否则返回 `false`。
     */
    bool dfs(int u)
    {
        if (u == 0) // 到达虚拟NIL节点，说明成功找到一条增广路径
            return true;
        for (auto v : adj[u])
        {
            if (dist[pair_v[v]] == dist[u] + 1) // 沿着分层图的边搜索
            {
                if (dfs(pair_v[v])) // 递归查找
                {
                    pair_u[u] = v;
                    pair_v[v] = u;
                    return true;
                }
            }
        }
        dist[u] = INT32_MAX; // 从 u 出发无法找到增广路，将其距离设为无穷，防止后续访问
        return false;
    }

    /**
     * @brief 计算二分图的最大匹配数。
     * @return 最大匹配数。
     */
    int max_matching()
    {
        int matching = 0;
        while (bfs()) // 只要还能找到增广路
        {
            for (int u = 1; u <= n; u++)
            {
                if (pair_u[u] == 0) // 尝试为每个未匹配的左部点寻找增广路
                {
                    if (dfs(u))
                        matching++;
                }
            }
        }
        return matching;
    }

    /**
     * @brief 获取最终的匹配结果。
     * @return 一个向量 `pair_u`，其中 `pair_u[i]` 表示与左部顶点 `i` 匹配的右部顶点。
     */
    vector<int> get_matching()
    {
        return pair_u;
    }
};

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