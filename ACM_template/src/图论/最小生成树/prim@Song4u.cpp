// //prim
// //任意点作为生成树的起点，每次选取和生成树中的点距离最小的非生成树中的点，加入生成树，直至生成树中有n个点

const int N = 5e3 + 3;
struct prim
{
    struct Edge//注意顺序，因为优先队列是小根堆，之后同理
    {
        int w,v;
        bool operator>(const Edge &f)const
        {
            return w > f.w;
        }
    };
    vector<Edge> e[N];
    priority_queue<Edge,vector<Edge>,greater<Edge> > q;
    int dis[N],vis[N];
    int n;
    void init(int nn)
    {
        n = nn;
        for(int i=1;i<=n;++i)
            e[i].clear();
        memset(dis,0x3f,sizeof(int)*(n+1));
        memset(vis,0,sizeof(int)*(n+1));
        while(!q.empty())
            q.pop();
    }
    void addEdge(int u, int v, int w)
    {
        e[u].push_back({w,v});
        e[v].push_back({w,u});
    }
    int run()
    {
        dis[1]=0;
        q.push({0,1});
        Edge u;
        int cnt=0,cost=0;
        while(!q.empty() && cnt<n)
        {
            u=q.top();
            q.pop();
            if(vis[u.v])
                continue;
            vis[u.v]=1;
            cost+=u.w;
            ++cnt;
            for(auto &[w,v]:e[u.v])
            {
                if(w>=dis[v])
                    continue;
                dis[v]=w;
                q.push({w,v});
            }
        }
        return (cnt==n?cost:-1);
    }
};