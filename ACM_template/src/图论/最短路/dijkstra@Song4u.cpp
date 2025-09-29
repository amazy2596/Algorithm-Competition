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
vector<pii> gra[N];
int n;
vector<ll> dijkstra(int st){//不能处理边权为负的情况
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