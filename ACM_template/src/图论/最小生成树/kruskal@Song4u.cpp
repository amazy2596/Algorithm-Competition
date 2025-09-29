// //克鲁斯卡尔
// //每个点最初是一个连通块，每次选取边权最小的边，当边连接的是两个不同的连通块，把他们合并成一个连通块，直至生成树中有n个点

const int N = 2e5 + 3;
const int M = 2e6 + 3;
struct kruskal
{
    struct Edge
    {
        int u, v, w;
        bool operator<(const Edge &f) const
        {
            return w < f.w;
        }
    };
    Edge e[M];
    int tot,n;
    int f[N];
    int find(int x)
    {
        return f[x] == -1 ? x : (f[x] = find(f[x]));
    }
    bool merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v)
            return false;
        f[u]=v;
        return true;
    }
    void init(int nn)
    {
        n = nn;
        tot = 0;
        memset(f, -1, sizeof(int) * (n + 1));
    }
    void addEdge(int u, int v, int w)
    {
        e[tot++] = {u, v, w};
    }
    int run()
    {
        sort(e, e + tot);
        int cnt = 1,cost = 0;
        for (int i = 0;i<tot && cnt<n;++i)
        {
            if(!merge(e[i].u,e[i].v))
                continue;
            cost += e[i].w;
            ++cnt;
        }
        return (cnt==n?cost:-1);
    }
};