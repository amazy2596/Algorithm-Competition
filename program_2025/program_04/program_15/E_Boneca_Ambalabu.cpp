#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(32);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int k = 0; k <= 31; k++)
            cnt[k] += (a[i] >> k & 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int k = 0; k <= 31; k++)
        {
            int bit = (a[i] >> k & 1);
            int other = cnt[k] - bit;

            if (bit == 0)
                temp += (1ll << k) * other;
            else 
                temp += (1ll << k) * (n - other - 1);
        }

        ans = max(ans, temp);
    }

    cout << ans << "\n";
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