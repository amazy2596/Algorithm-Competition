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

    auto check = [&](int x)
    {
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < x)
                mp[a[i]]++;
            if (mp.size() == x)
            {
                mp.clear();
                res++;
            }
        }

        return res;
    };

    int l = 0, r = 2e5;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        int res = check(mid);
        if (res >= k)
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << "\n";
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