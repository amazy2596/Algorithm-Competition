#include <bits/stdc++.h>
using namespace std;

long long oddCount(long long n){
    long long e = (n+1)/2, o = n/2;
    return e*(e+1)/2 + o*(o+1)/2;
}

struct Fenwick {
    int n;
    vector<long long> fenw;
    Fenwick(int n):n(n),fenw(n+1,0){}
    void update(int i, long long val){
        for(; i<=n; i+=(i & -i)) fenw[i]+=val;
    }
    long long query(int i){
        long long s=0;
        for(; i>0; i-=(i & -i)) s+=fenw[i];
        return s;
    }
};

long long countEvenWithValue(int n, const vector<int>& a, int v){
    vector<long long> pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+(a[i]==v ? 1LL : 0LL);
    }
    vector<long long> d(n+1);
    for(int i=0;i<=n;i++){
        d[i]=2LL*pref[i]-i;
    }
    vector<long long> vals(d.begin(), d.end());
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto idxOf=[&](long long x){
        return int(lower_bound(vals.begin(), vals.end(), x)-vals.begin())+1;
    };
    Fenwick fenE(vals.size()), fenO(vals.size());
    long long res=0;
    for(int i=0;i<=n;i++){
        int pos=idxOf(d[i]);
        if(i%2==0){
            long long need=d[i]-2;
            int upPos=int(upper_bound(vals.begin(), vals.end(), need)-vals.begin());
            if(upPos>0) res+=fenE.query(upPos);
            fenE.update(pos,1);
        } else {
            long long need=d[i]-2;
            int upPos=int(upper_bound(vals.begin(), vals.end(), need)-vals.begin());
            if(upPos>0) res+=fenO.query(upPos);
            fenO.update(pos,1);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=oddCount(n);
        for(int v=1; v<=10; v++){
            ans+=countEvenWithValue(n,a,v);
        }
        cout<<ans<<"\n";
    }
    return 0;
}