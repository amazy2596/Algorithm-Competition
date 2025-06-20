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
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt >= a[i])
        {
            ans++;
            continue;
        }
        if ((n - i) * (a[i] - cnt) < k)
        {
            ans += (n - i) * (a[i] - cnt) + 1;
            k -= (n - i) * (a[i] - cnt);
            cnt = a[i];
        }
        else
        {
            ans += k;
            break;
        }
    }
    cout << ans << "\n";
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