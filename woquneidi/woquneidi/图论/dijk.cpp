#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 2e5+10;
bool st[N];
int main()
{
    int n,m;
    cin>>n>>m;
    int dist[N];
    memset(dist,0x3f,sizeof(dist));
    vector<vector<pii>> gra(n+1);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        gra[a].push_back({b,c});
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dist[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        pii tnod = q.top();
        q.pop();
        int nod = tnod.second;
        int d = tnod.first;
        if(st[nod]) continue;
        st[nod] = true;
        for(auto [next_nod,vlen] : gra[nod]){
            if(dist[next_nod] > dist[nod]+vlen){
                dist[next_nod] = dist[nod]+vlen;
                q.push({dist[next_nod],next_nod});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) cout<<"-1"<<endl;
    else cout<<dist[n]<<endl;
    return 0;
}
