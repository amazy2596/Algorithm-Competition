#include <bits/stdc++.h>
#define uint uint64_t
#define LL long long
using namespace std;

void solve(){
    LL n, q, x, y, cnt = 0; cin >> n >> q;
    vector<LL> a(n + 10, 0), v(n + 10, 0), pv(n + 10, LLONG_MIN), f(n + 10, 0), dp(n + 10, LLONG_MIN), ds(n + 10, LLONG_MIN), vp(n + 10, 0), op(n + 10, 0);
    vector<vector<int>> G(n + 10);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 2; i <= n; ++i){
        cin >> x;
        G[x].push_back(i);
    }
    auto dfs = [&](auto &&self, int np, int p) -> void {
        vp[np] = ++cnt; // x进入
        if(~p) v[np] = v[p] + a[np]; else v[np] = a[np]; // 继承父节点往下
        f[np] = a[np];
        for(auto to : G[np]){
            self(self, to, np);
            f[np] = max(f[np], f[to] + a[np]); // 类似树形dp的东西
        }
        op[np] = cnt; // x离开
    };
    dfs(dfs, 1, -1);
    for(int i = 1; i <= n; ++i) pv[vp[i]] = v[i]; // 同步dfn序
    dp[1] = pv[1], ds[n] = pv[n]; // 下面都是前后缀最大值
    for(int i = 2; i <= n; ++i) dp[i] = max(dp[i - 1], pv[i]);
    for(int i = n - 1; i >= 1; --i) ds[i] = max(ds[i + 1], pv[i]);
    while(q--){
        cin >> x >> y;
        LL left = LLONG_MIN;
        if(vp[x] > 1) left = max(left, dp[vp[x] - 1]);
        if(op[x] < n) left = max(left, ds[op[x] + 1]);
        cout << max(left, v[y] + f[x]) << endl;
    }
    return;
}


signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}