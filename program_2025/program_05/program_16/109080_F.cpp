#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (r - l > 70)
        {
            cout << "0\n";
            continue;
        }

        int ans = a[l];
        for (int i = l + 1; i <= r; i++)
            ans = ans + a[i] - (ans ^ a[i]);

        cout << ans << "\n";
    }
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