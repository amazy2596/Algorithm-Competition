#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int x = 1; x <= 10; x++)
    {
        vector<int> b(n), pre(n);
        int sum = n;
        for (int i = 0; i < n; i++)
        {
            b[i] = (a[i] <= x ? -1 : 1);
            pre[i] = sum;
            sum += b[i];
        }

        sum = n;
        int j = 0;
        vector<int> cnt(2 * n + 1);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                while (j <= i)
                {
                    cnt[pre[j]]++;
                    j++;
                }
            }
            sum += b[i];
            ans += cnt[sum];
        }
    }

    ans = (n * (n + 1)) / 2 - ans;
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