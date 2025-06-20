#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];

    int l, r;
    cin >> l >> r;

    int beg = l / n + 1;
    int ed = r / n + 1;

    int ans = 0;

    if (beg == ed)
    {
        for (int i = l; i <= r; i++)
            ans += beg * a[(i - 1) % n + 1];

        cout << ans << "\n";
        return;
    }

    for (int i = l; i <= beg * n; i++)
        ans += beg * a[(i - 1) % n + 1];

    for (int i = (ed - 1) * n + 1; i <= r; i++)
        ans += ed * a[(i - 1) % n + 1];

    for (int i = beg + 1; i < ed; i++)
        ans += i * pre[n];

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