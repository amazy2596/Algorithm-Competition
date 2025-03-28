#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    set<int> s;
    for (int i = 1; i < m; i++)
        s.insert(a[i] - a[i - 1]);

    vector<int> dist;
    for (int x : s)
        dist.push_back(x);

    vector<int> dp(t + 1, 0);

    dp[n] = 1;

    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (j + 2 * dist[i] > t)
                continue;
            if (dp[j] != 0)
                dp[j + 2 * dist[i]] |= dp[j];
        }
    }

    for (int i = t; i >= 0; i--)
    {
        if (dp[i])
        {
            cout << i << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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