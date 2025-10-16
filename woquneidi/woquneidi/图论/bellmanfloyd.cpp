#include <bits/stdc++.h>
using namespace std;
const int M = 1e4+1;
const int N = 550;
int n,m,k;
struct edge{
    int a,b,w;
}edges[M];
int dist[N];
int backup[N];
int bf(){
    
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    for(int i = 1;i<=k;i++){
        memcpy(backup,dist,sizeof(dist));
        for(int j = 1;j<=m;j++){
            int a = edges[j].a;
            int b = edges[j].b;
            int w = edges[j].w;
            dist[b] = min(dist[b],backup[a]+w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -0x3f3f3f3f;
    else return dist[n];
}
int main()
{
    cin>>n>>m>>k;

    for(int i = 1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = {a,b,w};
    }
    
    int t = bf();
    
    if(t==-0x3f3f3f3f) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
