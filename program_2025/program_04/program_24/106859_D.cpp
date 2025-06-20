#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int sum = 0;
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        pre[i] = max(pre[i - 1], sum);
    }
    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        suf[i] = max(suf[i + 1], sum);
    }

    // 1 2 3 4 5
    // 0 1 2 3 4

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (k < i)
            break;
        m++;
        k = k - i + 1;
    }

    int ans = max(pre[m], suf[n - m + 1]);
    for (int i = 1; i < m; i++)
    {
        ans = max(ans, pre[i] + suf[n - m + i + 1]);
    }
    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}