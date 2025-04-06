#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];

    int cnt = x / sum;
    x %= sum;

    int i = 0, id = n;
    while (x > 0)
    {
        i++;
        x -= a[id];
        id--;
    }

    cout << max(0ll, n * k - cnt * n - i + 1) << "\n";
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