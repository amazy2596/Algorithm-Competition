//O.o?  bug again??????
#include <bits/stdc++.h>
using namespace std;

#define Song4u ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define tri tuple<int,int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f 
#define infll 0x3f3f3f3f3f3f3f3fLL

const int N=210,M=10010;
int n,m,a,b;

struct edge{int u,v;};
vector<edge>e;//边集
vector<int>h[N];//出边
int dfn[N],low[N],tot;

struct bridge{
  int x,y;
  bool operator<(const bridge &t)const{
    if(x==t.x)return y<t.y;
    return x<t.x;
  }
}bri[M];
int cnt;//给割边计数

void add(int a,int b){
  e.push_back({a,b});
  h[a].push_back(e.size()-1);
}
void tarjan(int x,int in_edge){
  dfn[x]=low[x]=++tot;
  for(int i=0;i<h[x].size();i++){
    int j=h[x][i], y=e[j].v;//j是当前出边在边集中的位置，y是当前边的下一个点
    if(!dfn[y]){ //若y尚未访问
      tarjan(y,j);
      low[x]=min(low[x],low[y]);
      if(low[y]>dfn[x]){
        bri[cnt++]={x,y};
      }
    }
    else if(j!=(in_edge^1)) //不是反边
      low[x]=min(low[x],dfn[y]);
  }
}


void solve(){
    cin>>n>>m;

    while(m--){
        cin>>a>>b;

        add(a,b);
        add(b,a);
    }

    for(int i = 1;i<=n;i++){
        if(!dfn[i]) tarjan(i,0);
    }

    sort(bri,bri+cnt);

    for(int i = 0;i<cnt;i++){
        cout<<bri[i].x<<' '<<bri[i].y<<'\n';
    }
}

int main()
{
    Song4u
    
    int Test_number = 1;
    // cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

