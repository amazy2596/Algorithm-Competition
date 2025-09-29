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

const int N = 1005; // 假设最大顶点数

struct Floyd {
    int n;
    ll dis[N][N];

    void init(int m) {
        n = m;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dis[i][j] = (i==j) ? 0 : infll; 
            }
        }
    }

    void flo() {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
    }
};

void solve(){
    int n,m;
    cin>>n>>m;


    Floyd f;
    f.init(n);

    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        f.dis[u][v] = min(f.dis[u][v],w+0ll);
        f.dis[v][u] = min(f.dis[v][u],w+0ll);
    }


    f.flo();

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<f.dis[i][j] << ' ';
        }
        cout<<endl;
    }
}