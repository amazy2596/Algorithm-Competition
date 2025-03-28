#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx += abs((n - i + 1) - i);
    if (k % 2 == 1 || k > mx)
    {
        cout << "No\n";
        return;
    }
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    int l = 1, r = n;
    while (l < r && k > 0)
    {
        if (k >= 2 * (r - l))
        {
            swap(ans[l], ans[r]);
            k -= 2 * (r - l);
            l++, r--;
        }
        else
        {
            swap(ans[l], ans[l + k / 2]);
            k = 0;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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