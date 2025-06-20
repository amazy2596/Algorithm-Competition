// #include <bits/stdc++.h>
// #define uint uint64_t
// #define int long long
// using namespace std;

// void solve()
// {
//     int n, x, y;
//     cin >> n >> x >> y;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
    
//     sort(a.begin() + 1, a.end());

//     vector<int> dp(n + 1, INT32_MAX);
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int pre = i - y;
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (a[j] >= a[i] - x)
//                 dp[i] = min(dp[i], dp[j]);
//             if (a[j] >= a[i] - y)
//                 dp[i] = min(dp[i], dp[j] + 1);
//         }
//     }

//     cout << (dp[n] == INT32_MAX ? -1 : dp[n]) << "\n";
// }

// signed main()
// {
//     // ios::sync_with_stdio(false);
//     // cout.tie(nullptr);
//     // cin.tie(nullptr);
//     int T = 1;
//     // cin >> T;
//     while (T--)
//         solve();
//     return 0;
// }

//O.o?  bug again??????
#include <bits/stdc++.h>
using namespace std;

#define Song4u ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define tri tuple<int,int,int>
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    
    vector<int> a(n+1);
    
    int ed = -1;
    
    for(int i = 1;i<=n;i++) cin>>a[i],ed = max(ed,a[i]);
    
    map<int,bool> vis;
    
    vector<vector<pii>> gra(n+1);
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(abs(a[i]-a[j])<=x){
                gra[i].push_back({j,0});
                gra[j].push_back({i,0});
            }else if(abs(a[i]-a[j])>x&&abs(a[i]-a[j])<=y){
                gra[i].push_back({j,1});
                gra[j].push_back({i,1});
            }
        }
    }
    
    for(int i = 1;i<=n;i++){
        if(a[i]<=x) gra[0].push_back({i,0});
        else if(a[i]>x&&a[i]<=y) gra[0].push_back({i,1});
    }
    
    
    queue<pii> q;//第一项是当前下标，第二个是使用技能的次数
    
    q.push({0,0});
    
    while(!q.empty()){
        auto [idx,cnt] = q.front();
        q.pop();
        
        if(a[idx]==ed){
            cout<<cnt;
            return ;
        }
        
        if(vis[idx]) continue;
        vis[idx] = true;
        
        for(auto [nidx,ok] : gra[idx]){
            if(!vis[nidx]){
                if(ok) q.push({nidx,cnt+1});
                else q.push({nidx,cnt});
            }else continue;
            
        }
    }
    
    cout<<"-1";
    
}

int main()
{
    Song4u
    
    int Test_number = 1;
//    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}
