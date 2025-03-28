#include <bits/stdc++.h>
#define int long long
using namespace std;
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    auto get = [&](int x, int check)
    {
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= x)
            {
                int t = (a[i] - x) / b[i] + 1;
                cnt += t;
                sum += a[i] * t - (t * (t - 1) / 2) * b[i];
                if (check == 1)
                    a[i] = max(0ll, a[i] - t * b[i]);
            }
        }
        return pair<int, int> {cnt, sum};
    };
    int l = 0, r = 1e10;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (get(mid, 0).first <= k)
            r = mid;
        else 
            l = mid + 1;
    }
    auto [cnt, sum] = get(l, 1);
    if (l > 0)
        sum += (k - cnt) * (l - 1);
    cout << sum << "\n";
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}