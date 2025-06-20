#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    const int N = 2e5 + 5;
    vector<int> a(N);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    int suf = 0, ans = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        suf += a[i];
        if (suf >= m)
            ans = max(ans, min(m, a[i]));
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