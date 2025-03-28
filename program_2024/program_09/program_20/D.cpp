#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1), ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        for (int j = 1; j <= i; j++)
        {
            int sum = pre[i] - pre[j - 1];
            if (sqrtf(sum) - sqrt(sum) == 0)
            {
                for (int k = j; k <= i; k++)
                    ans[k]++;
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}