#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        a[i].push_back(0);
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            a[i].back() += a[i][j];
        }
    }
    
    sort(a.begin(), a.end(), [&](vector<int> &x, vector<int> &y)
    {
        return x.back() > y.back();
    });

    vector<int> v(1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v.emplace_back(a[i][j]);
    
    vector<int> pre(v.size()), ppre(v.size());
    for (int i = 1; i < v.size(); i++)
    {
        pre[i] = pre[i - 1] + v[i];
        ppre[i] = ppre[i - 1] + pre[i];
    }

    cout << ppre.back() << "\n";
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