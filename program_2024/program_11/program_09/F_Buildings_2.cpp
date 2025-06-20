#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<pair<int, int>>> query(n + 1);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        query[l].emplace_back(r, i);
    }
    vector<int> ans(q);
    deque<int> d;
    for (int l = n; l >= 1; l--)
    {
        for (auto [r, i] : query[l])
        {
            auto it = upper_bound(d.begin(), d.end(), r);
            ans[i] = d.end() - it;
        }
        while (!d.empty() && a[d.front()] < a[l])
            d.pop_front();
        d.push_front(l);
    }
    for (auto a : ans)
        cout << a << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}