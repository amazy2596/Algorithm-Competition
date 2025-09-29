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

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n), siz(n, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};



void solve(){
    int n;
    cin>>n;

    DSU dsu(n+1);

    vector<pii> a(n+1);

    for(int i = 1;i<=n;i++) cin>>a[i].fi>>a[i].se;

    int ans = 1;

    for(int i = 1;i<=n;i++){
       auto [l,r] = a[i];
       l--;
       if(dsu.find(l) == dsu.find(r)){
        ans = 0;
        break;
       }else{
        dsu.merge(l,r);
       }
    }

    cout<<ans<<'\n';
}

int main()
{
    Song4u
    
    int Test_number = 1;
    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

