#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    vector<int> sufA(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 0)
            sufA[i] = sufA[i + 1] + a[i];
    }

    int ans = sufA[0], cur = 0;
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        cur += a[i] + b[i];
        ans = max(ans, cur + sufA[i + 1]);
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