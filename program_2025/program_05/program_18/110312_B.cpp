#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;
using i64 = long long;
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m + 1), b(m + 1), t(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }
    vector<i64> dp(n + 1, -1e18);
    dp[1] = 0, t[0] = 1;
    i64 ans = -1e18;
    for(int i = 1; i <= m; i++) {
        auto dp2 = dp;
        deque<int> dq;
        i64 dx = min(d * 1ll * (t[i] - t[i - 1]), (i64)n);
        // int qr = dx + 1, ql = 1;
        int qidx = 0;
        for(int j = 1; j <= n; j++) {
            i64 l = max(1ll, j - dx), r = min((i64)n, j + dx);
            
            while(!dq.empty() && dq.front() < l) dq.pop_front(); 
            
            
            for(int z = qidx + 1; z <= r; z++) {
                while(!dq.empty() && dp[dq.back()] <= dp[z]) dq.pop_back();
                dq.push_back(z);
            }
            qidx = r;
            dp2[j] = dp[dq.front()] + b[i] * 1ll * abs(j - a[i]);
        }
        dp = dp2;
        if(i == m) {
            for(int j = 1; j <= n; j++) ans = max(ans, dp[j]);
        }
    }

    dp.assign(n + 1, -1e18);
    dp[n] = 0, t[0] = 1;

    for(int i = 1; i <= m; i++) {
        auto dp2 = dp;
        deque<int> que;
        i64 dx = min(d * 1ll * (t[i] - t[i - 1]), (i64)n);
        // int qr = dx + 1, ql = 1;
        int qidx = 0;
        for(int j = 1; j <= n; j++) {
            i64 l = max(1ll, j - dx), r = min((i64)n, j + dx);
            
             while(!que.empty() && que.front() < l) que.pop_front(); 
            
            
            for(int z = qidx + 1; z <= r; z++) {
                while(!que.empty() && dp[que.back()] <= dp[z]) que.pop_back();
                que.push_back(z);
            }
            qidx = r;
            dp2[j] = dp[que.front()] + b[i] * 1ll * abs(j - a[i]);
        }
        dp = dp2;
        if(i == m) {
            for(int j = 1; j <= n; j++) ans = max(ans, dp[j]);
        }
    }


    cout << ans;

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