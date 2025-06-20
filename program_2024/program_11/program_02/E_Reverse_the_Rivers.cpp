#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(n, vector<int>(k));
    vector<vector<int>> b(k, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> a[i][j];
    for (int i = 0; i < k; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum |= a[j][i];
            a[j][i] = sum;
            b[i][j] = a[j][i];
        }
    }
    while (q--)
    {
        int m;
        cin >> m;
        vector<pair<int, int>> cnt;
        for (int l = 0; l < m; l++)
        {
            int r, c;
            char op;
            cin >> r >> op >> c;
            r--;
            if (op == '<')
            {
                int idx = lower_bound(b[r].begin(), b[r].end(), c) - b[r].begin();
                cnt.push_back({0, idx - 1});
            }
            else
            {
                int idx = upper_bound(b[r].begin(), b[r].end(), c) - b[r].begin();
                cnt.push_back({idx, n - 1});
            }
        }
        int l = 0, r = n - 1;
        for (int i = 0; i < cnt.size(); i++)
            l = max(l, cnt[i].first), r = min(r, cnt[i].second);
        if (l <= r)
            cout << l + 1 << "\n";
        else
            cout << -1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}