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

ll qmi(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a);
        }

        b>>=1;
        a = a*a;
    }

    return res;
}
void solve(){
    ll n,y,m;
    cin>>n>>y>>m;

    vector<vector<int>> a(n+1);

    for(int i = 1;i<=n;i++){
        int sz;
        cin>>sz;

        for(int j = 1;j<=sz;j++){
            ll x;
            cin>>x;
            a[i].push_back(x);
        }

        reverse(a[i].begin(),a[i].end());
    }

    auto check = [&](ll mid) -> bool {
        ll s = mid;
        for(int i = 1;i<=n;i++){
            ll res = 0;
            for(int j = 0;j<a[i].size() ; j++){
                if(s < a[i][j]) return false;
                res += a[i][j] * qmi(s,j);
            }

            s = res;
        }

        return s == y;
    };

    ll l = 1;
    ll r = m;

    while(l<r){
        ll mid = (l+r) >> 1;

        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    cout<<l<<'\n';
}

int main()
{
    Song4u
    
    int Test_number = 1;
   cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}