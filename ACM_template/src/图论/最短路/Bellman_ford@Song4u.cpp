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

bool bellmanford(int st){ //bellmanford判负环
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