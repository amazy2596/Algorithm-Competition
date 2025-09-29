//O.o?  bug again??????
#include <bits/stdc++.h>
using namespace std;

#define Song4u ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define T double
#define ptt pair<double,double>
#define tri tuple<int,int,int>
#define inf 0x3f3f3f3f 
#define infll 0x3f3f3f3f3f3f3f3fLL

//eDCC：无向图中极大的不包含割边的连通块被称为“边双连通分量”
//e.g.https://www.luogu.com.cn/problem/P2860
const int M = 1e4+10;
const int N = 5e3+10;

int n,m;
struct edge{
    int v,ne;
};
edge e[M];
int h[N],idx = 1;
int dfn[N];
int low[N];
int tot;
stack<int> stk;
int dcc[N],cnt;
int bri[M];
int d[N];

void add(int x,int y){
    e[++idx].v = y;
    e[idx].ne = h[x];
    h[x] = idx;
}

void tarjan(int x,int in_edg){
    dfn[x] = low[x] = ++tot;
    stk.push(x);

    for(int i = h[x];i;i = e[i].ne){
        int y = e[i].v;

        if(!dfn[y]){
            tarjan(y,i);
            low[x] = min(low[x],low[y]);
            if(low[y] > dfn[x]){
                bri[i] = bri[i^1] = true;
            }
        }else if(i!=(in_edg^1)){
            low[x] = min(low[x],dfn[y]);
        }
    }

    if(dfn[x] == low[x]){
        ++cnt;

        while(1){
            int y = stk.top();
            stk.pop();
            dcc[y] = cnt;
            if(y==x) break;
        }
    }
}
 
void solve(){
    cin>>n>>m;

    while(m--){
        int x,y;
        cin>>x>>y;

        add(x,y);
        add(y,x);
    }

    tarjan(1,0);

    for(int i = 2;i<=idx;i++){
        if(bri[i]){
            d[dcc[e[i].v]] ++;
        }
    }

    int ans = 0;

    for(int i = 1;i<=cnt;i++){
        if(d[i] == 1) ans++;
    }
    
    // cout<<ans<<'\n';
    ans = (ans+1) / 2;

    cout<<ans;

}