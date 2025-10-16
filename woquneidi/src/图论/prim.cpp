#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
const int M = 1e5+10;
int mp[N][N];
int dist[N];
bool st[N];
int n,m;

int prim(){
      memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], mp[t][j]);
    }

    return res;
}
int main()
{
    cin>>n>>m;
    memset(mp,0x3f,sizeof(mp));
    memset(dist,0x3f,sizeof(dist));
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u][v] = min(mp[u][v],w);
        mp[v][u] = min(mp[v][u],w);
    }
    int t = prim();
    if(t==0x3f3f3f3f) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
