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
#define fi first
#define se second
#define inf 0x3f3f3f3f 
#define infll 0x3f3f3f3f3f3f3f3fLL

// tarjan求vDCC
const int N = 2e6+10;
int n,m;
vector<int> e[N];//加边数组
vector<int> ne[N];//new_e在缩完点之后要建的新图
int dfn[N];
int low[N];
int tot;
stack<int> stk;
vector<int> dcc[N];//点双连通分量
int cnt;//记录dcc
int cut[N];//点x是不是割点
int root;
int num;//给每个割点一个新编号
int id[N];//给每个割点新编号用

void tarjan(int x){
    dfn[x] = low[x] = ++ tot;
    stk.push(x);
    if(!e[x].size()){//若x没有边，就是一个孤立点
        dcc[++cnt].push_back(x);
        return ;
    }

    int child = 0;
    for(int y : e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
            if(low[y] >= dfn[x]){
                child ++;
                if(x!=root || child > 1){
                    cut[x] = true;
                }

                cnt++;

                while(1){
                    int z = stk.top();
                    stk.pop();
                    dcc[cnt].push_back(z);
                    if(z==y) break;
                }

                dcc[cnt].push_back(x);
            }
        }else{
            low[x] = min(low[x],dfn[y]);
        }
    }
}

void solve(){
    cin>>n>>m;

    while(m--){
        int a,b;
        cin>>a>>b;
        if(a==b)  continue;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for(root = 1;root<=n;root ++){
        if(!dfn[root]) tarjan(root);
    }

    //给每个割点一个新编号，因为缩点之后要把割点裂点
    num = cnt;
    for(int i = 1;i<=n;i++){
        if(cut[i]) id[i] = ++num;
    }

    //建新图，从每个vdcc向对应割点连边
    for(int i = 1;i<=cnt;i++){
        for(int j = 0;j<dcc[i].size();j++){
            int x = dcc[i][j];
            if(cut[x]){
                ne[i].push_back(id[x]);
                ne[id[x]].push_back(i);
            }
        }
    }

    cout<<cnt<<'\n';

    for(int i = 1;i<=cnt;i++){
        cout<<dcc[i].size()<<' ';
        for(auto x : dcc[i]){
            cout<<x<<' ';
        }

        cout<<'\n';
    }
}