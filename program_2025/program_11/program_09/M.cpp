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
#define mp make_pair
#define db double

const int maxn=300010;
vector<pii> a[maxn];
int pt[maxn],v[maxn],co[maxn];
ll d[maxn],arv[maxn];
ll ans[maxn];

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    for(int i = 1;i<=k;i++) cin>>pt[i];

    for(int i=1;i<=m;++i){
        int x,y,z;
        cin>>x>>y>>z;

        z *= 2;
        a[x].push_back(mp(y,z)),a[y].push_back(mp(x,z));
    }
        priority_queue<pair<ll,int> > p;
        memset(d,0x3f,sizeof(ll)*(n+1));
        memset(v,0,sizeof(int)*(n+1));
        d[1]=0;
        p.push(mp(0,1));
        while(p.size()){
            int x=p.top().se;p.pop();
            if(v[x])continue;
            v[x]=1;
            for(pii y:a[x]){
                if(d[y.fi]>d[x]+y.se){
                    d[y.fi]=d[x]+y.se;
                    p.push(mp(-d[y.fi],y.fi));
                }
            }
        }
        ll tmt=0;
        priority_queue<pair<ll,pii> > pp;
        for(int i=1;i<=k;++i)tmt=max(tmt,d[pt[i]]),pp.push(mp(0,mp(pt[i],i)));
        memset(co,0,sizeof(int)*(n+1));
        memset(ans,0,sizeof(ll)*(k+1));
        while(pp.size()){
            int x=pp.top().se.fi,rt=pp.top().se.se;
            ll ti=-pp.top().fi;
            pp.pop();
    
            if(co[x]){
                if(co[x]!=rt&&d[x]+ti<=tmt){
                    ans[rt]=max(ans[rt],tmt-(ti+arv[x])/2);
                    ans[co[x]]=max(ans[co[x]],tmt-(ti+arv[x])/2);
                }
                continue;
            }
            co[x]=rt,arv[x]=ti;
            for(pii y:a[x]){
                pp.push(mp(-(ti+y.se),mp(y.fi,rt)));
            }
        }
        for(int i=1;i<=k;++i){
            if(ans[i]&1)printf("%lld.5 ",ans[i]/2);
            else printf("%lld.0 ",ans[i]/2);
        }
        puts("");
        for(int i=1;i<=n;++i)a[i].clear();


}
int main()
{
    Song4u
    
    int Test_number = 1;
    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}