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


const int N = 2e4+10;

vector<int> gra[N];
int dfn[N];//时间戳，节点x第一次被访问的顺序
int low[N];//追溯值，从节点x出发，所能访问到的最早时间戳
int tot;//时间戳编号
int cut[N];//记录当前点是不是割点
int root;//哪个点是根


void tarjan(int x){
    //入x时，盖戳
    dfn[x] = low[x] = ++tot;
    int child = 0;

    for(int y : gra[x]){
        if(!dfn[y]){//若y尚未访问
            tarjan(y);
            //回x时，更新low，判割点
            low[x] = min(low[x],low[y]);
            if(low[y] >= dfn[x]){
                child ++;//子树的数量
                if(x != root || child > 1){
                    cut[x] = 1;
                }
            }
        }else{//若y已经找到
            low[x] = min(low[x],dfn[y]);
        }

    }
}



void solve(){
    cin>>n>>m;
    
    while(m--){
        int u,v;
        cin>>u>>v;

        gra[u].push_back(v);
        gra[v].push_back(u);
    }


    for(int i = 1;i<=n;i++){
        if(!dfn[i]){
            root  = i;
            tarjan(i);
        }
    }

    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(cut[i]) ans++;
    }

    cout<<ans<<'\n';

    for(int i = 1;i<=n;i++) {
        if(cut[i]) cout<<i<<' ';
    }
}

int main()
{
    Song4u
    
    int Test_number = 1;
//    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}