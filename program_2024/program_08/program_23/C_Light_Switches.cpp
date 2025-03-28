#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int mx = a[n - 1];
    vector<int> c(2 * k);
    for (int i = 0; i < n; i++)
    {
        int cnt = (mx - a[i]) / (2 * k);
        int l = a[i] + cnt * k * 2;
        int r = l + k;
        if (r > mx)
            c[0]++, c[r - mx]--;
        l += 2 * k, r += 2 * k;
        if (r - mx <= 2 * k - 1)
            c[l - mx]++, c[r - mx]--;
    }
    for (int i = 1; i <= c.size(); i++)
        c[i] = c[i - 1] + c[i];
    for (int i = 0; i <= c.size(); i++)
    {
        if (c[i] == n)
        {
            cout << i + mx << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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