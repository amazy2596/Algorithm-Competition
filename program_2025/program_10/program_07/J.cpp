#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long ,long long>;

void solve() {
    ll n,m,q;
    cin>>n>>m>>q;

    vector<bool> vis(n+1,false);
    vector<ll> sc(n+1,m);
    vector<ll> ac(m+1,0);

    map<pii,int> st;

    int bf = -1;

    while(q--){
        int op,id,x;
        cin>>op;

        if(op==1){
            cin>>x;

            if(bf == -1){
                vis[x] = true;
                bf = x;
            }else{
                vis[bf] = false;
                vis[x] = true;
                bf = x;
            }
            
        }else if(op == 2){
            cin>>id>>x;

            if(!vis[x]) continue;

            if(st[{id,x}] == 2 || st[{id,x}] == 1) continue;

            ac[id] += sc[x];
            sc[x] --;
            st[{id,x}] = 2;

        }else{
            cin>>id>>x;

            if(!vis[x]) continue;

            if(st[{id,x}] == 2 || st[{id,x}] == 1) continue;

            st[{id,x}] = 1;
        }
    }

    vector<pll> ans;

    for(int i = 1;i<=m;i++){
        ans.push_back({i,ac[i]});
    }

    auto cmp = [&](pll x, pll y) -> bool{
        auto [id1,sc1] = x;
        auto [id2,sc2] = y;

        if(x == y) return id1 < id2;
        
        return sc1>sc2;
    };

    sort(ans.begin(),ans.end(),cmp);

    for(auto [id,scc] : ans){
        cout<<id<<' '<<scc<<'\n';
    }

    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}