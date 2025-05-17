#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // a[i] - a[j] == b[j] - b[i];
    // a[i] + b[i] == a[j] + b[j];

    auto check = [&](int x)
    {
        int res = 0;
        for (int i = 1; i < n; i++) 
            res += x - a[i];
        return res;
    };

    int l = 0, r = 1e12;
    while (l < r)
    {
        int mid = l + r >> 1;
        int res = check(mid);
        if (res >= a[0])
            r = mid;
        else 
            l = mid + 1;
    }

    for (int i = 0; i < n; i++)
        cout << l - a[i] << " ";
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