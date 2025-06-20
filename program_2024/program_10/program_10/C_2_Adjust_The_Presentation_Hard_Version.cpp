#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    vector<set<int>> s(n);
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i], b[i]--;
        s[b[i]].insert(i);
    }

    for (int i = 0; i < n; i++)
        s[i].insert(m);

    vector<int> val(n);
    for (int i = 0; i < n; i++)
        val[i] = *s[a[i]].begin();

    int fail = 0;
    for (int i = 1; i < n; i++)
        fail += val[i - 1] > val[i];
    
    auto update = [&](int i)
    {
        if (i > 0)
            fail -= val[i - 1] > val[i];
        if (i < n - 1)
            fail -= val[i] > val[i + 1];
        val[i] = *s[a[i]].begin();
        if (i > 0)
            fail += val[i - 1] > val[i];
        if (i < n - 1)
            fail += val[i] > val[i + 1];
    };

    cout << (fail == 0 ? "YA\n" : "TIDAK\n");
    while (q--)
    {
        int i, t;
        cin >> i >> t;
        i--, t--;
        int old = b[i];
        s[b[i]].erase(i);
        b[i] = t;
        s[b[i]].insert(i);
        update(pos[old]);
        update(pos[b[i]]);
        cout << (fail == 0 ? "YA\n" : "TIDAK\n");
    }
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