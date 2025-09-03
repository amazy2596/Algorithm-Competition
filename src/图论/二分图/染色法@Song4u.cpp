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
const int M = 2*N;

int n,m;
struct edge{
    int v,ne;
}e[M];

int h[N];
int idx;
int col[N];

void add(int a,int b){
    e[idx++] = {b,h[a]};
    h[a] = idx;
}

bool dfs(int u,int c){
    col[u] = c;
    for(int i = h[u];i;i = e[i].ne){
        int v = e[i].v;
        if(!col[v]){
            if(dfs(v,3-c)) return true;
        }else{
            if(col[v] == c) return false;
        }
    }

    return false;
}

void solve(){
    cin>>n>>m;

    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        add(a,b);
        add(b,a);
    }

    bool suc = true;
    for(int i = 1;i<=n;i++){
        if(!col[i]){
            if(dfs(i,1)){
                suc = false;
                break;
            }
        }
    }

    cout<<(suc ? "YES" : "NO")<<'\n';
}

int main()
{
    Song4u
    
    int Test_number = 1;
    // cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

