#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    int ans = accumulate(a.begin(), a.end(), 0ll);

    vector<int> f(1 << m);
    f[0] = (1 << 30) - 1;
    for (int s = 1; s < (1 << m); s++)
    {
        int u = __builtin_ctz(s);
        f[s] = f[s ^ (1 << u)] & b[u];
    }

    vector<int> cnt;
    for (int i = 0; i < n; i++)
    {
        vector<int> g(m + 1, INT64_MAX);
        for (int s = 0; s < (1 << m); s++)
        {
            int c = __builtin_popcount(s);
            g[c] = min(g[c], a[i] & f[s]);
        }

        for (int j = 1; j <= m; j++)
            cnt.push_back(g[j - 1] - g[j]);
    }

    sort(cnt.begin(), cnt.end());
    while (cnt.size() && k)
    {
        ans -= cnt.back();
        cnt.pop_back();
        k--;
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}