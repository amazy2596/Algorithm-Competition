#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q), b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < q; i++)
        cin >> a[i];
    sort(b.begin(), b.end());
    for (auto x : a)
    {
        if (m == 1)
        {
            if (x < b[0])
                cout << b[0] - 1 << "\n";
            else 
                cout << n - b[0] << "\n";
        }
        else 
        {
            auto it = lower_bound(b.begin(), b.end(), x);
            if (x < b[0])
                cout << b[0] - 1 << "\n";
            else if (x > b.back())
                cout << n - b.back() << "\n";
            else
            {
                int r = *it, l = *(--it);
                cout << (r - l) / 2 << "\n";
            }
        }
    }
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