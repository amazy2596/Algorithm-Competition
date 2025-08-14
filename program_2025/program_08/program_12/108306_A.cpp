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

const int N = 2e5+10;
const int MAXH = 32;

ll dp[N][MAXH + 1];
int n;
int l[N];
int r[N];
int height[N];
int siz[N];
ll tmp[MAXH + 1];

ll ans = inf;

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= MAXH; j++) {
            dp[i][j] = inf;
        }
        height[i] = 0;
        siz[i] = 1; 
    }
    ans = inf;
}

void pre() {
    tmp[0] = 0;
    tmp[1] = 1;
    for (int i = 2; i <= MAXH; i++) {
        tmp[i] = tmp[i - 2] + tmp[i - 1] + 1;
    }
}

void dfs(int u) {
    if (u == 0) 
    {
        for (int i = 0; i < MAXH; i++)
            dp[u][i] = tmp[i];
        return;
    }

    dfs(l[u]);
    dfs(r[u]);

    siz[u] = 1;
    if (l[u] != 0) siz[u] += siz[l[u]];
    if (r[u] != 0) siz[u] += siz[r[u]];
    height[u] = 1 + max(l[u] ? height[l[u]] : 0, r[u] ? height[r[u]] : 0);

    vector<int> costl(MAXH + 1, inf);
    vector<int> costr(MAXH + 1, inf);

    for (int i = 0; i <= MAXH; i++) {
        if (dp[l[u]][i] != inf)
            costl[i] = dp[l[u]][i];
        if (dp[r[u]][i] != inf)
            costr[i] = dp[r[u]][i];
    }

    for (int i = 0; i <= MAXH; i++) {
        if (i == 0) {
            dp[u][0] = 1 + costl[0] + costr[0];
        } else if (i == 1) {
            dp[u][i] = costl[0] + costr[0];
        } else {
            ll t1 = (i - 1 <= MAXH) ? costl[i - 1] + costr[i - 1] : inf;
            ll t2 = (i - 2 >= 0 && i - 1 <= MAXH) ? costl[i - 1] + costr[i - 2] : inf;
            ll t3 = (i - 2 >= 0 && i - 1 <= MAXH) ? costl[i - 2] + costr[i - 1] : inf;
            dp[u][i] = min({dp[u][i], t1, t2, t3});
        }
    }
}

void solve() {
    cin >> n;
    init();

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    dfs(1);

    ans = inf;
    for (int i = 1; i <= MAXH; i++) {
        ans = min(ans, dp[1][i]);
    }
    cout << min(ans, (ll)n) << '\n';
}

int main() {
    Song4u
    pre();
    int Test_number = 1;
    cin >> Test_number;
    while (Test_number--) solve(); 
    return 0;
}