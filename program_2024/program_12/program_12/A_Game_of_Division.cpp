#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool f = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        bool ff = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (abs(a[i] - a[j]) % k == 0)
                ff = 0;
        }
        if (ff)
        {
            f = 1;
            idx = i + 1;
            break;
        }
    }
    if (f)
    {
        cout << "YES\n";
        cout << idx << "\n";
    }
    else
        cout << "NO\n";
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