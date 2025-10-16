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


// https://www.luogu.com.cn/problem/P2863
const int N = 1e4+10;

int n,m;
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
    while(m--){
        int a,b;
        cin>>a>>b;

        gra[a].push_back(b);
    }

    for(int i = 1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }

    int ans = 0;
    for(int i = 1;i<=cnt;i++){
        if(siz[i] > 1) ans++;
    }
    cout<<ans;
}

int main()
{
    Song4u
    
    int Test_number = 1;
    // cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

