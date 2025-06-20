#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.begin(), b.end(), [&](pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    vector<int> ans(m, -1);
    int num = m;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i], [&](pair<int, int> p, int val)
        {
            return p.first < val;
        });
        int idx = it - b.begin();
        for (int j = idx; j < b.size(); j++)
            ans[b[j].second] = i + 1;
        for (int j = b.size() - 1; j >= idx; j--)
            b.pop_back();
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
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