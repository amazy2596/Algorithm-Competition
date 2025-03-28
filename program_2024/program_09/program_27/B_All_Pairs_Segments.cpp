#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> ans;
    ans[n - 1]++;
    auto calc = [&](int l, int r)
    {
        return (l + r) * (r - l + 1) / 2;
    };
    for (int i = 0; i < n - 1; i++)
    {
        int l = a[i], r = a[i + 1];
        int num1 = r - l - 1;
        int k1 = (n - i - 1) * (i + 1);
        int k2 = (n - i - 1) + (n - i) * i;
        ans[k1] += num1;
        ans[k2]++;
    }
    while (q--)
    {
        int k;
        cin >> k;
        cout << ans[k] << " ";
    }
    cout << '\n';
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