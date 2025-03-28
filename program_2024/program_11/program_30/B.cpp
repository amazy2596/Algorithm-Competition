#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    deque<int> d;
    int ans = min(1 + k, m), cost = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (!d.empty() && a[i] - d.back() - 1 + cost > k)
        {
            int front = d.front();
            d.pop_front();
            cost -= (!d.empty() ? d.front() - front - 1 : 0);
        }
        if (!d.empty())
            cost += a[i] - d.back() - 1;
        d.push_back(a[i]);

        int l = d.front(), r = d.back();
        ans = max(ans, r - l + 1 + min({l - 1 + m - r, k - cost}));
    }
    cout << ans << "\n";
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