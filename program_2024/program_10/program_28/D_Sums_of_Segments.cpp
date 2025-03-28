#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), ppre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        ppre[i] = ppre[i - 1] + pre[i];
    }
    auto get = [&](int idx, int l, int r) -> int
    {
        if (l > r)
            return 0;
        return ppre[r] - ppre[l - 1] - (r - l + 1) * pre[idx - 1];
    };
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + get(i, i, n);
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++)
        vec[i] = vec[i - 1] + (n - i + 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int count_l = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        int count_r = lower_bound(vec.begin(), vec.end(), r) - vec.begin();
        int ans = 0;
        if (count_l == count_r)
            ans += get(count_l, count_l + (l - vec[count_l - 1] - 1), count_r + (r - vec[count_r - 1] - 1));
        else
        {
            ans += get(count_l, count_l + (l - vec[count_l - 1] - 1), n);
            ans += sum[count_r] - sum[count_l];
            ans -= get(count_r, count_r + (r - vec[count_r - 1]), n);
        }
        cout << ans << "\n";
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