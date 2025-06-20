#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];
    int q;
    cin >> q;
    while (q--)
    {
        int l, u;
        cin >> l >> u;
        int r = upper_bound(pre.begin() + l, pre.end(), pre[l - 1] + u) - pre.begin();
        u -= pre[r - 1] - pre[l - 1];
        if (a[r] % 2 == 0)
            r -= (u < a[r] / 2);
        else
            r -= (u <= a[r] / 2);
        cout << max(l, min(r, n)) << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}