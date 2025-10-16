#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
const int M = N*2;
int n,m;
int p[N];
struct edge{
    int a,b,w;
    bool operator < (const edge &W) const {
        return w<W.w;
    }
}edges[M];
int find(int x){
   if(p[x]!=x) p[x] = find(p[x]);
   return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i] = {a,b,c};
    }
    sort(edges+1,edges+1+m);
    int res = 0;
    int cnt = 0;
    for(int i = 1;i<=n;i++) p[i] = i;
    for(int i = 1;i<=m;i++){
        int a = edges[i].a;
        int b = edges[i].b;
        int c = edges[i].w;
        a = find(a);
        b = find(b);
        if(a==b){
            ;
        }else{
            p[a] = p[b];
            cnt++;
            res+=c;
        }
    }
    if(cnt!=n-1) cout<<"impossible";
    else cout<<res<<endl;
    return 0;
}
