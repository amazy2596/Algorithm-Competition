#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
vector<pair<int, int>> p(N);
vector<int> g[N];
vector<int> dp(N);
vector<bool> vis(N);

void solve()
{
    int n, m, k = 0, mx = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        unordered_set<int> s;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            if (x < N)
                s.insert(x);
        }
        int mex = 0;
        while (s.count(mex))
        {
            mex++;
        }
        int to_mex = mex + 1;
        while (s.count(to_mex))
        {
            to_mex++;
        }
        p[i] = make_pair(mex, to_mex);
        mx = max(mx, mex);
        k = max(k, to_mex);
    }

    for (int i = 0; i <= k; i++)
        vector<int>().swap(g[i]);
    
    for (int i = 0; i < n; i++)
        g[p[i].first].push_back(p[i].second);

    for (int mex = k; mex >= 0; mex--)
    {
        dp[mex] = mex;
        for (auto to_mex : g[mex])
            dp[mex] = max(dp[mex], dp[to_mex]);

        if ((int)g[mex].size() >= 2) 
            mx = max(mx, dp[mex]);
    }

    for (int i = 0; i <= min(m, k); i++)
        ans += max(dp[i], mx);

    if (k < m)
        ans += (k + m + 1) * (m - k) / 2;

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}