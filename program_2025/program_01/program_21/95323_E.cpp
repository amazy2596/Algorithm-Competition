#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    auto calc = [&](int x, int l, int r)
    {
        int res = 0;
        for (int i = l; i <= r; i++)
            res += abs(a[i] - x);

        return res;
    };

    int tar1 = a[(n / 2) / 2 + 1], tar2 = a[(n / 2) + (n / 2) / 2 + 1];
    int ans = 1e18l;
    for (int i = tar1 - 5; i <= tar1 + 5; i++)
    {
        for (int j = tar2 - 5; j <= tar2 + 5; j++)
        {
            if (i == j)
                continue;
            ans = min(ans, calc(i, 1, n / 2) + calc(j, n / 2 + 1, n));
        }
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