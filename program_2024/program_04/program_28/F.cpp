#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        
        int ct=0,ctt=0;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            if(x==y){
                ct++;
            }
            if(y==1) ctt++;
        }
        if(ct==m){
            for(int i=1;i<n;i++){
                cout<<i<<' ';
            }
            cout<<n<<'\n';
        }
        else if(ctt==m){
            for(int i=n;i>1;i--){
                cout<<i<<' ';
            }
            cout<<1<<'\n';
        }
        else cout<<"-1"<<'\n';
    }
    return 0;
}