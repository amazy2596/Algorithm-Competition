// //Boruvka
// //每次处理一个连通块时，它向其他连通块伸出一条最小边权的边，启发式合并两个连通块的点（这里总共花费 nlogn）
// //如果能连成，就加上这个边的贡献，直至连通块数为1。

int a[N];//点权，1-index
namespace boruvka
{
    int n,f[N];
    vector<int> connectBlock[N];//连通块 i 包含的点权(或点)
    queue<int> q;//待处理的点（连通块）
    int find(int x)
    {
        return f[x] ==0 ? x : (f[x] = find(f[x]));
    }
    bool merge(int u,int v)//启发式合并维护连通块包含的点
    {
        u=find(u),v=find(v);
        if(u==v)
            return false;
        if(connectBlock[u].size()<connectBlock[v].size())
            swap(u,v);
        for(int &x:connectBlock[v])
            connectBlock[u].push_back(x);
        connectBlock[v].clear();
        f[v]=u;
        return true;
    }
    void init(int nn)
    {
        n = nn;
        for(int i=1;i<=n;++i)
            q.push(i);
        for(int i=1;i<=n;++i)
            connectBlock[i].push_back(a[i]);
    }
    array<int,2> cal(int x)
    {
        //根据题目计算最小边权和对应的点
        return {0,0};
    }
    ll run()
    {
        array<int,2> res;//边权，连接的另一个点（连通块），顺序不能错
        int u,com=n;//连通块数
        ll ans=0;
        while(com>1)
        {
            while(connectBlock[q.front()].empty())
                q.pop();
            u=q.front();
            q.pop();
            res={INF,0};
            for(int &v:connectBlock[u])
                res=min(res,cal(v));
            if(!merge(u,res[1]))
                continue;
            q.push(u);
            ans+=res[0];
            --com;
        }
        return ans;
    }
};