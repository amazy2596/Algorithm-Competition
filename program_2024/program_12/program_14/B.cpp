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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    auto check = [&](int tar)
    {
        int x = tar - *a.begin(), y = a.back() - tar;
        return x > (y + 1);
    };
    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid;
    }
    int count = a.back() - *a.begin();
    cout << count << " " << l << "\n";
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