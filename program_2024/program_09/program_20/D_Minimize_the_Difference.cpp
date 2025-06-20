#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    auto average = [&](int l, int r) -> int
    {
        return (pre[r] - pre[l - 1] + r - l) / (r - l + 1);
    };
    stack<pair<int, int>> stk;
    int l = n, r = n;
    while (l >= 1)
    {
        while (!stk.empty())
        {
            auto [tl, tr] = stk.top();
            if (average(l, r) >= average(tl, tr))
            {
                stk.pop();
                r = tr;
            }
            else 
                break;
        }
        stk.push({l, r});
        r = l - 1;
        l--;
    }
    int mx = 0, mn = INT64_MAX;
    while (!stk.empty())
    {
        auto [l, r] = stk.top();
        stk.pop();
        mx = max(mx, average(l, r));
        mn = min(mn, (pre[r] - pre[l - 1]) / (r - l + 1));
    }
    cout << mx - mn << "\n";
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