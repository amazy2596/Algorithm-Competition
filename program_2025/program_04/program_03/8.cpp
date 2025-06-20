#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<double> mid(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        mid[i] = (r - l) * 1.0 / 2 + l;
    }

    sort(mid.begin(), mid.end());

    while (m--)
    {
        int L, R;
        cin >> L >> R;

        auto l = lower_bound(mid.begin(), mid.end(), L) - mid.begin();
        auto r = upper_bound(mid.begin(), mid.end(), R) - mid.begin() - 1;
        cout << r - l + 1 << "\n";
    }
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