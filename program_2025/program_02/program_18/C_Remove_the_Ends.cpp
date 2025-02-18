#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            pre[i] = pre[last] + a[i], last = i;
    }
    
    vector<int> idx;
    last = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < 0)
            suf[i] = suf[last] - a[i], last = i, idx.push_back(i);
    }
    reverse(idx.begin(), idx.end());

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            auto it = lower_bound(idx.begin(), idx.end(), i);
            if (it != idx.end())
                ans = max(ans, pre[i] + suf[*it]);
        }

        ans = max({ans, pre[i], suf[i]});
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