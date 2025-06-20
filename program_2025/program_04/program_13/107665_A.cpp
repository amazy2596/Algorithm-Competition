#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        b.push_back(a[i].first);
        b.push_back(a[i].second);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    vector<int> c(b.size() + 2), pre(b.size() + 2);
    for (auto [l, r] : a)
    {
        auto L = lower_bound(b.begin(), b.end(), l) - b.begin(); 
        auto R = upper_bound(b.begin(), b.end(), r) - b.begin();

        c[L] += l + r;
        c[R] -= l + r;
    }
    
    for (int i = 0; i < b.size(); i++)
    {
        if (i == 0)
            pre[i] = c[i];
        else 
            pre[i] = c[i] + pre[i - 1];
    }

    int mx = -1e18, idx = -1e18;
    for (int i = 0; i < b.size(); i++)
    {
        if (pre[i] > mx)
        {
            mx = pre[i];
            idx = b[i];
        }
    }

    cout << idx << "\n";
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