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

vector<vector<vector<ll>>> floyd(vector<vector<vector<ll>>> dist,int n){
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                dist[k][x][y] = min(dist[k - 1][x][y], dist[k - 1][x][k] + dist[k - 1][k][y]);
            }
        }
    }

    return dist;
}

vector<ll> dijkstra(vector<vector<pll>> gra,int n,int st){//不能处理边权为负的情况
    ll ans = 0;
    priority_queue<pll,vector<pll>,greater<pll>> q;

    vector<ll> dist(n+1,infll);
    vector<bool> vis(n+1,false);


    q.push({0,st});
    dist[st] = 0;

    while(!q.empty()){
        auto [len,tnod] = q.top();
        q.pop();

        if(vis[tnod]) continue;
        vis[tnod] = true;

        for(auto [nnod,w] : gra[tnod]){
            if(dist[nnod] > dist[tnod] + w){
                dist[nnod] = dist[tnod] + w;
                q.push({dist[nnod],nnod});
            }
        }
    }

    return dist;
}

bool bellmanford(vector<vector<pll>> gra,int n,int st){ //bellmanford判负环
    vector<ll> dist(n+1,infll);
    dist[st] = 0;

    bool suc = false;

    for(int i = 1;i<=n;i++){
        suc = false;

        for(int u = 1;u<=n;u++){
            for(auto [v,len] : gra[u]){
                if(dist[u]==infll) continue;
                if(dist[v] > dist[u] + len){
                    dist[v] = dist[u] + len;
                    suc = true;

                }
            }
        }

        if(!suc) break;

    }

    return suc;
    
}

bool spfa(vector<vector<pll>> gra,int n,int st){//判负环
    vector<ll> dist(n+1,infll);
    vector<bool> vis(n+1,false);
    vector<int> cnt(n+1,0);//记录到达该点最短路径的经过边数
                           //若这个数大于n则一定经过负环
                           //因为最多只可能经过n-1条边

    dist[st] = 0;
    vis[st] = true;

    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int tnod = q.front();
        q.pop();
        vis[tnod] = false;
        for(auto [nnod,w] : gra[tnod]){
            if(dist[nnod] > dist[tnod] + w){
                dist[nnod] = dist[tnod] + w;
                cnt[tnod]  = cnt[nnod] + 1;

                if(cnt[nnod] >= n) return false;
                if(!vis[nnod]) q.push(nnod);
                vis[nnod] = true;
            }
        }
    }

    return true;
}


void solve(){
    
}

int main()
{
    Song4u
    
    int Test_number = 1;
//    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

