#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    bool f = 0;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());

        for (int j = 1; j < m; j++)
        {
            if (a[i][j] - a[i][j - 1] != n)
                f = 1;
        }
    }   

    if (f)
    {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j)
    {
        return a[i][0] < a[j][0]; 
    });

    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " \n"[i == n - 1];
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