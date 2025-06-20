#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << -1 << "\n";
        return;
    }
    int ans = 1e9;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] == a[i + 1] && a[i - 1] != a[i])
        {
            int l = i - 1, r = i + 1;
            while (l >= 0 && a[l] == a[i - 1])
                l--;
            while (r < n && a[r] == a[i + 1])
                r++;
            ans = min({ans, i - l - 1, r - i - 1});
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
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