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

const int N = 110;
int n,m;
int ans = 0;

string a[N];
vector<int> flo[4];

bool sel[10];

int num[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};


void solve(){

    cin>>n>>m;

    for(int i = 1;i<=n;i++) cin>>a[i];

    for(int i = 1;i<=m;i++) flo[i].clear();


    for(int j = 1;j<=m;j++){
        for(int i = 1;i<=n;i++){
            flo[j].push_back(a[i][j-1] - '0');
        }
    }

    for(int i = 1;i<=m;i++){
        sort(flo[i].begin(),flo[i].end());
        flo[i].erase(unique(flo[i].begin(),flo[i].end()),flo[i].end());
    }

    for(int i = 1;i<=m;i++){

        if(flo[i].size() == 1)continue;

        int res = inf;

        for(int j = 0;j<=127;j++){
            bool suc = true;

            memset(sel,false,sizeof(sel));
            
            for(int k = 0;k<7;k++){
                if((j>>k) & 1) sel[k] = true;
            }

            map<string,int> cnt;

            for(auto x : flo[i]){
                string res;

                for(int k = 0;k<=6;k++){
                    if(sel[k]) res += num[x][k] + '0';
                }

                cnt[res] ++;

                if(cnt[res] >= 2) {
                    suc = false;
                    break;
                }
            }

            if(!suc) continue;
            else{
                int mid = 0;

                for(int k = 0;k<7;k++){
                    if(sel[k]) mid++;
                }

                // for(int k = 0;k<7;k++){
                //     if(sel[k])  cout<<1;
                //     else cout<<0;
                // }

                // cout<<'\n';
                res = min(mid,res);
                // cout<<res<<"Q\n";
            }
            
        }

        ans+=res;

        // cout<<ans<<"P\n";
    }


    cout<<ans<<'\n';
    ans = 0;



}

int main()
{
    Song4u
    
    int Test_number = 1;
    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}