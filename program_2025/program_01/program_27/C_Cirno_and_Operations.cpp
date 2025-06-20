#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i];
    if (n == 1)
    {
        cout << ans << "\n";
        return;
    }
    
    ans = max({ans, *a.begin() - *a.rbegin(), *a.rbegin() - *a.begin()});
    while (a.size() > 1)
    {
        
        vector<int> b;
        for (int i = 1; i < a.size(); i++)
            b.emplace_back(a[i] - a[i - 1]);
        a = b;
        ans = max({ans, *b.begin() - *b.rbegin(), *b.rbegin() - *b.begin()});
    }

    cout << ans << "\n";
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