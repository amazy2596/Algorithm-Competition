#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
        if (it == b.end())
            it--;
        int y = *it - a[i];
        if (min(x, y) >= a[i - 1])
            a[i] = min(x, y);
        else if (max(x, y) >= a[i - 1])
            a[i] = max(x, y);
        else  
        {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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