#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j)
    {
        if (l[i] == l[j])
            return r[i] > r[j];
        return l[i] < l[j];
    });
    vector<int> R(n, -1);
    set<int> s;
    for (int j = 0; j < n; j++)
    {
        int i = p[j];
        auto it = s.lower_bound(r[i]);
        if (it != s.end())
            R[i] = *it;
        s.insert(r[i]);
        if (j + 1 < n && l[i] == l[p[j + 1]] && r[i] == r[p[j + 1]])
            R[i] = r[i];
    }

    sort(p.begin(), p.end(), [&](int i, int j)
    {
        if (r[i] == r[j])
            return l[i] < l[j];
        return r[i] > r[j];
    });
    vector<int> L(n, -1);
    s.clear();
    for (int j = 0; j < n; j++)
    {
        int i = p[j];
        auto it = s.upper_bound(l[i]);
        if (it != s.begin())
            L[i] = *prev(it);
        s.insert(l[i]);
        if (j + 1 < n && l[i] == l[p[j + 1]] && r[i] == r[p[j + 1]])
            L[i] = l[i];
    }
    // vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (L[i] == -1)
            cout << "0\n";
        else 
            cout << R[i] - L[i] - (r[i] - l[i]) << "\n";
    }
    // for (int i = 0; i < n; i++)
        // cout << ans[i] << "\n";
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