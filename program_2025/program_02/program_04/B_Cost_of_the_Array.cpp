#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k == n)
    {
        vector<int> ans = {0};
        for (int i = 1; i <= n; i += 2)
            ans.push_back(a[i]);
        ans.push_back(0);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] != i)
            {
                cout << i << "\n";
                return;
            }
        }
    }
    int cnt = 2;
    int ans = 1e9;
    for (int i = 1; i < n - k + cnt; i++)
    {
        for (int j = 1; j < n - k + cnt; j++)
        {
            if (a[i + j - 1] != j)
            {
                ans = min(ans, j);
                break;
            }
        }
    }

    cout << ans << "\n";
    // for (int i = n - k + cnt; i < n; i++)
    // {
        // if (cnt % 2 == 1)
            // ans.push_back(a[i]);
        // cnt++;
    // }
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