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

int n,m;


const int N = 1e4+10;

vector<int> gra[N];
int dfn[N];//时间戳，节点x第一次被访问的顺序
int low[N];//追溯值，从节点x出发，所能访问到的最早时间戳
int tot;//时间戳编号
int stk[N];//栈
int instk[N];//在不在栈中
int top;
int scc[N];//点x属于哪一个scc
int siz[N];//scc大小
int cnt;//scc编号
int din[N],dout[N];//统计scc的入度和出度

void tarjan(int x){
    //入x时，盖戳，入栈
    dfn[x] = low[x] = ++ tot;
    stk[++top] =  x;
    instk[x] = 1;

    for(int y : gra[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
        }else if(instk[y]){
            low[x] = min(low[x],dfn[y]);
        }
    }

    if(dfn[x] == low[x]){
        int y;
        ++cnt;
        do{
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        }while(y!=x);
    }
}



void solve(){
    cin>>n>>m;

    for(int i = 1;i<=m;i++){
        int u,v;
        cin>>u>>v;

        gra[u].push_back(v);
    }
    
    for(int i = 1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    if(cnt==1){
        cout<<n;
        return ;
    }
    for(int i = 1;i<=n;i++){
        for(int j : gra[i]){
            if(scc[i] != scc[j]){
                din[scc[j]] ++;
                dout[scc[i]] ++;
            }
        }
    }

    int ans = 0;
    int z = 0;
    for(int i = 1;i<=cnt;i++){
        if(dout[i] == 0){
            ans+=siz[i];
            z++;

        }
    }

    cout<<(z > 1 ? 0 : ans);
}

int main()
{
    Song4u
    
    int Test_number = 1;
//    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}
