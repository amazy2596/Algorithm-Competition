#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool ff = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ff = 1;
    }
    if (ff)
    {
        cout << -1 << "\n";
        return;
    }
    
    int mx = *max_element(a.begin(), a.end()) + 1;
    for (int i = mx; i <= 1e10; i++)
    {
        bool f = 0;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << i << "\n";
            return;
        }
    }
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