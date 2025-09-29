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

const int N = 1e5+10;
int n;

vector<pii> gra[N];
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
    cin>>n;
}

int main()
{
    Song4u
    
    int Test_number = 1;
    // cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

