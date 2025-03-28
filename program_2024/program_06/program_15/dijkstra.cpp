#include<iostream>
#include<queue>
#include<cstdint>
using namespace std;

// 定义常量大小
const int N = 2e5 + 5;
int head[N], ver[N], Next[N], edge[N], tot = 0;

// 添加边的函数
void add(int x, int y, int z)
{
    ver[++tot] = y; // 记录终点
    edge[tot] = z; // 记录边的权重
    Next[tot] = head[x]; // 链接到之前的边
    head[x] = tot; // 更新链表头
}

// 定义节点结构体
struct node {
    int dist, y; // dist 表示距离，y 表示节点
};

// 重载小于运算符用于优先队列的比较
const bool operator<(const node &a, const node &b)
{
    return a.dist > b.dist; // 按照距离的反序排列（小根堆）
}

bool vis[N]; // 访问标记数组
int mn[N]; // 最短距离数组

// 初始化函数
void init()
{
    for (int i = 0; i <= N; i++)
        vis[i] = 0, mn[i] = INT32_MAX; // 初始化访问标记和最短距离
}

// Dijkstra算法实现
void dijkstra(int s)
{
    init(); // 初始化
    priority_queue<node> q; // 定义优先队列
    q.push({0, s}); // 起点入队
    mn[s] = 0; // 起点到自身的距离为0
    while (!q.empty())
    {
        int x = q.top().y; // 取队首元素
        q.pop();
        if (vis[x])
            continue; // 如果该节点已访问，跳过
        vis[x] = 1; // 标记该节点已访问
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i], z = edge[i]; // 获取邻接节点和边的权重
            if (mn[y] > mn[x] + z)
            {
                mn[y] = mn[x] + z; // 更新最短距离
                q.push({mn[y], y}); // 邻接节点入队
            }
        }
    }
}

int main()
{
    // 4 6 1
    int n, m, s;
    cin >> n >> m >> s; // 输入节点数、边数和起点
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z; // 输入边的信息
        add(x, y, z); // 添加边
        add(y, x, z);
    }
    dijkstra(s); // 运行Dijkstra算法
    for (int i = 1; i <= n; i++)
        cout << mn[i] << " "; // 输出每个节点的最短距离
    return 0;
}


// 输入
// 4 6 1
// 1 2 2
// 2 3 2
// 2 4 1
// 1 3 5
// 3 4 3
// 1 4 4

// 输出
// 0 2 4 3

